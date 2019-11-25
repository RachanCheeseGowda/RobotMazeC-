#ifndef STAGE1_H
#define STAGE1_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "button.h"
#include <QMouseEvent>

class Stage1: public QGraphicsView{
public:
    Stage1(QWidget * parent=0);
    ~Stage1();
    QPointer<QGraphicsScene> stageSelectScene;
    void display();
    void clear();

    QPointer<Button> back;
    QPointer<Button> home;
    QPointer<Button> level1;
    QPointer<Button> level2;
    QPointer<Button> level3;
    QPointer<Button> level4;
    QPointer<Button> level5;
    QPointer<Button> level6;
    QPointer<Button> level7;
    QPointer<Button> level8;
    QPointer<Button> level9;
    QPointer<Button> level10;
    QPointer<Button> level11;
    QPointer<Button> level12;
};
#endif // STAGE1_H
