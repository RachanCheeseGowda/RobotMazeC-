#ifndef STAGE3_H
#define STAGE3_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "button.h"
#include <QMouseEvent>

class Stage3: public QGraphicsView{
public:
    Stage3(QWidget * parent=0);
    ~Stage3();
    QPointer<QGraphicsScene> stageSelectScene;
    void display();
    void clear();

    QPointer<Button> back;
    QPointer<Button> home;
    QPointer<Button> level25;
    QPointer<Button> level26;
    QPointer<Button> level27;
    QPointer<Button> level28;
    QPointer<Button> level29;
    QPointer<Button> level30;
    QPointer<Button> level31;
    QPointer<Button> level32;
    QPointer<Button> level33;
    QPointer<Button> level34;
    QPointer<Button> level35;
    QPointer<Button> level36;
};
#endif // STAGE3_H
