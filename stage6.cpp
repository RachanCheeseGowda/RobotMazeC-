#include "Stage6.h"

Stage6::Stage6(QWidget *parent)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

Stage6::~Stage6()
{
    delete stageSelectScene;
    delete back;
    delete home;
    delete level61;
    delete level62;
    delete level63;
    delete level64;
    delete level65;
    delete level66;
    delete level67;
    delete level68;
    delete level69;
    delete level70;
    delete level71;
    delete level72;
}

void Stage6::clear()
{
    delete back;
    delete home;
    delete level61;
    delete level62;
    delete level63;
    delete level64;
    delete level65;
    delete level66;
    delete level67;
    delete level68;
    delete level69;
    delete level70;
    delete level71;
    delete level72;
    delete stageSelectScene;
}

extern QString currentPlayerName;

void Stage6::display()
{
    clear();
    setWindowTitle(currentPlayerName);
    stageSelectScene = new QGraphicsScene();
    //SET SCENE SIZE
    stageSelectScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setWindowTitle(currentPlayerName+" STAGE 6");
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/level6select.png")));
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

    level61 = new Button("LEVEL61");
    level61->setPos(40,150);
    stageSelectScene->addItem(level61);

    level62 = new Button("LEVEL62");
    level62->setPos(253,150);
    stageSelectScene->addItem(level62);

    level63 = new Button("LEVEL63");
    level63->setPos(467,150);
    stageSelectScene->addItem(level63);

    level64 = new Button("LEVEL64");
    level64->setPos(680,150);
    stageSelectScene->addItem(level64);

    level65 = new Button("LEVEL65");
    level65->setPos(40,290);
    stageSelectScene->addItem(level65);

    level66 = new Button("LEVEL66");
    level66->setPos(253,290);
    stageSelectScene->addItem(level66);

    level67 = new Button("LEVEL67");
    level67->setPos(467,290);
    stageSelectScene->addItem(level67);

    level68 = new Button("LEVEL68");
    level68->setPos(680,290);
    stageSelectScene->addItem(level68);

    level69 = new Button("LEVEL69");
    level69->setPos(40,430);
    stageSelectScene->addItem(level69);

    level70 = new Button("LEVEL70");
    level70->setPos(253,430);
    stageSelectScene->addItem(level70);

    level71 = new Button("LEVEL71");
    level71->setPos(467,430);
    stageSelectScene->addItem(level71);

    level72 = new Button("LEVEL72");
    level72->setPos(680,430);
    stageSelectScene->addItem(level72);
    show();
}
