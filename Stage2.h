#ifndef STAGE2_H
#define STAGE2_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "button.h"
#include <QMouseEvent>

class Stage2: public QGraphicsView{
public:
    Stage2(QWidget * parent=0);
    ~Stage2();
    QPointer<QGraphicsScene> stageSelectScene;
    void display();
    void clear();

    QPointer<Button> back;
    QPointer<Button> home;
    QPointer<Button> level13;
    QPointer<Button> level14;
    QPointer<Button> level15;
    QPointer<Button> level16;
    QPointer<Button> level17;
    QPointer<Button> level18;
    QPointer<Button> level19;
    QPointer<Button> level20;
    QPointer<Button> level21;
    QPointer<Button> level22;
    QPointer<Button> level23;
    QPointer<Button> level24;
};
#endif // STAGE2_H
