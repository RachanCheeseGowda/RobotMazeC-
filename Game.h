#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "robot.h"
#include "AlgorithmBlock.h"
#include "AlgorithmBlockPlayer1.h"
#include "AlgorithmBlockPlayer2.h"
#include "tile.h"
#include <QGraphicsPixmapItem>
#include <QVector>
#include "Timer.h"
#include "button.h"
#include "User.h"
#include <QPointer>
#include "Obstacle.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    ~Game();

    void setCursor(AlgorithmBlock *a);
    void mouseMoveEvent(QMouseEvent *event);

    AlgorithmBlock* cursor;
    QGraphicsScene * scene;
    Robot * robot;
    Robot * robot2;
    QPointer<AlgorithmBlock>  algorithmBlock;
    QVector<QPointer<AlgorithmBlock>> sequence;
    QVector<QPointer<AlgorithmBlockPlayer1>> sequence1;
    QVector<QPointer<AlgorithmBlockPlayer2>> sequence2;
    QVector<QPointer<AlgorithmBlock>> sequence_copy;
    QVector<QPointer<Obstacle>> obstacle;
    Tile *maze[14][14];
    Timer *timer;
    Button *back;
    Button *home;
    Button *volume;
    User *user;

    void finish(bool gameOver);
    void startGame();
    void clearMP();

    void restart();
    void format(int initY);
    void clearEmptyMaze();
    int getLevelNo() const;
    void setLevelNo(int value);
    void createLevel(int i);

    void get_high_score(int i);
    void keyPressEvent(QKeyEvent * event);


    int current_timer=0;
    int initialY;
    int tileSize;
    int initialTileX;
    int initialTileY;
    int noBlocks;
    int step;
    int level_height;

    int currentlySelected=1;
    int currentlySelected2=1;
    int index1=1;
    int index2=1;
    bool player1ingame=0;
    bool player2ingame=0;
    int winner;

    void level1();
    void level2();
    void level3();
    void level4();
    void level5();
    void level6();
    void level7();
    void level8();
    void level9();
    void level10();
    void level11();
    void level12();

    void level13();
    void level14();
    void level15();
    void level16();
    void level17();
    void level18();
    void level19();
    void level20();
    void level21();
    void level22();
    void level23();
    void level24();

    void level25();
    void level26();
    void level27();
    void level28();
    void level29();
    void level30();
    void level31();
    void level32();
    void level33();
    void level34();
    void level35();
    void level36();

    void level37();
    void level38();
    void level39();
    void level40();
    void level41();
    void level42();
    void level43();
    void level44();
    void level45();
    void level46();
    void level47();
    void level48();

    void level49();
    void level50();
    void level51();
    void level52();
    void level53();
    void level54();
    void level55();
    void level56();
    void level57();
    void level58();
    void level59();
    void level60();

    void level61();
    void level62();
    void level63();
    void level64();
    void level65();
    void level66();
    void level67();
    void level68();
    void level69();
    void level70();
    void level71();
    void level72();

    void level73();
    void level74();
    void level75();
    void level76();
    void level77();
    void level78();
    void level79();
    void level80();
    void level81();
    void level82();
    void level83();
    void level84();

    void level85();
    void level86();
    void level87();
    void level88();
    void level89();
    void level90();
    void level91();
    void level92();
    void level93();
    void level94();
    void level95();
    void level96();


    void level100();

    void drawMulitplayer();
    void drawMulitplayer2();
    void end();
    void initialize();
    void startMulitplayerGame1();
    void startMulitplayerGame2();
    void level101();
    void level102();
private:
    int levelNo;
};
#endif // GAME_H
