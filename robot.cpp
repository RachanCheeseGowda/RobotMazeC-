#include "Robot.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <Game.h>
#include "math.h"
#include <QThread>

extern Game *level;


Robot::Robot(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    moveSound = new QMediaPlayer();
    moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/robotBlip.wav"));

    timer = new QTimer(this);
    blockTimer = new QTimer(this);
    moveTimer = new QTimer(this);
    delay = new QTimer(this);
    dance = new QTimer(this);
    // set graphic
    setImage();
}

void Robot::setImage()
{
    if(skin==0){
        setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01gold.png"));
    }
    if(skin==1){
        setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01.png"));
    }
}

Robot::~Robot()
{
    delete timer;
    delete blockTimer;
    delete moveTimer;
    delete dance;
    delete delay;
    delete moveSound;
}



void Robot::startSequence(QVector<QPointer<AlgorithmBlock> > sequence, Tile *maze[14][14],QVector<QPointer<Obstacle>> obstacle)
{
    qDebug()<<"start";
    for(AlgorithmBlock* b:sequence){
        qDebug()<<b->getDirection()<<b->getSteps()<<b->getY();
    }

    timer->start(10);
    blockTimer->start(400);
    moveTimer->start(100);
    connect(timer, &QTimer::timeout, this, std::bind(&Robot::move,this,sequence,maze,obstacle));
    connect(blockTimer, &QTimer::timeout, this, std::bind(&Robot::indicateBlock,this,sequence));
    connect(moveTimer,SIGNAL(timeout()),this,SLOT(animateMove()));

}

void Robot::startSequence1(QVector<QPointer<AlgorithmBlockPlayer1>> sequence, Tile *maze[14][14],QVector<QPointer<Obstacle>> obstacle)
{
    timer->start(10);
    moveTimer->start(100);
    connect(timer, &QTimer::timeout, this, std::bind(&Robot::move1,this,sequence,maze,obstacle));
    connect(moveTimer,SIGNAL(timeout()),this,SLOT(animateMove()));

}

void Robot::startSequence2(QVector<QPointer<AlgorithmBlockPlayer2> > sequence, Tile *maze[14][14], QVector<QPointer<Obstacle> > obstacle)
{

    timer->start(10);
    moveTimer->start(100);
    connect(timer, &QTimer::timeout, this, std::bind(&Robot::move2,this,sequence,maze,obstacle));
    connect(moveTimer,SIGNAL(timeout()),this,SLOT(animateMove()));
}

void Robot::stop()
{
    qDebug()<<"STOPPING";
    disconnect(delay,0,0,0);
    disconnect(blockTimer,0,0,0);
    disconnect(moveTimer,0,0,0);
    disconnect(timer,0,0,0);
    disconnect(dance,0,0,0);
}



void Robot::startDance()
{
    connect(dance,SIGNAL(timeout()),this,SLOT(celebrate()));
    dance->start(90);
}



