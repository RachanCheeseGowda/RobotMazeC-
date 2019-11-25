#ifndef HINT_H
#define HINT_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "text.h"
#include "button.h"

class Hint: public QGraphicsView{
public:
    Hint(QWidget * parent=0);
    ~Hint();

    QPointer<QGraphicsScene> HintScene;
    QVector<QPointer<Text>> title;
    QVector<QPointer<Text>> words;
    QVector<QPointer<Button>> image;
    QPointer<Button> next;


    void displayFrame();
    void clear();
    void convert_line(QString line);

    int x=0;
    int y=0;
    int count=0;
    void level1Hint();
    void level2Hint();
    void level10Hint();
    void level12Hint();
    void level13Hint();
    void level14Hint();
    void level25Hint();
    void level28Hint();
    void level39Hint();
    void level49Hint();
    void level54Hint();
    void level85Hint();
    void level100Hint();
    void end();
};
#endif // HINT_H
