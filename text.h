#ifndef TEXT_H
#define TEXT_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Text: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Text(QChar c);
    ~Text();
    void set_image(QChar c);
    void set_black_digit(QChar c);
    QChar c;
};
#endif // TEXT_H
