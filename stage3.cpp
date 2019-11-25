#include "Stage3.h"

Stage3::Stage3(QWidget *parent)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

Stage3::~Stage3()
{
    delete stageSelectScene;
    delete back;
    delete home;
    delete level25;
    delete level26;
    delete level27;
    delete level28;
    delete level29;
    delete level30;
    delete level31;
    delete level32;
    delete level33;
    delete level34;
    delete level35;
    delete level36;
}

void Stage3::clear()
{
    delete back;
    delete home;
    delete level25;
    delete level26;
    delete level27;
    delete level28;
    delete level29;
    delete level30;
    delete level31;
    delete level32;
    delete level33;
    delete level34;
    delete level35;
    delete level36;
    delete stageSelectScene;
}

extern QString currentPlayerName;

void Stage3::display()
{
    clear();
    setWindowTitle(currentPlayerName);
    stageSelectScene = new QGraphicsScene();
    //SET SCENE SIZE
    stageSelectScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setWindowTitle(currentPlayerName+" STAGE 3");
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/level3select.png")));
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

    level25 = new Button("LEVEL25");
    level25->setPos(40,150);
    stageSelectScene->addItem(level25);

    level26 = new Button("LEVEL26");
    level26->setPos(253,150);
    stageSelectScene->addItem(level26);

    level27 = new Button("LEVEL27");
    level27->setPos(467,150);
    stageSelectScene->addItem(level27);

    level28 = new Button("LEVEL28");
    level28->setPos(680,150);
    stageSelectScene->addItem(level28);

    level29 = new Button("LEVEL29");
    level29->setPos(40,290);
    stageSelectScene->addItem(level29);

    level30 = new Button("LEVEL30");
    level30->setPos(253,290);
    stageSelectScene->addItem(level30);

    level31 = new Button("LEVEL31");
    level31->setPos(467,290);
    stageSelectScene->addItem(level31);

    level32 = new Button("LEVEL32");
    level32->setPos(680,290);
    stageSelectScene->addItem(level32);

    level33 = new Button("LEVEL33");
    level33->setPos(40,430);
    stageSelectScene->addItem(level33);

    level34 = new Button("LEVEL34");
    level34->setPos(253,430);
    stageSelectScene->addItem(level34);

    level35 = new Button("LEVEL35");
    level35->setPos(467,430);
    stageSelectScene->addItem(level35);

    level36 = new Button("LEVEL36");
    level36->setPos(680,430);
    stageSelectScene->addItem(level36);
    show();
}

