#include "HighScore.h"
#include <QFile>
#include <vector>
#include <cstring>
#include "User.h"
#include "button.h"
#include "text.h"

HighScore::HighScore(QWidget *parent)
{

}

HighScore::~HighScore()
{
    delete HighScoreScene;
    delete next;
    delete home;
}

void HighScore::clear()
{
    users.clear();
    level_header.clear();
    names.clear();
    scores.clear();
    medals.clear();
    delete next;
    delete home;
}

void HighScore::display_high_score()
{
    clear();
    qDebug()<<"uh";
    QString user_path = "Users.txt";
    QFile file(user_path);
    QString s= "";
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
           s = in.readLine();
           users.push_back(new User(s));
       }
       file.close();
    }
    //fills in the vector
    for(User* b:users){
        qDebug()<<b->getUsername();
        b->read_user_level();
    }
    //Get highscore for each level where i is the level no
    for(int i=0;i<6;i++){
        for(User* b:users){
            if(b->user_score[i]!=0){
                qDebug()<<b->getUsername()<< "took "<<b->user_score[i]<<"seconds on level "<<i;
            }
        }
    }


    //display
    setWindowTitle("HIGH SCORES");
    HighScoreScene = new QGraphicsScene();
    //SET SCENE SIZE
    //SET BACKGROUND IMAGE
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/hs.jpg")));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //SET VIEW SIZE
    //setFixedSize(500,600);



    QString line="";
    int x = 10;
    int y = 0;
    int count=0;
    int count1=0;
    int count2=0;
    int count3=0;
    for(int i=1;i<=96;i++){
        line = "LEVEL "+QString::number(i);
        x=145;
        y+=40;
        for(int j=0;j<line.length();j++){
            level_header.push_back(new Text(line[j]));
            if(line[j].isDigit()){
                level_header[count]->setPos(x,y+2);
            }
            else{
                level_header[count]->setPos(x,y);
            }
            level_header[count]->setScale(0.5);
            HighScoreScene->addItem(level_header[count]);
            x +=35;
            count++;
        }

        //insertion sort
        User* key;
        for(int j=0;j<=users.size()-1;j++){
            key = users[j];
            int k=j-1;
            while (k >= 0 && users[k]->user_score[i] > key->user_score[i]) {
                  users[k+1]=users[k];
                  k = k - 1;
            }
            users[k+1] = key;
        }

        //x=40;
        y+=50;
        line = "";
        QString time;
        for(User* b:users){
            if(b->user_score[i]!=0){
                line = b->getUsername();
                time = QString::number(b->user_score[i])+"s";
                if(b->user_score[i]<30){
                    medals.push_back(new Button("GOLDMEDAL"));
                }
                if(b->user_score[i]>=30&&b->user_score[i]<60){
                    medals.push_back(new Button("SILVERMEDAL"));
                }
                if(b->user_score[i]>=60){
                    medals.push_back(new Button("BRONZEMEDAL"));
                }

                //x+=5;
                x=40;
                for(int k=0;k<line.length();k++){
                    names.push_back(new Text(line[k]));
                    if(line[k]=='A'){
                        names[count1]->setPos(x-2,y);
                    }
                    else{
                        if(line[k].isDigit()){
                            names[count1]->setPos(x,y+2);
                        }
                        else{
                            names[count1]->setPos(x,y);
                        }
                    }
                    names[count1]->setScale(0.4);
                    HighScoreScene->addItem(names[count1]);
                    if(line[k]=='I'){
                        x +=10;
                    }
                    else{
                        x +=20;
                    }
                    count1++;
                }
                x=420;
                medals[count3]->setScale(0.19);
                medals[count3]->setPos(440,y-10);
                HighScoreScene->addItem(medals[count3]);
                count3++;
                for(int k=time.length()-1;k>=0;k--){
                    scores.push_back(new Text(time[k]));
                    scores[count2]->setPos(x,y+2);
                    scores[count2]->setScale(0.4);
                    HighScoreScene->addItem(scores[count2]);
                    x -=20;
                    count2++;
                }
                x=5;
                y+=50;
            }
        }
    }
    HighScoreScene->setSceneRect(HighScoreScene->itemsBoundingRect());
    qDebug()<<HighScoreScene->height()<<HighScoreScene->width();
    qDebug()<<HighScoreScene->itemsBoundingRect().height();
    setScene(HighScoreScene);
    HighScoreScene->setSceneRect(0,0,500,HighScoreScene->itemsBoundingRect().height()+150);

    home = new Button("HSHOME");
    home->setPos(180,HighScoreScene->itemsBoundingRect().height()+50);
    HighScoreScene->addItem(home);

    qDebug()<<count1<<count2;
    show();
}