void Robot::move(QVector<QPointer<AlgorithmBlock>> sequence,Tile *maze[14][14],QVector<QPointer<Obstacle>> obstacle)
{
    int winI;
    int winJ;
    timer->setInterval(10);
    moveSound->play();
    stepY=0;
    stepX=0;
    //sequence[index]->setSelectedImage();
    distance=sequence[index]->getSteps()*level->tileSize;
    if(sequence[index]->getDirection()=="NORTH"){
        stepX=0;
        stepY=-1;
    }
    if(sequence[index]->getDirection()=="SOUTH"){
        stepX=0;
        stepY=1;
    }
    if(sequence[index]->getDirection()=="EAST"){
        stepX=1;
        stepY=0;
    }
    if(sequence[index]->getDirection()=="WEST"){
        stepX=-1;
        stepY=0;
    }
    if(sequence[index]->getBlockType()=="JUMP"){
        timer->setInterval(1);
        isJump=1;
    }
    if(sequence[index]->getBlockType()=="JUMP"&&count>distance/2){
        isJump=0;
    }
    if(sequence[index]->getBlockType()=="BRIDGE"&&count<level->tileSize){
        qDebug()<<count;
        //DEPLOY BRIDGE
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
            }
        }
        timer->setInterval(15);
        count++;
        isBridge=1;
        return;
    }
    //validate
    bool checkBridge=1;
    if(isBridge==1){
        checkBridge=0;
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
            }
        }
    }

    if(isBridge==1&&checkBridge==0){
        qDebug()<<"NO BRIDGE";
        delay->start(3000);
        moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
        moveSound->play();
        connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
        disconnect(timer,0,0,0);
        disconnect(moveTimer,0,0,0);
        return;
    }

    if(count%level->tileSize==0){
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                if(maze[i][j]->getTileState()==2){
                    winI=i;
                    winJ=j;
                }
                //BUTTON
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==4 &&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==5){
                                for(QPointer<Obstacle> b:obstacle){
                                    b->toggleButton();
                                    if(b->getX()==maze[k][l]->getX()&&b->getY()==maze[k][l]->getY()){
                                        maze[k][l]->setTileState(1);
                                        b->toggleButton();
                                        b->stopFire();
                                        qDebug()<<"EXTINGUISHED";
                                    }
                                }
                            }
                        }
                    }
                }
                //FIRE
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==5 &&isJump==0){
                    qDebug()<<"BURNT TO A CRISP";
                    delay->start(3000);
                    moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                    moveSound->play();
                    connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                    disconnect(timer,0,0,0);
                    disconnect(moveTimer,0,0,0);
                    return;
                }
                //Portal 1
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==6 &&enteredPortal==0 &&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-6){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-6 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==6){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                //Portal 2
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==7 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-7){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-7 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==7){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                //Portal 3
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==8 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-8){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-8 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==8){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                //Portal 4
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==9 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-9){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-9 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==9){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(isJump==0){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==0){
                        delay->start(3000);
                        moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                        moveSound->play();
                        connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                        disconnect(timer,0,0,0);
                        disconnect(moveTimer,0,0,0);
                        return;
                    }
                    if(bridgeMove==0){
                        if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                            delay->start(3000);
                            moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                            moveSound->play();
                            connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                            disconnect(timer,0,0,0);
                            disconnect(moveTimer,0,0,0);
                            return;
                        }
                        if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                            delay->start(3000);
                            moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                            moveSound->play();
                            connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                            disconnect(timer,0,0,0);
                            disconnect(moveTimer,0,0,0);
                            return;
                        }
                    }

                }
            }
        }
    }
    //end of instruction
    if(count==distance){
        if(deployingBridge){
            for(QPointer<Obstacle> b:obstacle){
                b->animateBridge(0);
            }
            deployingBridge=0;
        }
        sequence[index]->setSelectedImage();
        moveFrame=1;
        timer->setInterval(400);
        stepX=0;
        stepY=0;
        count =-1;
        bridgeMove=0;
        //Check if the end of this instruction lands on the winning block
        if(this->pos().x()-x_offset==maze[winI][winJ]->getX()&&this->pos().y()==maze[winI][winJ]->getY()){
            delay->start(3000);
            moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/ta da.wav"));
            moveSound->play();
            connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,1));
            disconnect(timer,0,0,0);
            disconnect(blockTimer,0,0,0);
            disconnect(moveTimer,0,0,0);
            return;
        }
        if(index<sequence.size()){
            index++;
            if(index == sequence.size()){
                index--;
                if (moveSound->state() == QMediaPlayer::PlayingState){
                    moveSound->setPosition(0);
                }
                else if (moveSound->state() == QMediaPlayer::StoppedState){
                    moveSound->play();
                }
                qDebug()<<"2bad";
                delay->start(3000);
                connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                disconnect(timer,0,0,0);
                disconnect(blockTimer,0,0,0);
                disconnect(moveTimer,0,0,0);
                sequence[index]->setSelectedImage();
                return;
            }
        }
    }
    setPos(x()+stepX, y()+stepY);
    if(enteredPortal==1){
        enteredPortal=2;
        timer->setInterval(1000);
    }
    else if(enteredPortal==2){
        enteredPortal=0;
    }
    count+=1;
}


