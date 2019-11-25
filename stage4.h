#ifndef STAGE4_H
#define STAGE4_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "button.h"
#include <QMouseEvent>

class Stage4: public QGraphicsView{
public:
    Stage4(QWidget * parent=0);
    ~Stage4();
    QPointer<QGraphicsScene> stageSelectScene;
    void display();
    void clear();

    QPointer<Button> back;
    QPointer<Button> home;
    QPointer<Button> level37;
    QPointer<Button> level38;
    QPointer<Button> level39;
    QPointer<Button> level40;
    QPointer<Button> level41;
    QPointer<Button> level42;
    QPointer<Button> level43;
    QPointer<Button> level44;
    QPointer<Button> level45;
    QPointer<Button> level46;
    QPointer<Button> level47;
    QPointer<Button> level48;
};
#endif // STAGE4_H
