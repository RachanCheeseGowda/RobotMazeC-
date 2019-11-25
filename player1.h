#ifndef PLAYER1_H
#define PLAYER1_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "robot.h"
#include "AlgorithmBlock.h"
#include "tile.h"
#include <QGraphicsPixmapItem>
#include <QVector>
#include "Timer.h"
#include "button.h"
#include "User.h"
#include <QPointer>
#include "Obstacle.h"

class player1: public QGraphicsView{
public:
    player1(QWidget * parent=0);
    ~player1();

    void setCursor(AlgorithmBlock *a);

    AlgorithmBlock* cursor;
    QGraphicsScene * scene;
    Robot * robot;
    QPointer<AlgorithmBlock>  algorithmBlock;
    QVector<QPointer<AlgorithmBlock>> sequence;
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


    void restart();
    void format(int initY);
    void clearEmptyMaze();
    int getLevelNo() const;
    void setLevelNo(int value);
    void createLevel(int i);

    void get_high_score(int i);

    int current_timer=0;
    int initialY;
    int tileSize;
    int initialTileX;
    int initialTileY;
    int noBlocks;
    int step;
    int level_height;

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

    void end();
    void initialize();
private:
    int levelNo;
};
#endif // PLAYER1_H
