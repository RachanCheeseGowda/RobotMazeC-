#include "Stage1.h"

Stage1::Stage1(QWidget *parent)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

Stage1::~Stage1()
{
    delete stageSelectScene;
    delete back;
    delete home;
    delete level1;
    delete level2;
    delete level3;
    delete level4;
    delete level5;
    delete level6;
    delete level7;
    delete level8;
    delete level9;
    delete level10;
    delete level11;
    delete level12;
}

void Stage1::clear()
{
    delete back;
    delete home;
    delete level1;
    delete level2;
    delete level3;
    delete level4;
    delete level5;
    delete level6;
    delete level7;
    delete level8;
    delete level9;
    delete level10;
    delete level11;
    delete level12;
    delete stageSelectScene;
}

extern QString currentPlayerName;

void Stage1::display()
{
    clear();
    setWindowTitle(currentPlayerName);
    stageSelectScene = new QGraphicsScene();
    //SET SCENE SIZE
    stageSelectScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setWindowTitle(currentPlayerName+" STAGE 1");
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/level1select.png")));
    setScene(stageSelectScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //SET VIEW SIZE
    setFixedSize(900,600);

    back = new Button("BACK");
    back->setPos(10,10);
    stageSelectScene->addItem(back);

    home = new Button("STAGEHOME");
    home->setPos(10,53);
    stageSelectScene->addItem(home);

    level1 = new Button("LEVEL1");
    level1->setPos(40,150);
    stageSelectScene->addItem(level1);

    level2 = new Button("LEVEL2");
    level2->setPos(253,150);
    stageSelectScene->addItem(level2);

    level3 = new Button("LEVEL3");
    level3->setPos(467,150);
    stageSelectScene->addItem(level3);

    level4 = new Button("LEVEL4");
    level4->setPos(680,150);
    stageSelectScene->addItem(level4);

    level5 = new Button("LEVEL5");
    level5->setPos(40,290);
    stageSelectScene->addItem(level5);

    level6 = new Button("LEVEL6");
    level6->setPos(253,290);
    stageSelectScene->addItem(level6);

    level7 = new Button("LEVEL7");
    level7->setPos(467,290);
    stageSelectScene->addItem(level7);

    level8 = new Button("LEVEL8");
    level8->setPos(680,290);
    stageSelectScene->addItem(level8);

    level9 = new Button("LEVEL9");
    level9->setPos(40,430);
    stageSelectScene->addItem(level9);

    level10 = new Button("LEVEL10");
    level10->setPos(253,430);
    stageSelectScene->addItem(level10);

    level11 = new Button("LEVEL11");
    level11->setPos(467,430);
    stageSelectScene->addItem(level11);

    level12 = new Button("LEVEL12");
    level12->setPos(680,430);
    stageSelectScene->addItem(level12);
    show();
}

