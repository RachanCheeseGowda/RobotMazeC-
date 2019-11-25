#include "Stage4.h"

Stage4::Stage4(QWidget *parent)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

Stage4::~Stage4()
{
    delete stageSelectScene;
    delete back;
    delete home;
    delete level37;
    delete level38;
    delete level39;
    delete level40;
    delete level41;
    delete level42;
    delete level43;
    delete level44;
    delete level45;
    delete level46;
    delete level47;
    delete level48;
}

void Stage4::clear()
{
    delete back;
    delete home;
    delete level37;
    delete level38;
    delete level39;
    delete level40;
    delete level41;
    delete level42;
    delete level43;
    delete level44;
    delete level45;
    delete level46;
    delete level47;
    delete level48;
    delete stageSelectScene;
}

extern QString currentPlayerName;

void Stage4::display()
{
    clear();
    setWindowTitle(currentPlayerName);
    stageSelectScene = new QGraphicsScene();
    //SET SCENE SIZE
    stageSelectScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setWindowTitle(currentPlayerName+" STAGE 4");
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/level4select.png")));
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

    level37 = new Button("LEVEL37");
    level37->setPos(40,150);
    stageSelectScene->addItem(level37);

    level38 = new Button("LEVEL38");
    level38->setPos(253,150);
    stageSelectScene->addItem(level38);

    level39 = new Button("LEVEL39");
    level39->setPos(467,150);
    stageSelectScene->addItem(level39);

    level40 = new Button("LEVEL40");
    level40->setPos(680,150);
    stageSelectScene->addItem(level40);

    level41 = new Button("LEVEL41");
    level41->setPos(40,290);
    stageSelectScene->addItem(level41);

    level42 = new Button("LEVEL42");
    level42->setPos(253,290);
    stageSelectScene->addItem(level42);

    level43 = new Button("LEVEL43");
    level43->setPos(467,290);
    stageSelectScene->addItem(level43);

    level44 = new Button("LEVEL44");
    level44->setPos(680,290);
    stageSelectScene->addItem(level44);

    level45 = new Button("LEVEL45");
    level45->setPos(40,430);
    stageSelectScene->addItem(level45);

    level46 = new Button("LEVEL46");
    level46->setPos(253,430);
    stageSelectScene->addItem(level46);

    level47 = new Button("LEVEL47");
    level47->setPos(467,430);
    stageSelectScene->addItem(level47);

    level48 = new Button("LEVEL48");
    level48->setPos(680,430);
    stageSelectScene->addItem(level48);
    show();
}
