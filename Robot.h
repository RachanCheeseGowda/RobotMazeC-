#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include "algorithmblock.h"
#include "algorithmblockplayer1.h"
#include "algorithmblockplayer2.h"
#include "tile.h"
#include <QPointer>
#include "Obstacle.h"

class Robot:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Robot(QGraphicsItem * parent=0);
    ~Robot();
    QPointer<QTimer> timer;
    QPointer<QTimer> blockTimer;
    QPointer<QTimer> moveTimer;
    QPointer<QTimer> dance;
    QPointer<QTimer> delay;

    void startSequence(QVector<QPointer<AlgorithmBlock>> block,Tile *maze[14][14],QVector<QPointer<Obstacle>> obstacle);
    void stop();
    void setImage();
    void startDance();
    int danceFrame=0;
    int distance;
    int count=0;
    int index = 1;
    bool isJump=0;
    bool isBridge=0;
    bool bridgeMove=0;
    bool deployingBridge=0;
    int enteredPortal=0;
    bool on=1;
    int stepY=0;
    int stepX=0;
    int moveFrame=1;
    int x_offset=0;
    int skin=0;
    QMediaPlayer * moveSound;
    void startSequence1(QVector<QPointer<AlgorithmBlockPlayer1> > sequence, Tile *maze[14][14], QVector<QPointer<Obstacle> > obstacle);
    void startSequence2(QVector<QPointer<AlgorithmBlockPlayer2> > sequence, Tile *maze[14][14], QVector<QPointer<Obstacle> > obstacle);
public slots:
    void move(QVector<QPointer<AlgorithmBlock>> block,Tile *maze[14][14],QVector<QPointer<Obstacle>> obstacle);
    void move1(QVector<QPointer<AlgorithmBlockPlayer1>> block,Tile *maze[14][14],QVector<QPointer<Obstacle>> obstacle);
    void move2(QVector<QPointer<AlgorithmBlockPlayer2>> block,Tile *maze[14][14],QVector<QPointer<Obstacle>> obstacle);
    void indicateBlock(QVector<QPointer<AlgorithmBlock>> sequence);
    void animateMove();
    void celebrate();
    void finish(bool i);
};

#endif // PLAYER_H
