#include "algorithmblock.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include <QGraphicsPixmapItem>
#include <typeinfo>
#include <QDebug>

extern Game *level;
extern Game *level;

AlgorithmBlock::AlgorithmBlock(QString blockType,QString direction,int steps,int y)
{
    this->blockType=blockType;
    this->direction=direction;
    this->steps=steps;
    this->y = y;
    this->newlyPlaced=0;
    this->start=0;
    setImage();
}

AlgorithmBlock::~AlgorithmBlock()
{

}

void AlgorithmBlock::setImage()
{
    //START
    if(blockType=="START" &&direction==""&&steps==0){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/STARTgreen.png"));
    }
    //NORTH
    if(blockType=="MOVE" &&direction=="NORTH"&&steps==1){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarN1S.png"));
    }
    if(blockType=="MOVE" &&direction=="NORTH"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarN2S.png"));
    }
    if(blockType=="MOVE" &&direction=="NORTH"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarN3S.png"));
    }
    if(blockType=="MOVE" &&direction=="NORTH"&&steps==4){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarN4S.png"));
    }
    //SOUTH
    if(blockType=="MOVE" &&direction=="SOUTH"&&steps==1){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarS1S.png"));
    }
    if(blockType=="MOVE" &&direction=="SOUTH"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarS2S.png"));
    }
    if(blockType=="MOVE" &&direction=="SOUTH"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarS3S.png"));
    }
    if(blockType=="MOVE" &&direction=="SOUTH"&&steps==4){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarS4S.png"));
    }
    //WEST
    if(blockType=="MOVE" &&direction=="WEST"&&steps==1){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarW1S.png"));
    }
    if(blockType=="MOVE" &&direction=="WEST"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarW2S.png"));
    }
    if(blockType=="MOVE" &&direction=="WEST"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarW3S.png"));
    }
    if(blockType=="MOVE" &&direction=="WEST"&&steps==4){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarW4S.png"));
    }
    //EAST
    if(blockType=="MOVE" &&direction=="EAST"&&steps==1){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarE1S.png"));
    }
    if(blockType=="MOVE" &&direction=="EAST"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarE2S.png"));
    }
    if(blockType=="MOVE" &&direction=="EAST"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarE3S.png"));
    }
    if(blockType=="MOVE" &&direction=="EAST"&&steps==4){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarE4S.png"));
    }
    //BRIDGE
    if(blockType=="BRIDGE" &&direction=="EAST"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarBE.png"));
    }
    if(blockType=="BRIDGE" &&direction=="WEST"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarBW.png"));
    }
    if(blockType=="BRIDGE" &&direction=="NORTH"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarBN.png"));
    }
    if(blockType=="BRIDGE" &&direction=="SOUTH"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarBS.png"));
    }
    //JUMP
    if(blockType=="JUMP" &&direction=="EAST"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarJE.png"));
    }
    if(blockType=="JUMP" &&direction=="WEST"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarJW.png"));
    }
    if(blockType=="JUMP" &&direction=="NORTH"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarJN.png"));
    }
    if(blockType=="JUMP" &&direction=="SOUTH"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarJS.png"));
    }
    setScale(0.525);
    setPos(48,getY());
}

