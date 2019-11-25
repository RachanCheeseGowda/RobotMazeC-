#include "Stage2.h"

Stage2::Stage2(QWidget *parent)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

Stage2::~Stage2()
{
    delete stageSelectScene;
    delete back;
    delete home;
    delete level13;
    delete level14;
    delete level15;
    delete level16;
    delete level17;
    delete level18;
    delete level19;
    delete level20;
    delete level21;
    delete level22;
    delete level23;
    delete level24;
}

void Stage2::clear()
{
    delete back;
    delete home;
    delete level13;
    delete level14;
    delete level15;
    delete level16;
    delete level17;
    delete level18;
    delete level19;
    delete level20;
    delete level21;
    delete level22;
    delete level23;
    delete level24;
    delete stageSelectScene;
}

extern QString currentPlayerName;

void Stage2::display()
{
    clear();
    setWindowTitle(currentPlayerName);
    stageSelectScene = new QGraphicsScene();
    //SET SCENE SIZE
    stageSelectScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setWindowTitle(currentPlayerName+" STAGE 2");
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/level2select.png")));
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

    level13 = new Button("LEVEL13");
    level13->setPos(40,150);
    stageSelectScene->addItem(level13);

    level14 = new Button("LEVEL14");
    level14->setPos(253,150);
    stageSelectScene->addItem(level14);

    level15 = new Button("LEVEL15");
    level15->setPos(467,150);
    stageSelectScene->addItem(level15);

    level16 = new Button("LEVEL16");
    level16->setPos(680,150);
    stageSelectScene->addItem(level16);

    level17 = new Button("LEVEL17");
    level17->setPos(40,290);
    stageSelectScene->addItem(level17);

    level18 = new Button("LEVEL18");
    level18->setPos(253,290);
    stageSelectScene->addItem(level18);

    level19 = new Button("LEVEL19");
    level19->setPos(467,290);
    stageSelectScene->addItem(level19);

    level20 = new Button("LEVEL20");
    level20->setPos(680,290);
    stageSelectScene->addItem(level20);

    level21 = new Button("LEVEL21");
    level21->setPos(40,430);
    stageSelectScene->addItem(level21);

    level22 = new Button("LEVEL22");
    level22->setPos(253,430);
    stageSelectScene->addItem(level22);

    level23 = new Button("LEVEL23");
    level23->setPos(467,430);
    stageSelectScene->addItem(level23);

    level24 = new Button("LEVEL24");
    level24->setPos(680,430);
    stageSelectScene->addItem(level24);
    show();
}