void HighScore::display_high_score(int i)
{
    //read from text file
    clear();
    qDebug()<<"uh";
    QString user_path = "Users.txt";
    QFile file(user_path);
    QString s= "";
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
           s = in.readLine();
           users.push_back(new User(s));
       }
       file.close();
    }
    //fills in the vector
    for(User* b:users){
        qDebug()<<b->getUsername();
        b->read_user_level();
    }
    //Get highscore for selected level
    for(User* b:users){
        if(b->user_score[i]!=0){
            qDebug()<<b->getUsername()<< "took "<<b->user_score[i]<<"seconds";
        }
    }

    //display
    setWindowTitle("HIGH SCORES");
    HighScoreScene = new QGraphicsScene();
    //SET SCENE SIZE
    //SET BACKGROUND IMAGE
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/hs.jpg")));
    //setWindowFlags(Qt::Window| Qt::FramelessWindowHint);
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //SET VIEW SIZE
    //setFixedSize(500,600);

    QString line="";
    int x = 5;
    int y = 0;
    int count=0;
    int count1=0;
    int count2=0;
    int count3=0;
    line = "LEVEL "+QString::number(i);
    x=140;
    y+=40;
    for(int j=0;j<line.length();j++){
        level_header.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            level_header[count]->setPos(x,y+2);
        }
        else{
            level_header[count]->setPos(x,y);
        }
        level_header[count]->setScale(0.5);
        HighScoreScene->addItem(level_header[count]);
        x +=35;
        count++;
    }
    //insertion sort
    User* key;
    for(int j=0;j<=users.size()-1;j++){
        key = users[j];
        int k=j-1;
        while (k >= 0 && users[k]->user_score[i] > key->user_score[i]) {
              users[k+1]=users[k];
              k = k - 1;
        }
        users[k+1] = key;
    }

    x=5;
    y+=50;
    line = "";
    QString time;
    for(User *b:users){
        if(b->user_score[i]!=0){
            line = b->getUsername();
            time = QString::number(b->user_score[i])+"s";
            if(b->user_score[i]<30){
                medals.push_back(new Button("GOLDMEDAL"));
            }
            if(b->user_score[i]>=30&&b->user_score[i]<60){
                medals.push_back(new Button("SILVERMEDAL"));
            }
            if(b->user_score[i]>=60){
                medals.push_back(new Button("BRONZEMEDAL"));
            }

            //x+=5;
            x=40;
            for(int k=0;k<line.length();k++){
                names.push_back(new Text(line[k]));
                if(line[k]=='A'){
                    names[count1]->setPos(x-2,y);
                }
                else{
                    if(line[k].isDigit()){
                        names[count1]->setPos(x,y+2);
                    }
                    else{
                        names[count1]->setPos(x,y);
                    }
                }
                names[count1]->setScale(0.4);
                HighScoreScene->addItem(names[count1]);
                if(line[k]=='I'){
                    x +=10;
                }
                else{
                    x +=20;
                }
                count1++;
            }
            x=420;
            medals[count3]->setScale(0.19);
            medals[count3]->setPos(440,y-10);
            HighScoreScene->addItem(medals[count3]);
            count3++;
            for(int k=time.length()-1;k>=0;k--){
                scores.push_back(new Text(time[k]));
                scores[count2]->setPos(x,y+2);
                scores[count2]->setScale(0.4);
                HighScoreScene->addItem(scores[count2]);
                x -=20;
                count2++;
            }
            x=5;
            y+=50;
        }
    }

    if(HighScoreScene->itemsBoundingRect().height()<300){
        HighScoreScene->setSceneRect(0,0,500,500);
        setScene(HighScoreScene);

        home = new Button("LHSHOME");
        home->setPos(75,400);
        HighScoreScene->addItem(home);

        next = new Button("NEXT");
        next->setPos(275,400);
        HighScoreScene->addItem(next);
    }
    else{
        HighScoreScene->setSceneRect(HighScoreScene->itemsBoundingRect());
        qDebug()<<HighScoreScene->height()<<HighScoreScene->width();
        qDebug()<<HighScoreScene->itemsBoundingRect().height();
        setScene(HighScoreScene);
        HighScoreScene->setSceneRect(0,0,500,HighScoreScene->itemsBoundingRect().height()+150);

        home = new Button("LHSHOME");
        home->setPos(75,HighScoreScene->itemsBoundingRect().height()+50);
        HighScoreScene->addItem(home);

        next = new Button("NEXT");
        next->setPos(275,home->y());
        qDebug()<<next->pos();
        HighScoreScene->addItem(next);
    }
    show();
}