void AlgorithmBlock::setSelectedImage()
{
    //START
    if(blockType=="START" &&direction==""&&steps==0){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/START.png"));
    }
    //NORTH
    if(blockType=="MOVE" &&direction=="NORTH"&&steps==1){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarN1S.png"));
    }
    if(blockType=="MOVE" &&direction=="NORTH"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarN2S.png"));
    }
    if(blockType=="MOVE" &&direction=="NORTH"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarN3S.png"));
    }
    if(blockType=="MOVE" &&direction=="NORTH"&&steps==4){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarN4S.png"));
    }
    //SOUTH
    if(blockType=="MOVE" &&direction=="SOUTH"&&steps==1){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarS1S.png"));
    }
    if(blockType=="MOVE" &&direction=="SOUTH"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarS2S.png"));
    }
    if(blockType=="MOVE" &&direction=="SOUTH"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarS3S.png"));
    }
    if(blockType=="MOVE" &&direction=="SOUTH"&&steps==4){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarS4S.png"));
    }
    //WEST
    if(blockType=="MOVE" &&direction=="WEST"&&steps==1){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarW1S.png"));
    }
    if(blockType=="MOVE" &&direction=="WEST"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarW2S.png"));
    }
    if(blockType=="MOVE" &&direction=="WEST"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarW3S.png"));
    }
    if(blockType=="MOVE" &&direction=="WEST"&&steps==4){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarW4S.png"));
    }
    //EAST
    if(blockType=="MOVE" &&direction=="EAST"&&steps==1){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarE1S.png"));
    }
    if(blockType=="MOVE" &&direction=="EAST"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarE2S.png"));
    }
    if(blockType=="MOVE" &&direction=="EAST"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarE3S.png"));
    }
    if(blockType=="MOVE" &&direction=="EAST"&&steps==4){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarE4S.png"));
    }
    //BRIDGE
    if(blockType=="BRIDGE" &&direction=="EAST"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarBE.png"));
    }
    if(blockType=="BRIDGE" &&direction=="WEST"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarBW.png"));
    }
    if(blockType=="BRIDGE" &&direction=="NORTH"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarBN.png"));
    }
    if(blockType=="BRIDGE" &&direction=="SOUTH"&&steps==3){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarBS.png"));
    }
    //JUMP
    if(blockType=="JUMP" &&direction=="EAST"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarJE.png"));
    }
    if(blockType=="JUMP" &&direction=="WEST"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarJW.png"));
    }
    if(blockType=="JUMP" &&direction=="NORTH"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarJN.png"));
    }
    if(blockType=="JUMP" &&direction=="SOUTH"&&steps==2){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/purplebarJS.png"));
    }
    setScale(0.525);
    setPos(48,getY());
}

int AlgorithmBlock::getStart()
{
    return start;
}

void AlgorithmBlock::setStart(int value)
{
    start = value;
}

QString AlgorithmBlock::getBlockType() const
{
    return blockType;
}

//DO NOT TOUCH
void AlgorithmBlock::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->blockType!="START" and start==0){
        for(AlgorithmBlock* b:level->sequence){
            b->setImage();
        }
        setSelectedImage();
        qDebug()<<"click";
        if(newlyPlaced==0){
            newlyPlaced=1;
            level->setCursor(this);
            initY=getY();
            setZValue(1);
        }
    }
}
//DO NOT TOUCH
void AlgorithmBlock::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->blockType!="START"&&start==0){
        qDebug()<<"click";
        AlgorithmBlock* a = new AlgorithmBlock("","",0,0);
        //not the best method
        if(this->blockType!="START"){
            //snap feature
            int prev=level->initialY+43;
            int next;
            for(int i= prev;i<=500;i+=43){
                next=i;
                if(getY()>=prev && getY()<next){
                    if(initY>getY()){
                        if(getY()<prev+23){
                            setY(prev);
                        }
                        else{
                            setY(prev+10);
                        }
                    }
                    else{
                        if(getY()<prev+23){
                            setY(prev-10);
                        }
                        else{
                            setY(prev);
                        }
                    }
                }
                prev=next;
            }
            setPos(48,getY());
            setZValue(-1);
            level->setCursor(a);
            setSelectedImage();
            level->format(initY);
        }
    }
    else if(start==0){
        this->setSelectedImage();
        level->startGame();
        start=1;
        newlyPlaced=1;
    }
}

void AlgorithmBlock::setBlockType(QString s)
{
    blockType = s;
}

void AlgorithmBlock::setDirection(QString s)
{
    direction = s;
}

void AlgorithmBlock::setSteps(int i)
{
    steps = i;
}

int AlgorithmBlock::getSteps()
{
    return steps;
}

void AlgorithmBlock::setY(int i)
{
    y=i;
}

int AlgorithmBlock::getY()
{
    return y;
}

QString AlgorithmBlock::getDirection()
{
    return direction;
}