void Robot::move1(QVector<QPointer<AlgorithmBlockPlayer1>> sequence,Tile *maze[14][14],QVector<QPointer<Obstacle>> obstacle)
{
    int winI;
    int winJ;
    timer->setInterval(10);
    moveSound->play();
    stepY=0;
    stepX=0;
    //sequence[index]->setSelectedImage();
    distance=sequence[index]->getSteps()*level->tileSize;
    if(sequence[index]->getDirection()=="NORTH"){
        stepX=0;
        stepY=-1;
    }
    if(sequence[index]->getDirection()=="SOUTH"){
        stepX=0;
        stepY=1;
    }
    if(sequence[index]->getDirection()=="EAST"){
        stepX=1;
        stepY=0;
    }
    if(sequence[index]->getDirection()=="WEST"){
        stepX=-1;
        stepY=0;
    }
    if(sequence[index]->getBlockType()=="JUMP"){
        timer->setInterval(1);
        isJump=1;
    }
    if(sequence[index]->getBlockType()=="JUMP"&&count>distance/2){
        isJump=0;
    }
    if(sequence[index]->getBlockType()=="BRIDGE"&&count<level->tileSize){
        qDebug()<<count;
        //DEPLOY BRIDGE
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
            }
        }
        timer->setInterval(15);
        count++;
        isBridge=1;
        return;
    }
    //validate
    bool checkBridge=1;
    if(isBridge==1){
        checkBridge=0;
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
            }
        }
    }

    if(isBridge==1&&checkBridge==0){
        qDebug()<<"NO BRIDGE";
        delay->start(3000);
        moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));

        level->winner=2;
        moveSound->play();
        connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
        disconnect(timer,0,0,0);
        disconnect(moveTimer,0,0,0);
        return;
    }

    if(count%level->tileSize==0){
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                if(maze[i][j]->getTileState()==2){
                    winI=i;
                    winJ=j;
                }
                //BUTTON
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==4 &&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==5){
                                for(QPointer<Obstacle> b:obstacle){
                                    b->toggleButton();
                                    if(b->getX()==maze[k][l]->getX()&&b->getY()==maze[k][l]->getY()){
                                        maze[k][l]->setTileState(1);
                                        b->toggleButton();
                                        b->stopFire();
                                        qDebug()<<"EXTINGUISHED";
                                    }
                                }
                            }
                        }
                    }
                }
                //FIRE
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==5 &&isJump==0){
                    qDebug()<<"BURNT TO A CRISP";
                    delay->start(3000);
                    moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));

                    level->winner=2;
                    moveSound->play();
                    connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                    disconnect(timer,0,0,0);
                    disconnect(moveTimer,0,0,0);
                    return;
                }
                //Portal 1
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==6 &&enteredPortal==0 &&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-6){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-6 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==6){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                //Portal 2
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==7 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-7){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-7 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==7){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                //Portal 3
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==8 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-8){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-8 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==8){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                //Portal 4
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==9 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-9){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-9 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==9){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(isJump==0){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==0){
                        delay->start(3000);
                        moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                        level->winner=2;
                        moveSound->play();
                        connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                        disconnect(timer,0,0,0);
                        disconnect(moveTimer,0,0,0);
                        return;
                    }
                    if(bridgeMove==0){
                        if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                            delay->start(3000);
                            moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                            level->winner=2;
                            moveSound->play();
                            connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                            disconnect(timer,0,0,0);
                            disconnect(moveTimer,0,0,0);
                            return;
                        }
                        if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                            delay->start(3000);
                            moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                            moveSound->play();
                            connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                            disconnect(timer,0,0,0);
                            disconnect(moveTimer,0,0,0);
                            return;
                        }
                    }

                }
            }
        }
    }
    //end of instruction
    if(count==distance){
        if(deployingBridge){
            for(QPointer<Obstacle> b:obstacle){
                b->animateBridge(0);
            }
            deployingBridge=0;
        }
        sequence[index]->setSelectedImage();
        moveFrame=1;
        timer->setInterval(400);
        stepX=0;
        stepY=0;
        count =-1;
        bridgeMove=0;
        //Check if the end of this instruction lands on the winning block
        if(this->pos().x()-x_offset==maze[winI][winJ]->getX()&&this->pos().y()==maze[winI][winJ]->getY()){
            delay->start(3000);
            moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/ta da.wav"));
            moveSound->play();
            if(level->winner!=2){
                level->winner=1;
            }
            connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,1));
            disconnect(timer,0,0,0);
            disconnect(blockTimer,0,0,0);
            disconnect(moveTimer,0,0,0);
            return;
        }
        if(index<sequence.size()){
            index++;
            if(index == sequence.size()){
                index--;
                if (moveSound->state() == QMediaPlayer::PlayingState){
                    moveSound->setPosition(0);
                }
                else if (moveSound->state() == QMediaPlayer::StoppedState){
                    moveSound->play();
                }
                qDebug()<<"2bad";
                delay->start(3000);
                connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                disconnect(timer,0,0,0);
                disconnect(blockTimer,0,0,0);
                disconnect(moveTimer,0,0,0);
                sequence[index]->setSelectedImage();
                return;
            }
        }
    }
    setPos(x()+stepX, y()+stepY);
    if(enteredPortal==1){
        enteredPortal=2;
        timer->setInterval(1000);
    }
    else if(enteredPortal==2){
        enteredPortal=0;
    }
    count+=1;
}

