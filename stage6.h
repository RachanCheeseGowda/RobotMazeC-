#ifndef STAGE6_H
#define STAGE6_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "button.h"
#include <QMouseEvent>

class Stage6: public QGraphicsView{
public:
    Stage6(QWidget * parent=0);
    ~Stage6();
    QPointer<QGraphicsScene> stageSelectScene;
    void display();
    void clear();

    QPointer<Button> back;
    QPointer<Button> home;
    QPointer<Button> level61;
    QPointer<Button> level62;
    QPointer<Button> level63;
    QPointer<Button> level64;
    QPointer<Button> level65;
    QPointer<Button> level66;
    QPointer<Button> level67;
    QPointer<Button> level68;
    QPointer<Button> level69;
    QPointer<Button> level70;
    QPointer<Button> level71;
    QPointer<Button> level72;
};
#endif // STAGE6_H
