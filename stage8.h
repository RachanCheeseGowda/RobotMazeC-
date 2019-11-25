#ifndef STAGE8_H
#define STAGE8_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "button.h"
#include <QMouseEvent>

class Stage8: public QGraphicsView{
public:
    Stage8(QWidget * parent=0);
    ~Stage8();
    QPointer<QGraphicsScene> stageSelectScene;
    void display();
    void clear();

    QPointer<Button> back;
    QPointer<Button> home;
    QPointer<Button> level85;
    QPointer<Button> level86;
    QPointer<Button> level87;
    QPointer<Button> level88;
    QPointer<Button> level89;
    QPointer<Button> level90;
    QPointer<Button> level91;
    QPointer<Button> level92;
    QPointer<Button> level93;
    QPointer<Button> level94;
    QPointer<Button> level95;
    QPointer<Button> level96;
};
#endif // STAGE8_H
