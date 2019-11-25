#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QPointer>

class Obstacle: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Obstacle(int obstacle_type, int x, int y);
    ~Obstacle();
    void set_image();
    int getObstacle_type() const;
    void setObstacle_type(const int &value);

    void animateBridge(int i);
    void startFire();

    void stopFire();
    void toggleButton();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    QPointer<QTimer> fire;
public slots:
    void animateFire();
private:
    int angle=0;
    int fire_frame=0;
    int obstacle_type;
    int x;
    int y;
};
#endif // OBSTACLE_H
