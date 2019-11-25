#ifndef TIMER_H
#define TIMER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "button.h"
class Timer: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Timer(int i);
    ~Timer();
    void display();
    void set_image(QChar i);
    void start();
    void resert_timer();
    void set_medal(int i);
    void end();
    void reset();
    int timer=0;
    Timer *t1;
    QTimer *second;
    Button *medal;
public slots:
    void increment();
private:
};
#endif // TIMER_H
