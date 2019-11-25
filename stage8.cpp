#include "Stage8.h"

Stage8::Stage8(QWidget *parent)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

Stage8::~Stage8()
{
    delete back;
    delete home;
    delete level85;
    delete level86;
    delete level87;
    delete level88;
    delete level89;
    delete level90;
    delete level91;
    delete level92;
    delete level93;
    delete level94;
    delete level95;
    delete level96;
    delete stageSelectScene;
}

void Stage8::clear()
{
    delete back;
    delete home;
    delete level85;
    delete level86;
    delete level87;
    delete level88;
    delete level89;
    delete level90;
    delete level91;
    delete level92;
    delete level93;
    delete level94;
    delete level95;
    delete level96;
    delete stageSelectScene;
}

extern QString currentPlayerName;

void Stage8::display()
{
    clear();
    setWindowTitle(currentPlayerName);
    stageSelectScene = new QGraphicsScene();
    //SET SCENE SIZE
    stageSelectScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setWindowTitle(currentPlayerName+" STAGE 3");
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/level8select.png")));
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

    level85 = new Button("LEVEL85");
    level85->setPos(40,150);
    stageSelectScene->addItem(level85);

    level86 = new Button("LEVEL86");
    level86->setPos(253,150);
    stageSelectScene->addItem(level86);

    level87 = new Button("LEVEL87");
    level87->setPos(467,150);
    stageSelectScene->addItem(level87);

    level88 = new Button("LEVEL88");
    level88->setPos(680,150);
    stageSelectScene->addItem(level88);

    level89 = new Button("LEVEL89");
    level89->setPos(40,290);
    stageSelectScene->addItem(level89);

    level90 = new Button("LEVEL90");
    level90->setPos(253,290);
    stageSelectScene->addItem(level90);

    level91 = new Button("LEVEL91");
    level91->setPos(467,290);
    stageSelectScene->addItem(level91);

    level92 = new Button("LEVEL92");
    level92->setPos(680,290);
    stageSelectScene->addItem(level92);

    level93 = new Button("LEVEL93");
    level93->setPos(40,430);
    stageSelectScene->addItem(level93);

    level94 = new Button("LEVEL94");
    level94->setPos(253,430);
    stageSelectScene->addItem(level94);

    level95 = new Button("LEVEL95");
    level95->setPos(467,430);
    stageSelectScene->addItem(level95);

    level96 = new Button("LEVEL96");
    level96->setPos(680,430);
    stageSelectScene->addItem(level96);
    show();
}