void HighScore::display_high_score(int i,int winner)
{
    clear();
    //display
    setWindowTitle("HIGH SCORES");
    HighScoreScene = new QGraphicsScene();
    //SET SCENE SIZE
    //SET BACKGROUND IMAGE
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/hs.jpg")));
    //setWindowFlags(Qt::Window| Qt::FramelessWindowHint);
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //SET VIEW SIZE
    //setFixedSize(500,600);

    QString line="";
    int x = 5;
    int y = 0;
    int count=0;
    int count1=0;
    int count2=0;
    int count3=0;
    line = "MULTIPLAYER";
    x=75;
    y+=60;
    for(int j=0;j<line.length();j++){
        level_header.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            level_header[count]->setPos(x,y+2);
        }
        else{
            level_header[count]->setPos(x,y);
        }
        level_header[count]->setScale(0.5);
        HighScoreScene->addItem(level_header[count]);
        x +=35;
        count++;
    }
    line = "LEVEL "+QString::number(i-99);
    x=125;
    y+=40;
    for(int j=0;j<line.length();j++){
        level_header.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            level_header[count]->setPos(x,y+2);
        }
        else{
            level_header[count]->setPos(x,y);
        }
        level_header[count]->setScale(0.5);
        HighScoreScene->addItem(level_header[count]);
        x +=35;
        count++;
    }
    line = "PLAYER "+QString::number(winner)+" WINS";
    x=110;
    y+=70;
    count=0;
    for(int k=0;k<line.length();k++){
        names.push_back(new Text(line[k]));
        if(line[k]=='A'){
            names[count]->setPos(x-2,y);
        }
        else{
            if(line[k].isDigit()){
                names[count]->setPos(x,y+2);
            }
            else{
                names[count]->setPos(x,y);
            }
        }
        names[count]->setScale(0.4);
        if(line[k]=='I'){
            x +=10;
        }
        else{
            x +=20;
        }
        HighScoreScene->addItem(names[count]);
        count++;
    }
    if(HighScoreScene->itemsBoundingRect().height()<300){
        HighScoreScene->setSceneRect(0,0,500,500);
        setScene(HighScoreScene);

        home = new Button("LHSHOME");
        home->setPos(75,400);
        HighScoreScene->addItem(home);

        next = new Button("NEXT");
        next->setPos(275,400);
        HighScoreScene->addItem(next);
    }
    else{
        HighScoreScene->setSceneRect(HighScoreScene->itemsBoundingRect());
        qDebug()<<HighScoreScene->height()<<HighScoreScene->width();
        qDebug()<<HighScoreScene->itemsBoundingRect().height();
        setScene(HighScoreScene);
        HighScoreScene->setSceneRect(0,0,500,HighScoreScene->itemsBoundingRect().height()+150);

        home = new Button("LHSHOME");
        home->setPos(75,HighScoreScene->itemsBoundingRect().height()+50);
        HighScoreScene->addItem(home);

        next = new Button("NEXT");
        next->setPos(275,home->y());
        qDebug()<<next->pos();
        HighScoreScene->addItem(next);
    }
    show();
}
