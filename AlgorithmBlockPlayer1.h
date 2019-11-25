#ifndef ALGORITHMBLOCKPLAYER1_H
#define ALGORITHMBLOCKPLAYER1_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

class AlgorithmBlockPlayer1: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    AlgorithmBlockPlayer1();
    ~AlgorithmBlockPlayer1();
    AlgorithmBlockPlayer1(QString blockType,QString direction,int steps,int y);
    void setImage();

    //void keyPressEvent(QKeyEvent * event);

    void setDirection(QString s);
    void setSteps(int i);
    int getSteps();
    void setY(int i);
    int getY();
    QString getDirection();

    void setSelectedImage();
    int getStart();

    void setStart(int value);
    void setBlockType(QString s);

    QString getBlockType() const;
    bool newlyPlaced;
    int initY;
private:
    QString blockType;
    QString direction;
    int steps;
    int start;
    int y;
};
#endif // ALGORITHMBLOCKPLAYER1_H
