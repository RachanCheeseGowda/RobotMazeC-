#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Button(QString button_name);
    ~Button();
    void set_image();
    void set_selected_image();
    QString getButton_name() const;
    void setButton_name(const QString &value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QString button_name;
};
#endif // BUTTON_H
