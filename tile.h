#ifndef TILE_H
#define TILE_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Tile: public QObject{
    Q_OBJECT
public:
    Tile(int x,int y,int tileSize,int tileState);

    int getX();
    void setX(int i);
    int getY();
    void setY(int i);
    void check(QPoint q);
    int getTileState();
    void setTileState(int i);
private:
    int x;
    int y;
    int tileSize;
    int tileState;

};
#endif // TILE_H
