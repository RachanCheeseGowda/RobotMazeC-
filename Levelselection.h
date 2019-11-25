#ifndef LEVELSELECTION_H
#define LEVELSELECTION_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "button.h"
#include <QMouseEvent>
#include "text.h"

class LevelSelection: public QGraphicsView{
public:
    LevelSelection(QWidget * parent=0);
    ~LevelSelection();
    QPointer<QGraphicsScene> levelSelectScene;
    void display();
    void clear();

    QPointer<Button> home;
    QPointer<Button> stage1;
    QPointer<Button> stage2;
    QPointer<Button> stage3;
    QPointer<Button> stage4;
    QPointer<Button> stage5;
    QPointer<Button> stage6;
    QPointer<Button> stage7;
    QPointer<Button> stage8;

    QPointer<Text> stageNo1;
    QPointer<Text> stageNo2;
    QPointer<Text> stageNo3;
    QPointer<Text> stageNo4;
    QPointer<Text> stageNo5;
    QPointer<Text> stageNo6;
    QPointer<Text> stageNo7;
    QPointer<Text> stageNo8;
};
#endif // LEVELSELECTION_H
