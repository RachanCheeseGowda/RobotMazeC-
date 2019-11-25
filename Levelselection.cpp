#include "LevelSelection.h"
#include "button.h"
#include <QtDebug>
#include "text.h"
#include <QPointer>

LevelSelection::LevelSelection(QWidget *parent): QGraphicsView(){
    display();
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

LevelSelection::~LevelSelection()
{
    delete levelSelectScene;
    delete home;
    delete stage1;
    delete stage2;
    delete stage3;
    delete stage4;
    delete stage5;
    delete stage6;
    delete stage7;
    delete stage8;

    delete stageNo1;
    delete stageNo2;
    delete stageNo3;
    delete stageNo4;
    delete stageNo5;
    delete stageNo6;
    delete stageNo7;
    delete stageNo8;
}
extern QString currentPlayerName;

void LevelSelection:: clear(){
    delete home;
    delete stage1;
    delete stage2;
    delete stage3;
    delete stage4;
    delete stage5;
    delete stage6;
    delete stage7;
    delete stage8;

    delete stageNo1;
    delete stageNo2;
    delete stageNo3;
    delete stageNo4;
    delete stageNo5;
    delete stageNo6;
    delete stageNo7;
    delete stageNo8;
    delete levelSelectScene;
}

void LevelSelection::display()
{
    clear();
    setWindowTitle(currentPlayerName);
    levelSelectScene = new QGraphicsScene();
    //SET SCENE SIZE
    levelSelectScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/mainmenu.png")));
    setScene(levelSelectScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //SET VIEW SIZE
    setFixedSize(900,600);

    home = new Button("LSHOME");
    home->setPos(10,10);
    levelSelectScene->addItem(home);

    setMouseTracking(true);

    stage1 = new Button("STAGE1");
    stage1->setPos(87,144);
    levelSelectScene->addItem(stage1);
    stageNo1 = new Text('1');
    stageNo1->setPos(125,130);
    stageNo1->setOpacity(0.5);
    //stageNo1->set_black_digit('1');
    stageNo1->setScale(0.3);
    levelSelectScene->addItem(stageNo1);

    stage2 = new Button("STAGE2");
    stage2->setPos(22,305);
    levelSelectScene->addItem(stage2);
    stageNo2 = new Text('2');
    stageNo2->setPos(48,290);
    stageNo2->setOpacity(0.5);
    //stageNo2->set_black_digit('2');
    stageNo2->setScale(0.3);
    levelSelectScene->addItem(stageNo2);

    stage3 = new Button("STAGE3");
    stage3->setPos(274,174);
    levelSelectScene->addItem(stage3);
    stageNo3 = new Text('3');
    stageNo3->setPos(301,160);
    stageNo3->setOpacity(0.5);
    //stageNo3->set_black_digit('3');
    stageNo3->setScale(0.3);
    levelSelectScene->addItem(stageNo3);

    stage4 = new Button("STAGE4");
    stage4->setPos(170,364);
    levelSelectScene->addItem(stage4);
    stageNo4 = new Text('4');
    stageNo4->setPos(210,350);
    stageNo4->setOpacity(0.5);
    //stageNo4->set_black_digit('4');
    stageNo4->setScale(0.3);
    levelSelectScene->addItem(stageNo4);

    stage5 = new Button("STAGE5");
    stage5->setPos(429,40);
    levelSelectScene->addItem(stage5);
    stageNo5 = new Text('5');
    stageNo5->setPos(506,26);
    stageNo5->setOpacity(0.5);
    //stageNo5->set_black_digit('5');
    stageNo5->setScale(0.3);
    levelSelectScene->addItem(stageNo5);

    stage6 = new Button("STAGE6");
    stage6->setPos(830,168);
    levelSelectScene->addItem(stage6);
    stageNo6 = new Text('6');
    stageNo6->setPos(857,153);
    stageNo6->setOpacity(0.5);
    //stageNo6->set_black_digit('6');
    stageNo6->setScale(0.3);
    levelSelectScene->addItem(stageNo6);

    stage7 = new Button("STAGE7");
    stage7->setPos(708,310);
    levelSelectScene->addItem(stage7);
    stageNo7 = new Text('7');
    stageNo7->setPos(739,294);
    stageNo7->setOpacity(0.5);
    //stageNo7->set_black_digit('7');
    stageNo7->setScale(0.3);
    levelSelectScene->addItem(stageNo7);

    stage8 = new Button("STAGE8");
    stage8->setPos(570,380);
    levelSelectScene->addItem(stage8);
    stageNo8 = new Text('8');
    stageNo8->setPos(613,465);
    stageNo8->setOpacity(0.5);
    //stageNo8->set_black_digit('8');
    stageNo8->setScale(0.3);
    levelSelectScene->addItem(stageNo8);
    show();
}