void Robot::move2(QVector<QPointer<AlgorithmBlockPlayer2>> sequence,Tile *maze[14][14],QVector<QPointer<Obstacle>> obstacle)
{
    int winI;
    int winJ;
    timer->setInterval(10);
    moveSound->play();
    stepY=0;
    stepX=0;
    //sequence[index]->setSelectedImage();
    distance=sequence[index]->getSteps()*level->tileSize;
    if(sequence[index]->getDirection()=="NORTH"){
        stepX=0;
        stepY=-1;
    }
    if(sequence[index]->getDirection()=="SOUTH"){
        stepX=0;
        stepY=1;
    }
    if(sequence[index]->getDirection()=="EAST"){
        stepX=1;
        stepY=0;
    }
    if(sequence[index]->getDirection()=="WEST"){
        stepX=-1;
        stepY=0;
    }
    if(sequence[index]->getBlockType()=="JUMP"){
        timer->setInterval(1);
        isJump=1;
    }
    if(sequence[index]->getBlockType()=="JUMP"&&count>distance/2){
        isJump=0;
    }
    if(sequence[index]->getBlockType()=="BRIDGE"&&count<level->tileSize){
        qDebug()<<count;
        //DEPLOY BRIDGE
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-level->tileSize==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-level->tileSize==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        for(QPointer<Obstacle> b:obstacle){
                            if(b->getX()==maze[i][j]->getX()&&b->getY()==maze[i][j]->getY()&&b->getObstacle_type()==-3){
                                deployingBridge=1;
                                b->animateBridge(count);
                            }
                        }
                    }
                }
            }
        }
        timer->setInterval(15);
        count++;
        isBridge=1;
        return;
    }
    //validate
    bool checkBridge=1;
    if(isBridge==1){
        checkBridge=0;
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="SOUTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()+count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="NORTH"){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()-count==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="EAST"){
                    if(this->pos().x()-x_offset+count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
                if(sequence[index]->getDirection()=="WEST"){
                    if(this->pos().x()-x_offset-count==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                        qDebug()<<i<<j;
                        isBridge=0;
                        bridgeMove=1;
                        checkBridge=1;
                    }
                }
            }
        }
    }

    if(isBridge==1&&checkBridge==0){
        qDebug()<<"NO BRIDGE";
        delay->start(3000);
        moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
        level->winner=1;
        moveSound->play();
        connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
        disconnect(timer,0,0,0);
        disconnect(moveTimer,0,0,0);
        return;
    }

    if(count%level->tileSize==0){
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                if(maze[i][j]->getTileState()==2){
                    winI=i;
                    winJ=j;
                }
                //BUTTON
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==4 &&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==5){
                                for(QPointer<Obstacle> b:obstacle){
                                    b->toggleButton();
                                    if(b->getX()==maze[k][l]->getX()&&b->getY()==maze[k][l]->getY()){
                                        maze[k][l]->setTileState(1);
                                        b->toggleButton();
                                        b->stopFire();
                                        qDebug()<<"EXTINGUISHED";
                                    }
                                }
                            }
                        }
                    }
                }
                //FIRE
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==5 &&isJump==0){
                    qDebug()<<"BURNT TO A CRISP";
                    delay->start(3000);
                    moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                    level->winner=1;
                    moveSound->play();
                    connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                    disconnect(timer,0,0,0);
                    disconnect(moveTimer,0,0,0);
                    return;
                }
                //Portal 1
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==6 &&enteredPortal==0 &&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-6){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-6 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==6){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                //Portal 2
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==7 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-7){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-7 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==7){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                //Portal 3
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==8 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-8){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-8 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==8){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                //Portal 4
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==9 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==-9){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-9 &&enteredPortal==0&&isJump==0){
                    for(int k=0;k<14;k++){
                        for(int l=0;l<14;l++){
                            if(maze[k][l]->getTileState()==9){
                                this->setX(maze[k][l]->getX()+x_offset);
                                this->setY(maze[k][l]->getY());
                                enteredPortal=1;
                            }
                        }
                    }
                }
                if(isJump==0){
                    if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==0){
                        delay->start(3000);
                        moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                        moveSound->play();
                        level->winner=1;
                        connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                        disconnect(timer,0,0,0);
                        disconnect(moveTimer,0,0,0);
                        return;
                    }
                    if(bridgeMove==0){
                        if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==-3){
                            delay->start(3000);
                            moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                            level->winner=1;
                            moveSound->play();
                            connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                            disconnect(timer,0,0,0);
                            disconnect(moveTimer,0,0,0);
                            return;
                        }
                        if(this->pos().x()-x_offset==int(maze[i][j]->getX())&&this->pos().y()==int(maze[i][j]->getY())&&maze[i][j]->getTileState()==3){
                            delay->start(3000);
                            moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/fail.wav"));
                            level->winner=1;
                            moveSound->play();
                            connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                            disconnect(timer,0,0,0);
                            disconnect(moveTimer,0,0,0);
                            return;
                        }
                    }

                }
            }
        }
    }
    //end of instruction
    if(count==distance){
        if(deployingBridge){
            for(QPointer<Obstacle> b:obstacle){
                b->animateBridge(0);
            }
            deployingBridge=0;
        }
        sequence[index]->setSelectedImage();
        moveFrame=1;
        timer->setInterval(400);
        stepX=0;
        stepY=0;
        count =-1;
        bridgeMove=0;
        //Check if the end of this instruction lands on the winning block
        if(this->pos().x()-x_offset==maze[winI][winJ]->getX()&&this->pos().y()==maze[winI][winJ]->getY()){
            delay->start(3000);
            moveSound->setMedia(QUrl("qrc:/Sounds/Sounds/Robot/ta da.wav"));
            moveSound->play();
            if(level->winner!=1){
                level->winner=2;
            }
            connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,1));
            disconnect(timer,0,0,0);
            disconnect(blockTimer,0,0,0);
            disconnect(moveTimer,0,0,0);
            return;
        }
        if(index<sequence.size()){
            index++;
            if(index == sequence.size()){
                index--;
                if (moveSound->state() == QMediaPlayer::PlayingState){
                    moveSound->setPosition(0);
                }
                else if (moveSound->state() == QMediaPlayer::StoppedState){
                    moveSound->play();
                }
                qDebug()<<"2bad";
                delay->start(3000);
                connect(delay, &QTimer::timeout, this, std::bind(&Robot::finish,this,0));
                disconnect(timer,0,0,0);
                disconnect(blockTimer,0,0,0);
                disconnect(moveTimer,0,0,0);
                sequence[index]->setSelectedImage();
                return;
            }
        }
    }
    setPos(x()+stepX, y()+stepY);
    if(enteredPortal==1){
        enteredPortal=2;
        timer->setInterval(1000);
    }
    else if(enteredPortal==2){
        enteredPortal=0;
    }
    count+=1;
}

