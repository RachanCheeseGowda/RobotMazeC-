#include "Obstacle.h"
#include <QtDebug>
#include "Game.h"

extern Game *level;

Obstacle::Obstacle(int obstacle_type,int x,int y)
{
    this->obstacle_type = obstacle_type;
    this->x=x;
    this->y=y;
    fire = new QTimer();
}

Obstacle::~Obstacle()
{
    delete fire;
}

void Obstacle::set_image()
{
    if(obstacle_type==5){
        setScale(0.1);
        setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-01.png"));
    }
    if(obstacle_type==4){
        setScale(0.1);
        setPixmap(QPixmap(":/Images/Images/Obstacles/BUTTONS-01.png"));
    }
    if(obstacle_type==3){
        setScale(0.08);
        setPixmap(QPixmap(":/Images/Images/Obstacles/bridge-01.png"));
    }
    if(obstacle_type==-3){
        setScale(0.08);
        setPixmap(QPixmap(":/Images/Images/Obstacles/sbridge-01.png"));
    }

    if(obstacle_type==6){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal1.png"));
    }
    if(obstacle_type==-6){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal1.png"));
    }
    if(obstacle_type==7){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal2.png"));
    }
    if(obstacle_type==-7){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal2.png"));
    }
    if(obstacle_type==8){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal3.png"));
    }
    if(obstacle_type==-8){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal3.png"));
    }
    if(obstacle_type==9){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal4.png"));
    }
    if(obstacle_type==-9){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal4.png"));
    }
}

int Obstacle::getObstacle_type() const
{
    return obstacle_type;
}
//FIRE = 5
//BUTTON = 4
//BRIDGE = 3
//PORTALS = 6  -6
//          7  -7
void Obstacle::setObstacle_type(const int &value)
{
    obstacle_type = value;
}

void Obstacle::animateBridge(int i)
{
    if(obstacle_type==3){
        if(i==0){
            setPixmap(QPixmap(":/Images/Images/Obstacles/bridge-01.png"));
        }
        if(i==level->tileSize/4){
        }
        else if(i==2*level->tileSize/4){
            setPixmap(QPixmap(":/Images/Images/Obstacles/bridge-02.png"));
        }
        else if(i==3*level->tileSize/4){
            setPixmap(QPixmap(":/Images/Images/Obstacles/bridge-03.png"));
        }
        else if(i==4*level->tileSize/4 - 1){
            setPixmap(QPixmap(":/Images/Images/Obstacles/bridge-04.png"));
        }
    }
    if(obstacle_type==-3){
        if(i==0){
            setPixmap(QPixmap(":/Images/Images/Obstacles/sbridge-01.png"));
        }
        if(i==level->tileSize/4){
        }
        else if(i==2*level->tileSize/4){
            setPixmap(QPixmap(":/Images/Images/Obstacles/sbridge-02.png"));
        }
        else if(i==3*level->tileSize/4){
            setPixmap(QPixmap(":/Images/Images/Obstacles/sbridge-03.png"));
        }
        else if(i==4*level->tileSize/4 - 1){
            setPixmap(QPixmap(":/Images/Images/Obstacles/sbridge-04.png"));
        }
    }
}

void Obstacle::startFire()
{
    if(obstacle_type==5){
        fire->start(200);
        connect(fire,SIGNAL(timeout()),this,SLOT(animateFire()));
    }
}


void Obstacle::animateFire()
{
    setScale(0.1);
    if(obstacle_type==5){
        if(fire_frame==0){
            setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-01.png"));
        }
        if(fire_frame==1){
            setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-02.png"));
        }
        if(fire_frame==2){
            setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-03.png"));
        }
        if(fire_frame==3){
            setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-04.png"));
        }
        if(fire_frame==4){
            setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-05.png"));
        }
        if(fire_frame==5){
            setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-06.png"));
        }
        if(fire_frame==6){
            setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-07.png"));
        }
        if(fire_frame==7){
            setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-08.png"));
        }
        if(fire_frame==8){
            setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-09.png"));
        }
        fire_frame++;
        if(fire_frame>8){
            fire_frame=0;
        }
    }
}

void Obstacle::stopFire()
{
    fire->stop();
    disconnect(fire,0,0,0);
    setPixmap(QPixmap(""));
}

void Obstacle::toggleButton()
{
    if(obstacle_type==4){
        qDebug()<<"TURNING BUTTON ON";
        setPixmap(QPixmap(":/Images/Images/Obstacles/BUTTONS-02.png"));
    }
}

int Obstacle::getX() const
{
    return x;
}

void Obstacle::setX(int value)
{
    x = value;
}

int Obstacle::getY() const
{
    return y;
}

void Obstacle::setY(int value)
{
    y = value;
}
