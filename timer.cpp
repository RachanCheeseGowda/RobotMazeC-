#include "Timer.h"
#include "QString"
#include <QtDebug>
#include <QTimer>
#include <QThread>
#include "Game.h"
#include "Button.h"
extern Game *level;

Timer::Timer(int i)
{
    setScale(0.20);
    this->timer=i;
}

Timer::~Timer()
{
    delete t1;
    delete second;
    delete medal;
}

void Timer::increment()
{
    timer++;
    if(timer>=99){
        this->set_image('9');
        t1->set_image('9');
        second->stop();
    }
    display();
}

void Timer::display()
{
    QString display_number = QString::number(timer);
    int len = display_number.length();
    for (int i=0;i<len;i++){
        set_image(display_number[0+i]);
        if(i==0){
            if(display_number[i]=='1'){
                this->setPos(209,27);
            }
            else{
                this->setPos(206,27);
            }
        }
        if(i==1){
            t1->set_image(display_number[1-i]);
            if(display_number[1]=='1'){
                this->setPos(215,27);
            }
            else{
                this->setPos(212,27);
            }
            if(display_number[0]=='1'){
                t1->setPos(204,27);
            }
            else{
                t1->setPos(195,27);
            }
        }
    }
    //change the medal
    if(timer>=30){
        medal->setButton_name("SILVERMEDAL");
        medal->setPos(178,0);
    }
    if(timer>=60){
        medal->setButton_name("BRONZEMEDAL");
        medal->setPos(177,0);
    }
}

void Timer::set_image(QChar i)
{

    if(i=='0'){
        setPixmap(QPixmap(":/Images/Images/Digit/0blk.png"));
    }
    if(i=='1'){
        setPixmap(QPixmap(":/Images/Images/Digit/1blk.png"));
    }
    if(i=='2'){
        setPixmap(QPixmap(":/Images/Images/Digit/2blk.png"));
    }
    if(i=='3'){
        setPixmap(QPixmap(":/Images/Images/Digit/3blk.png"));
    }
    if(i=='4'){
        setPixmap(QPixmap(":/Images/Images/Digit/4blk.png"));
    }
    if(i=='5'){
        setPixmap(QPixmap(":/Images/Images/Digit/5blk.png"));
    }
    if(i=='6'){
        setPixmap(QPixmap(":/Images/Images/Digit/6blk.png"));
    }
    if(i=='7'){
        setPixmap(QPixmap(":/Images/Images/Digit/7blk.png"));
    }
    if(i=='8'){
        setPixmap(QPixmap(":/Images/Images/Digit/8blk.png"));
    }
    if(i=='9'){
        setPixmap(QPixmap(":/Images/Images/Digit/9blk.png"));
    }
}

void Timer::start()
{
    medal = new Button("GOLDMEDAL");
    medal->setPos(180,0);
    medal->setScale(0.35);
    medal->setZValue(-1);
    t1=new Timer(0);
    level->scene->addItem(t1);
    level->scene->addItem(medal);
    second = new QTimer();
    second->start(1000);
    connect(second, &QTimer::timeout, this, std::bind(&Timer::increment,this));

}

void Timer::resert_timer()
{
    timer=0;
}

void Timer::set_medal(int i)
{

}

void Timer::end()
{
    second->stop();
}

void Timer::reset()
{
    timer=0;
    disconnect(second,0,0,0);
}