void Robot::indicateBlock(QVector<QPointer<AlgorithmBlock>> sequence)
{
    if(on){
        sequence[index]->setSelectedImage();
        on=0;
    }
    else{
        sequence[index]->setImage();
        on=1;
    }

}

void Robot::animateMove()
{
    if(skin==0){
        if(isBridge==0){
            if(stepX==0 && stepY==0){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01gold.png"));
                 moveFrame=1;
            }
            //SOUTH
            else if(stepX==0 && stepY==1 && moveFrame==1){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01gold.png"));
                 moveFrame=2;
            }
            else if(stepX==0 && stepY==1 && moveFrame==2){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-02gold.png"));
                 moveFrame=3;
            }
            else if(stepX==0 && stepY==1 && moveFrame==3){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01gold.png"));
                 moveFrame=4;
            }
            else if(stepX==0 && stepY==1 && moveFrame==4){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-12gold.png"));
                 moveFrame=1;
            }
            //EAST
            else if(stepX==1 && stepY==0 && moveFrame==1){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-07gold.png"));
                 moveFrame=2;
            }
            else if(stepX==1 && stepY==0 && moveFrame==2){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-05gold.png"));
                 moveFrame=3;
            }
            else if(stepX==1 && stepY==0 && moveFrame==3){
                 moveFrame=4;
            }
            else if(stepX==1 && stepY==0 && moveFrame==4){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-07gold.png"));
                 moveFrame=5;
            }
            else if(stepX==1 && stepY==0 && moveFrame==5){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-06gold.png"));
                 moveFrame=6;
            }
            else if(stepX==1 && stepY==0 && moveFrame==6){
                 moveFrame=7;
            }
            else if(stepX==1 && stepY==0 && moveFrame==7){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-07gold.png"));
                 moveFrame=1;
            }
            //NORTH
            else if(stepX==0 && stepY==-1 && moveFrame==1){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-03gold.png"));
                 moveFrame=2;
            }
            else if(stepX==0 && stepY==-1 && moveFrame==2){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-04gold.png"));
                 moveFrame=3;
            }
            else if(stepX==0 && stepY==-1 && moveFrame==3){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-03gold.png"));
                 moveFrame=4;
            }
            else if(stepX==0 && stepY==-1 && moveFrame==4){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-11gold.png"));
                 moveFrame=5;
            }
            else if(stepX==0 && stepY==-1 && moveFrame==5){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-03gold.png"));
                 moveFrame=1;
            }
            //WEST
            else if(stepX==-1 && stepY==0 && moveFrame==1){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-10gold.png"));
                 moveFrame=2;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==2){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-09gold.png"));
                 moveFrame=3;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==3){
                 moveFrame=4;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==4){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-10gold.png"));
                 moveFrame=5;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==5){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-08gold.png"));
                 moveFrame=6;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==6){
                 moveFrame=7;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==7){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-10gold.png"));
                 moveFrame=1;
            }
        }
    }
    else{
        if(isBridge==0){
            if(stepX==0 && stepY==0){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01.png"));
                 moveFrame=1;
            }
            //SOUTH
            else if(stepX==0 && stepY==1 && moveFrame==1){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01.png"));
                 moveFrame=2;
            }
            else if(stepX==0 && stepY==1 && moveFrame==2){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-02.png"));
                 moveFrame=3;
            }
            else if(stepX==0 && stepY==1 && moveFrame==3){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01.png"));
                 moveFrame=4;
            }
            else if(stepX==0 && stepY==1 && moveFrame==4){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-12.png"));
                 moveFrame=1;
            }
            //EAST
            else if(stepX==1 && stepY==0 && moveFrame==1){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-07.png"));
                 moveFrame=2;
            }
            else if(stepX==1 && stepY==0 && moveFrame==2){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-05.png"));
                 moveFrame=3;
            }
            else if(stepX==1 && stepY==0 && moveFrame==3){
                 moveFrame=4;
            }
            else if(stepX==1 && stepY==0 && moveFrame==4){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-07.png"));
                 moveFrame=5;
            }
            else if(stepX==1 && stepY==0 && moveFrame==5){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-06.png"));
                 moveFrame=6;
            }
            else if(stepX==1 && stepY==0 && moveFrame==6){
                 moveFrame=7;
            }
            else if(stepX==1 && stepY==0 && moveFrame==7){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-07.png"));
                 moveFrame=1;
            }
            //NORTH
            else if(stepX==0 && stepY==-1 && moveFrame==1){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-03.png"));
                 moveFrame=2;
            }
            else if(stepX==0 && stepY==-1 && moveFrame==2){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-04.png"));
                 moveFrame=3;
            }
            else if(stepX==0 && stepY==-1 && moveFrame==3){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-03.png"));
                 moveFrame=4;
            }
            else if(stepX==0 && stepY==-1 && moveFrame==4){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-11.png"));
                 moveFrame=5;
            }
            else if(stepX==0 && stepY==-1 && moveFrame==5){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-03.png"));
                 moveFrame=1;
            }
            //WEST
            else if(stepX==-1 && stepY==0 && moveFrame==1){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-10.png"));
                 moveFrame=2;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==2){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-09.png"));
                 moveFrame=3;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==3){
                 moveFrame=4;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==4){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-10.png"));
                 moveFrame=5;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==5){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-08.png"));
                 moveFrame=6;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==6){
                 moveFrame=7;
            }
            else if(stepX==-1 && stepY==0 && moveFrame==7){
                 setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-10.png"));
                 moveFrame=1;
            }
        }
    }
}

