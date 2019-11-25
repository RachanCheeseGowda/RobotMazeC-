#include "Stage5.h"

Stage5::Stage5(QWidget *parent)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

Stage5::~Stage5()
{
    delete stageSelectScene;
    delete back;
    delete home;
    delete level49;
    delete level50;
    delete level51;
    delete level52;
    delete level53;
    delete level54;
    delete level55;
    delete level56;
    delete level57;
    delete level58;
    delete level59;
    delete level60;
}

void Stage5::clear()
{
    delete back;
    delete home;
    delete level49;
    delete level50;
    delete level51;
    delete level52;
    delete level53;
    delete level54;
    delete level55;
    delete level56;
    delete level57;
    delete level58;
    delete level59;
    delete level60;
    delete stageSelectScene;
}

extern QString currentPlayerName;

void Stage5::display()
{
    clear();
    setWindowTitle(currentPlayerName);
    stageSelectScene = new QGraphicsScene();
    //SET SCENE SIZE
    stageSelectScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setWindowTitle(currentPlayerName+" STAGE 5");
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/level5select.png")));
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

    level49 = new Button("LEVEL49");
    level49->setPos(40,150);
    stageSelectScene->addItem(level49);

    level50 = new Button("LEVEL50");
    level50->setPos(253,150);
    stageSelectScene->addItem(level50);

    level51 = new Button("LEVEL51");
    level51->setPos(467,150);
    stageSelectScene->addItem(level51);

    level52 = new Button("LEVEL52");
    level52->setPos(680,150);
    stageSelectScene->addItem(level52);

    level53 = new Button("LEVEL53");
    level53->setPos(40,290);
    stageSelectScene->addItem(level53);

    level54 = new Button("LEVEL54");
    level54->setPos(253,290);
    stageSelectScene->addItem(level54);

    level55 = new Button("LEVEL55");
    level55->setPos(467,290);
    stageSelectScene->addItem(level55);

    level56 = new Button("LEVEL56");
    level56->setPos(680,290);
    stageSelectScene->addItem(level56);

    level57 = new Button("LEVEL57");
    level57->setPos(40,430);
    stageSelectScene->addItem(level57);

    level58 = new Button("LEVEL58");
    level58->setPos(253,430);
    stageSelectScene->addItem(level58);

    level59 = new Button("LEVEL59");
    level59->setPos(467,430);
    stageSelectScene->addItem(level59);

    level60 = new Button("LEVEL60");
    level60->setPos(680,430);
    stageSelectScene->addItem(level60);
    show();
}
