#ifndef STAGE5_H
#define STAGE5_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "button.h"
#include <QMouseEvent>

class Stage5: public QGraphicsView{
public:
    Stage5(QWidget * parent=0);
    ~Stage5();
    QPointer<QGraphicsScene> stageSelectScene;
    void display();
    void clear();

    QPointer<Button> back;
    QPointer<Button> home;
    QPointer<Button> level49;
    QPointer<Button> level50;
    QPointer<Button> level51;
    QPointer<Button> level52;
    QPointer<Button> level53;
    QPointer<Button> level54;
    QPointer<Button> level55;
    QPointer<Button> level56;
    QPointer<Button> level57;
    QPointer<Button> level58;
    QPointer<Button> level59;
    QPointer<Button> level60;
};
#endif // STAGE5_H
