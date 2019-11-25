#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "User.h"
#include <QPointer>
#include "text.h"
#include "button.h"

class HighScore: public QGraphicsView{
public:
    HighScore(QWidget * parent=0);
    ~HighScore();

    QPointer<QGraphicsScene> HighScoreScene;
    QVector<User *> users;
    QVector<QPointer<Text>> level_header;
    QVector<QPointer<Text>> names;
    QVector<QPointer<Text>> scores;
    QVector<QPointer<Button>> medals;
    QPointer<Button> next;
    QPointer<Button> home;

    void display_high_score();
    void display_high_score(int i);
    void clear();
    void display_high_score(int i, int winner);
};

#endif // HIGHSCORE_H
