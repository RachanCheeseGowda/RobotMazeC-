#ifndef STAGE7_H
#define STAGE7_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "button.h"
#include <QMouseEvent>

class Stage7: public QGraphicsView{
public:
    Stage7(QWidget * parent=0);
    ~Stage7();
    QPointer<QGraphicsScene> stageSelectScene;
    void display();
    void clear();

    QPointer<Button> back;
    QPointer<Button> home;
    QPointer<Button> level73;
    QPointer<Button> level74;
    QPointer<Button> level75;
    QPointer<Button> level76;
    QPointer<Button> level77;
    QPointer<Button> level78;
    QPointer<Button> level79;
    QPointer<Button> level80;
    QPointer<Button> level81;
    QPointer<Button> level82;
    QPointer<Button> level83;
    QPointer<Button> level84;
};
#endif // STAGE7_H
