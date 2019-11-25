#ifndef ALGORITHMBLOCK_H
#define ALGORITHMBLOCK_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

class AlgorithmBlock: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    AlgorithmBlock();
    ~AlgorithmBlock();
    AlgorithmBlock(QString blockType,QString direction,int steps,int y);
    void setImage();

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


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
#endif // ALGORITHMBLOCK_H
