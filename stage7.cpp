#include "Stage7.h"

Stage7::Stage7(QWidget *parent)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

Stage7::~Stage7()
{
    delete back;
    delete home;
    delete level73;
    delete level74;
    delete level75;
    delete level76;
    delete level77;
    delete level78;
    delete level79;
    delete level80;
    delete level81;
    delete level82;
    delete level83;
    delete level84;
    delete stageSelectScene;
}

void Stage7::clear()
{
    delete back;
    delete home;
    delete level73;
    delete level74;
    delete level75;
    delete level76;
    delete level77;
    delete level78;
    delete level79;
    delete level80;
    delete level81;
    delete level82;
    delete level83;
    delete level84;
    delete stageSelectScene;
}

extern QString currentPlayerName;

void Stage7::display()
{
    clear();
    setWindowTitle(currentPlayerName);
    stageSelectScene = new QGraphicsScene();
    //SET SCENE SIZE
    stageSelectScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setWindowTitle(currentPlayerName+" STAGE 2");
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/level7select.png")));
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

    level73 = new Button("LEVEL73");
    level73->setPos(40,150);
    stageSelectScene->addItem(level73);

    level74 = new Button("LEVEL74");
    level74->setPos(253,150);
    stageSelectScene->addItem(level74);

    level75 = new Button("LEVEL75");
    level75->setPos(467,150);
    stageSelectScene->addItem(level75);

    level76 = new Button("LEVEL76");
    level76->setPos(680,150);
    stageSelectScene->addItem(level76);

    level77 = new Button("LEVEL77");
    level77->setPos(40,290);
    stageSelectScene->addItem(level77);

    level78 = new Button("LEVEL78");
    level78->setPos(253,290);
    stageSelectScene->addItem(level78);

    level79 = new Button("LEVEL79");
    level79->setPos(467,290);
    stageSelectScene->addItem(level79);

    level80 = new Button("LEVEL80");
    level80->setPos(680,290);
    stageSelectScene->addItem(level80);

    level81 = new Button("LEVEL81");
    level81->setPos(40,430);
    stageSelectScene->addItem(level81);

    level82 = new Button("LEVEL82");
    level82->setPos(253,430);
    stageSelectScene->addItem(level82);

    level83 = new Button("LEVEL83");
    level83->setPos(467,430);
    stageSelectScene->addItem(level83);

    level84 = new Button("LEVEL84");
    level84->setPos(680,430);
    stageSelectScene->addItem(level84);
    show();
}
