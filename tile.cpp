#include "Game.h"
#include "tile.h"
#include <QDebug>


Tile::Tile(int x, int y, int tileSize,int tileState)
{
    this->x=x;
    this->y=y;
    this->tileSize = tileSize;
    this->tileState=tileState;
}

int Tile::getX()
{
    return x;
}

void Tile::setX(int i)
{
    x=i;
}

int Tile::getY()
{
    return y;
}

void Tile::setY(int i)
{
    y=i;
}

void Tile::check(QPoint q)
{
    if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==1){
        qDebug()<<"TRUE ("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==0){
        qDebug()<<"VOID"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==2){
        qDebug()<<"WINNING TILE"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==3){
        qDebug()<<"SIDEWAYS BRIDGE"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==-3){
        qDebug()<<"BRIDGE"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==4){
        qDebug()<<"BUTTON"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==5){
        qDebug()<<"FIRE"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==6){
        qDebug()<<"PORTAL"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==-6){
        qDebug()<<"PORTAL"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==7){
        qDebug()<<"PORTAL"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==-7){
        qDebug()<<"PORTAL"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==8){
        qDebug()<<"PORTAL"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==-8){
        qDebug()<<"PORTAL"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==9){
        qDebug()<<"PORTAL"<<"("<<x<<y<<")";
    }
    else if(q.x()>x && q.x()<x+tileSize && q.y()>y && q.y()<y+tileSize&&this->tileState==-9){
        qDebug()<<"PORTAL"<<"("<<x<<y<<")";
    }
}

int Tile::getTileState()
{
    return tileState;
}
//0-space
//1-valid
//2-finish
//3-bridge
//4-button
//5-fire
//6 & -6 - portal pair 1
//7 & -7 - portal pair 2
void Tile::setTileState(int i)
{
    tileState=i;
}
