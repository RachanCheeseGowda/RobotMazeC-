#include "Hint.h"
#include <QFile>
#include <vector>
#include <cstring>
#include "button.h"
#include "text.h"
#include "Game.h"

Hint::Hint(QWidget *parent)
{

}

Hint::~Hint()
{
    delete HintScene;
    delete next;
}

void Hint::clear()
{
    title.clear();
    words.clear();
    image.clear();
    delete next;
}

void Hint::displayFrame()
{
    HintScene = new QGraphicsScene();
    //SET SCENE SIZE
    HintScene->setSceneRect(0,0,900,600);
    //SET BACKGROUND IMAGE
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Menu/hs.jpg")));
    setScene(HintScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //SET VIEW SIZE
    setFixedSize(900,600);
}

void Hint::level1Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 1";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }
    //Picture
    image.push_back(new Button("ALGORITHMBLOCK"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.7);
    HintScene->addItem(image[0]);
    image.push_back(new Button("START"));
    image[1]->setPos(100,400);
    image[1]->setScale(0.7);
    HintScene->addItem(image[1]);
    //Text
    line = "DRAG AND DROP THE";
    count=0;
    x=400;
    y=200;
    convert_line(line);
    line = "ALGORITHM BLOCKS INTO";
    x=400;
    y+=40;
    convert_line(line);
    line = "THE CORRECT SEQUENCE ";
    x=400;
    y+=40;
    convert_line(line);
    line = "TO MOVE YOUR ROBOT TO";
    x=400;
    y+=40;
    convert_line(line);
    line = "THE FINISH TILE";
    x=400;
    y+=40;
    convert_line(line);
    line = "HIT START TO EXECUTE";
    x=400;
    y+=70;
    convert_line(line);

    next = new Button("HINT1NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);    
    show();
}

void Hint::level2Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 2";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }
    //Picture
    image.push_back(new Button("GOLDMEDAL"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.4);
    HintScene->addItem(image[0]);
    image.push_back(new Button("SILVERMEDAL"));
    image[1]->setPos(100,300);
    image[1]->setScale(0.4);
    HintScene->addItem(image[1]);
    image.push_back(new Button("BRONZEMEDAL"));
    image[2]->setPos(100,400);
    image[2]->setScale(0.4);
    HintScene->addItem(image[2]);
    //Text
    line = "GET UNDER 30 SECONDS FOR";
    count=0;
    x=400;
    y=200;
    convert_line(line);
    line = "A GOLD MEDAL";
    x=400;
    y+=40;
    convert_line(line);
    line = "GET UNDER 60 SECONDS FOR";
    x=400;
    y+=70;
    convert_line(line);
    line = "A SILVER MEDAL";
    x=400;
    y+=40;
    convert_line(line);
    line = "OR SETTLE FOR BRONZE";
    x=400;
    y+=70;
    convert_line(line);

    next = new Button("HINT2NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level10Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 3";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }
    //Picture
    image.push_back(new Button("JUMP"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.7);
    HintScene->addItem(image[0]);
    //Text
    line = "THE JUMP BLOCK ";
    count=0;
    x=450;
    y=200;
    convert_line(line);
    line = "IS USED TO SKIP";
    x=450;
    y+=40;
    convert_line(line);
    line = "ONE TILE";
    x=450;
    y+=40;
    convert_line(line);
    line = "USE IT TO JUMP";
    x=450;
    y+=80;
    convert_line(line);
    line = "OVER THE GAPS";
    x=450;
    y+=40;
    convert_line(line);

    next = new Button("HINT10NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level12Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 4";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }
    image.push_back(new Button("JUMP"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.7);
    HintScene->addItem(image[0]);
    image.push_back(new Button("ALGORITHMBLOCK"));
    image[1]->setPos(100,260);
    image[1]->setScale(0.7);
    HintScene->addItem(image[1]);
    //Text
    line = "THERE ARE OFTEN MANY";
    count=0;
    x=400;
    y=200;
    convert_line(line);
    line = "SOLUTIONS TO ONE PROBLEM";
    x=400;
    y+=40;
    convert_line(line);
    line = "BE AS CREATIVE AS POSSIBLE";
    x=400;
    y+=80;
    convert_line(line);
    line = "YOU DO NOT NEED TO ";
    x=400;
    y+=80;
    convert_line(line);
    line = "USE ALL BLOCKS";
    x=400;
    y+=40;
    convert_line(line);

    next = new Button("HINT12NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level13Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 5";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    image.push_back(new Button("JUMP"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.7);
    HintScene->addItem(image[0]);

    //Text
    line = "JUMP CAN BE USED";
    count=0;
    x=450;
    y=200;
    convert_line(line);
    line = "AS A NORMAL BLOCK ";
    x=450;
    y+=40;
    convert_line(line);
    line = "TO MOVE 2 TILES";
    count=0;
    x=450;
    y=200;
    convert_line(line);

    next = new Button("HINT13NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level14Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 6";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    image.push_back(new Button("BRIDGEBLOCK"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.7);
    HintScene->addItem(image[0]);
    image.push_back(new Button("BRIDGE"));
    image[1]->setPos(100,300);
    image[1]->setScale(0.07);
    HintScene->addItem(image[1]);
    image.push_back(new Button("BRIDGE2"));
    image[2]->setPos(100,400);
    image[2]->setScale(0.07);
    HintScene->addItem(image[2]);

    //Text
    line = "THE BRIDGE BLOCK";
    count=0;
    x=400;
    y=200;
    convert_line(line);
    line = "IS USED TO NAVIGATE";
    x=400;
    y+=40;
    convert_line(line);
    line = "BRIDGES";
    x=400;
    y+=40;
    convert_line(line);
    line = "BRIDGE BLOCKS CAN";
    x=400;
    y+=80;
    convert_line(line);
    line = "ONLY BE USED WHEN";
    x=400;
    y+=40;
    convert_line(line);
    line = "NEXT TO A BRIDGE";
    x=400;
    y+=40;
    convert_line(line);

    next = new Button("HINT14NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level25Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 7";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    image.push_back(new Button("FIRE"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.3);
    HintScene->addItem(image[0]);

    //Text
    line = "FIRE IS DANGEROUS";
    count=0;
    x=400;
    y=200;
    convert_line(line);
    line = "BUTTONS CAN EXTINGUISH";
    x=400;
    y+=80;
    convert_line(line);
    line = "FIRE";
    x=400;
    y+=40;
    convert_line(line);

    next = new Button("HINT25NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level28Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 8";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    image.push_back(new Button("JUMP"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.7);
    HintScene->addItem(image[0]);

    //Text
    line = "YOU CAN JUMP OVER";
    count=0;
    x=400;
    y=200;
    convert_line(line);
    line = "FIRE AND VARIOUS";
    x=400;
    y+=40;
    convert_line(line);
    line = "OTHER OBSTACLES";
    x=400;
    y+=40;
    convert_line(line);
    line = "BUT DO NOT LAND ON";
    x=400;
    y+=80;
    convert_line(line);
    line = "A FIRE TILE";
    x=400;
    y+=40;
    convert_line(line);

    next = new Button("HINT28NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level39Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 9";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    image.push_back(new Button("PORTAL1"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.3);
    HintScene->addItem(image[0]);
    image.push_back(new Button("PORTAL1"));
    image[1]->setPos(100,300);
    image[1]->setScale(0.3);
    HintScene->addItem(image[1]);

    //Text
    line = "PORTALS ARE USED";
    count=0;
    x=450;
    y=200;
    convert_line(line);
    line = "TO TELEPORT OVER";
    x=450;
    y+=40;
    convert_line(line);
    line = "A DISTANCE";
    x=450;
    y+=40;
    convert_line(line);


    line = "PORTALS ARE LINKED";
    x=450;
    y+=80;
    convert_line(line);
    line = "BY COLOUR";
    x=450;
    y+=40;
    convert_line(line);

    next = new Button("HINT39NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level49Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 10";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    image.push_back(new Button("PORTAL1"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.3);
    HintScene->addItem(image[0]);
    image.push_back(new Button("PORTAL2"));
    image[1]->setPos(200,200);
    image[1]->setScale(0.3);
    HintScene->addItem(image[1]);

    //Text
    line = "PORTALS EACH LINK";
    count=0;
    x=400;
    y=200;
    convert_line(line);
    line = "BY COLOUR";
    x=400;
    y+=40;

    line = "BLUE GOES TO BLUE";
    x=400;
    y+=80;
    convert_line(line);
    line = "GREEN TO GREEN ETC";
    x=400;
    y+=40;
    convert_line(line);

    next = new Button("HINT49NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level54Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 11";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    image.push_back(new Button("PORTAL1"));
    image[0]->setPos(100,300);
    image[0]->setScale(0.3);
    HintScene->addItem(image[0]);
    image.push_back(new Button("PORTAL2"));
    image[1]->setPos(100,400);
    image[1]->setScale(0.3);
    HintScene->addItem(image[1]);

    image.push_back(new Button("ALGORITHMBLOCK"));
    image[2]->setPos(100,200);
    image[2]->setScale(0.7);
    HintScene->addItem(image[2]);

    //Text
    line = "PORTALS DO NOT ";
    count=0;
    x=400;
    y=200;
    convert_line(line);
    line = "INTERRUPT MOMENTUM";
    x=400;
    y+=40;
    convert_line(line);

    line = "THE ROBOT WILL CONTINUE";
    x=400;
    y+=80;
    convert_line(line);
    line = "THE REMAINING STEPS";
    x=400;
    y+=40;
    convert_line(line);
    line = "EVEN IF A PORTAL";
    x=400;
    y+=40;
    convert_line(line);
    line = "IS ENTERED";
    x=400;
    y+=40;
    convert_line(line);

    next = new Button("HINT54NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level85Hint()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "HINT 12";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    image.push_back(new Button("ALGORITHMBLOCK"));
    image[0]->setPos(100,200);
    image[0]->setScale(0.7);
    HintScene->addItem(image[0]);

    image.push_back(new Button("PORTAL1"));
    image[1]->setPos(100,300);
    image[1]->setScale(0.3);
    HintScene->addItem(image[1]);
    image.push_back(new Button("PORTAL1"));
    image[2]->setPos(100,400);
    image[2]->setScale(0.3);
    HintScene->addItem(image[2]);


    //Text
    line = "THE NEXT FEW LEVELS";
    count=0;
    x=400;
    y=200;
    convert_line(line);
    line = "WILL REQUIRE REPITITION";
    x=400;
    y+=40;
    convert_line(line);
    line = "OF CERTAIN STEPS TO";
    x=400;
    y+=40;
    convert_line(line);
    line = "SHORTEN THE DISTANCE";
    x=400;
    y+=40;
    convert_line(line);
    line = "THIS REPITION IS KNOWN";
    x=400;
    y+=80;
    convert_line(line);
    line = "AS RECURSION";
    x=400;
    y+=40;
    convert_line(line);

    next = new Button("HINT85NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::level100Hint()
{
    clear();
    displayFrame();
    x=120;
    y=50;
    count=0;
    //Title
    QString line = "PLAYER VS PLAYER";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    //Text
    line = "GRAB A FRIEND AND SEE WHO IS FASTER";
    count=0;
    x=20;
    y=200;
    convert_line(line);
    line = "W S AND UP DOWN  BUTTONS ARE USED TO SCROLL" ;
    x=20;
    y+=70;
    convert_line(line);
    line = "E AND SHIFT  BUTTONS  ARE USED TO SELECT" ;
    x=20;
    y+=50;
    convert_line(line);
    line = "SPACE AND KEYPAD 0  BUTTONS EXECUTE" ;
    x=20;
    y+=50;
    convert_line(line);

    next = new Button("HINT100NEXT");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::end()
{
    clear();
    displayFrame();
    x=350;
    y=50;
    count=0;
    //Title
    QString line = "THE END";
    for(int j=0;j<line.length();j++){
        title.push_back(new Text(line[j]));
        if(line[j].isDigit()){
            title[count]->setPos(x,y+2);
        }
        else{
            title[count]->setPos(x,y);
        }
        title[count]->setScale(0.7);
        if(line[count]=='I'){
            x +=20;
        }
        else{
            x +=40;
        }
        HintScene->addItem(title[count]);
        count++;
    }

    image.push_back(new Button("ROBOT1"));
    image[0]->setPos(50,200);
    image[0]->setScale(0.7);
    HintScene->addItem(image[0]);
    image.push_back(new Button("ROBOT2"));
    image[1]->setPos(200,200);
    image[1]->setScale(0.7);
    HintScene->addItem(image[1]);

    //Text
    line = "CONGRATULATIONS";
    count=0;
    x=450;
    y=200;
    convert_line(line);
    line = "YOU HELPED OUR LITTLE";
    x=450;
    y+=40;
    convert_line(line);
    line = "ROBOT REACH HIS FRIENDS";
    x=450;
    y+=40;
    convert_line(line);
    line = "MAKE SURE TO REPLAY TO";
    x=450;
    y+=75;
    convert_line(line);
    line = "GET A BETTER TIME";
    x=450;
    y+=40;
    convert_line(line);
    line = "SEE YOU SPACE ROBOT";
    x=450;
    y+=75;
    convert_line(line);

    next = new Button("HINTHOME");
    next->setPos(370,500);
    HintScene->addItem(next);
    show();
}

void Hint::convert_line(QString line)
{
    for(int k=0;k<line.length();k++){
        words.push_back(new Text(line[k]));
        if(line[k]=='A'){
            words[count]->setPos(x-2,y);
        }
        else{
            if(line[k].isDigit()){
                words[count]->setPos(x,y+2);
            }
            else{
                words[count]->setPos(x,y);
            }
        }
        words[count]->setScale(0.4);
        HintScene->addItem(words[count]);
        if(line[k]=='I'){
            x +=10;
        }
        else{
            x +=20;
        }
        count++;
    }
}