void Robot::celebrate()
{
    //SOUTH
    if(danceFrame==0){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01gold.png"));
         danceFrame=1;
    }
    else if(danceFrame==1){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-02gold.png"));
         danceFrame=2;
    }
    else if(danceFrame==2){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01gold.png"));
         danceFrame=3;
    }
    else if(danceFrame==3){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-12gold.png"));
         danceFrame=4;
    }
    //EAST
    else if(danceFrame==4){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-07gold.png"));
         danceFrame=5;
    }
    else if(danceFrame==5){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-05gold.png"));
         danceFrame=7;
    }
    else if(danceFrame==6){
         danceFrame=7;
    }
    else if(danceFrame==7){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-07gold.png"));
         danceFrame=8;
    }
    else if(danceFrame==8){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-06gold.png"));
         danceFrame=9;
    }
    else if(danceFrame==9){
         danceFrame=10;
    }
    else if(danceFrame==10){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-07gold.png"));
         danceFrame=11;
    }
    //NORTH
    else if(danceFrame==11){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-03gold.png"));
         danceFrame=12;
    }
    else if(danceFrame==12){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-04gold.png"));
         danceFrame=13;
    }
    else if(danceFrame==13){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-03gold.png"));
         danceFrame=14;
    }
    else if(danceFrame==14){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-11gold.png"));
         danceFrame=15;
    }
    else if(danceFrame==15){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-03gold.png"));
         danceFrame=16;
    }
    //WEST
    else if(danceFrame==16){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-10gold.png"));
         danceFrame=17;
    }
    else if(danceFrame==17){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-09gold.png"));
         danceFrame=18;
    }
    else if(danceFrame==18){
         danceFrame=19;
    }
    else if(danceFrame==19){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-10gold.png"));
         danceFrame=20;
    }
    else if(danceFrame==20){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-08gold.png"));
         danceFrame=21;
    }
    else if(danceFrame==21){
         danceFrame=22;
    }
    else if(danceFrame==22){
         setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-10gold.png"));
         danceFrame=0;
    }
}

void Robot::finish(bool i)
{
    qDebug()<<"lol";
    if(i==0){
        level->finish(0);
    }
    else{
        qDebug()<<"lol";
        level->finish(level->getLevelNo());
    }
    disconnect(delay,0,0,0);
}



