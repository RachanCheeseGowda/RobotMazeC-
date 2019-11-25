#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>
#include <QDebug>
#include "mainwindow.h"
#include "Timer.h"
#include "User.h"
#include "HighScore.h"
#include "hint.h"
#include <QKeyEvent>

extern MainWindow *mainWindow;
extern QString currentPlayerName;
extern int currentLevel;
extern HighScore *high_score;
extern Hint *hintScreen;
bool hintShown;

Game::Game(QWidget *parent): QGraphicsView(){
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

Game::~Game()
{
    delete cursor;
    delete scene;
    delete robot;
    delete algorithmBlock;
    delete maze[14][14];
    delete timer;
    delete back;
    delete home;
    delete volume;
    delete user;


}


//SETS ALL VALUES IN THE MAZE TO BE 0 (VOID)
void Game::clearEmptyMaze(){
    //CALCULATED AS: INITIAL_BLOCK_POSITION - 2*TILESIZE
    initialTileX=106;
    initialTileY=-94;

    for(int i=0;i<14;i++){
        for(int j=0; j<14;j++){
            maze[i][j]=new Tile(initialTileX+(j)*tileSize,initialTileY+(i)*tileSize,tileSize,0);
        }
    }
}

int Game::getLevelNo() const
{
    return levelNo;
}


void Game::setLevelNo(int value)
{
    levelNo = value;
}

void Game::initialize(){
    qDebug()<<currentPlayerName<<currentLevel;
    delete robot;
    for(QPointer<Obstacle> b:obstacle){
        b->stopFire();
    }
    sequence.clear();
    obstacle.clear();
    delete back;
    delete home;
    delete volume;

    qDebug()<<currentPlayerName<<"HINT SHOWN"<<hintShown;
    user = new User(currentPlayerName);
}

void Game::clearMP(){
    sequence1.clear();
    sequence2.clear();
    delete robot2;
    delete robot;
    delete home;
    delete volume;
}

void Game::createLevel(int i){
    if(getLevelNo()!=i){
        current_timer=0;
    }

    if(i==1&&hintShown!=true){
        hintScreen->level1Hint();
    }
    else if(i==1&&hintShown==true){
        setLevelNo(1);
        level1();
    }
    if(i==2&&hintShown!=true){
        hintScreen->level2Hint();
        hintShown=true;
    }
    else if(i==2&&hintShown==true){
        setLevelNo(2);
        level2();
    }
    if(i==3){
        setLevelNo(3);
        level3();
    }
    if(i==4){
        setLevelNo(4);
        level4();
    }
    if(i==5){
        setLevelNo(5);
        level5();
    }
    if(i==6){
        setLevelNo(6);
        level6();
    }
    if(i==7){
        setLevelNo(7);
        level7();
    }
    if(i==8){
        setLevelNo(8);
        level8();
    }
    if(i==9){
        setLevelNo(9);
        level9();
    }
    if(i==10&&hintShown!=true){
        hintScreen->level10Hint();
        hintShown=true;
    }
    else if(i==10&&hintShown==true){
        setLevelNo(10);
        level10();
    }
    if(i==11){
        setLevelNo(11);
        level11();
    }
    if(i==12&&hintShown!=true){
        hintScreen->level12Hint();
        hintShown=true;
    }
    else if(i==12&&hintShown==true){
        setLevelNo(12);
        level12();
    }
    if(i==13&&hintShown!=true){
        hintScreen->level13Hint();
        hintShown=true;
    }
    else if(i==13&&hintShown==true){
        setLevelNo(13);
        level13();
    }
    if(i==14){
        setLevelNo(14);
        level14();
    }
    if(i==15){
        setLevelNo(15);
        level15();
    }    
    if(i==16&&hintShown!=true){
        hintScreen->level14Hint();
        hintShown=true;
    }
    else if(i==16&&hintShown==true){
        setLevelNo(16);
        level16();
    }
    if(i==17){
        setLevelNo(17);
        level17();
    }
    if(i==18){
        setLevelNo(18);
        level18();
    }
    if(i==19){
        setLevelNo(19);
        level19();
    }
    if(i==20){
        setLevelNo(20);
        level20();
    }
    if(i==21){
        setLevelNo(21);
        level21();
    }
    if(i==22){
        setLevelNo(22);
        level22();
    }
    if(i==23){
        setLevelNo(23);
        level23();
    }
    if(i==24){
        setLevelNo(24);
        level24();
    }
    if(i==25&&hintShown!=true){
        hintScreen->level25Hint();
        hintShown=true;
    }
    else if(i==25&&hintShown==true){
        setLevelNo(25);
        level25();
    }
    if(i==26){
        setLevelNo(26);
        level26();
    }
    if(i==27){
        setLevelNo(27);
        level27();
    }
    if(i==28&&hintShown!=true){
        hintScreen->level28Hint();
        hintShown=true;
    }
    else if(i==28&&hintShown==true){
        setLevelNo(28);
        level28();
    }
    if(i==29){
        setLevelNo(29);
        level29();
    }
    if(i==30){
        setLevelNo(30);
        level30();
    }
    if(i==31){
        setLevelNo(31);
        level31();
    }
    if(i==32){
        setLevelNo(32);
        level32();
    }
    if(i==33){
        setLevelNo(33);
        level33();
    }
    if(i==34){
        setLevelNo(34);
        level34();
    }
    if(i==35){
        setLevelNo(35);
        level35();
    }
    if(i==36){
        setLevelNo(36);
        level36();
    }
    if(i==37){
        setLevelNo(37);
        level37();
    }
    if(i==38){
        setLevelNo(38);
        level38();
    }
    if(i==39&&hintShown!=true){
        hintScreen->level39Hint();
        hintShown=true;
    }
    else if(i==39&&hintShown==true){
        setLevelNo(39);
        level39();
    }
    if(i==40){
        setLevelNo(40);
        level40();
    }
    if(i==41){
        setLevelNo(41);
        level41();
    }
    if(i==42){
        setLevelNo(42);
        level42();
    }
    if(i==43){
        setLevelNo(43);
        level43();
    }
    if(i==44){
        setLevelNo(44);
        level44();
    }
    if(i==45){
        setLevelNo(45);
        level45();
    }
    if(i==46){
        setLevelNo(46);
        level46();
    }
    if(i==47){
        setLevelNo(47);
        level47();
    }
    if(i==48){
        setLevelNo(48);
        level48();
    }
    if(i==49&&hintShown!=true){
        hintScreen->level49Hint();
        hintShown=true;
    }
    else if(i==49&&hintShown==true){
        setLevelNo(49);
        level49();
    }
    if(i==50){
        setLevelNo(50);
        level50();
    }
    if(i==51){
        setLevelNo(51);
        level51();
    }
    if(i==52){
        setLevelNo(52);
        level52();
    }
    if(i==53){
        setLevelNo(53);
        level53();
    }
    if(i==54&&hintShown!=true){
        hintScreen->level54Hint();
        hintShown=true;
    }
    else if(i==54&&hintShown==true){
        setLevelNo(54);
        level54();
    }
    if(i==55){
        setLevelNo(54);
        level55();
    }
    if(i==56){
        setLevelNo(56);
        level56();
    }
    if(i==57){
        setLevelNo(57);
        level57();
    }
    if(i==58){
        setLevelNo(58);
        level58();
    }
    if(i==59){
        setLevelNo(59);
        level59();
    }
    if(i==60){
        setLevelNo(60);
        level60();
    }
    if(i==61){
        setLevelNo(61);
        level61();
    }
    if(i==62){
        setLevelNo(62);
        level62();
    }
    if(i==63){
        setLevelNo(63);
        level63();
    }
    if(i==64){
        setLevelNo(64);
        level64();
    }
    if(i==65){
        setLevelNo(65);
        level65();
    }
    if(i==66){
        setLevelNo(66);
        level66();
    }
    if(i==67){
        setLevelNo(67);
        level67();
    }
    if(i==68){
        setLevelNo(68);
        level68();
    }
    if(i==69){
        setLevelNo(69);
        level69();
    }
    if(i==70){
        setLevelNo(70);
        level70();
    }
    if(i==71){
        setLevelNo(71);
        level71();
    }
    if(i==72){
        setLevelNo(72);
        level72();
    }
    if(i==73){
        setLevelNo(73);
        level73();
    }
    if(i==74){
        setLevelNo(74);
        level74();
    }
    if(i==75){
        setLevelNo(75);
        level75();
    }
    if(i==76){
        setLevelNo(76);
        level76();
    }
    if(i==77){
        setLevelNo(77);
        level77();
    }
    if(i==78){
        setLevelNo(78);
        level78();
    }
    if(i==79){
        setLevelNo(79);
        level79();
    }
    if(i==80){
        setLevelNo(80);
        level80();
    }
    if(i==81){
        setLevelNo(81);
        level81();
    }
    if(i==82){
        setLevelNo(82);
        level82();
    }
    if(i==83){
        setLevelNo(83);
        level83();
    }
    if(i==84){
        setLevelNo(84);
        level84();
    }
    if(i==85&&hintShown!=true){
        hintScreen->level85Hint();
        hintShown=true;
    }
    else if(i==85&&hintShown==true){
        setLevelNo(85);
        level85();
    }
    if(i==86){
        setLevelNo(86);
        level86();
    }
    if(i==87){
        setLevelNo(87);
        level87();
    }
    if(i==88){
        setLevelNo(88);
        level88();
    }
    if(i==89){
        setLevelNo(89);
        level89();
    }
    if(i==90){
        setLevelNo(90);
        level90();
    }
    if(i==91){
        setLevelNo(91);
        level91();
    }
    if(i==92){
        setLevelNo(92);
        level92();
    }
    if(i==93){
        setLevelNo(93);
        level93();
    }
    if(i==94){
        setLevelNo(94);
        level94();
    }
    if(i==95){
        setLevelNo(95);
        level95();
    }
    if(i==96){
        setLevelNo(96);
        level96();
    }
    if(i==97){
        hintScreen->end();
    }
    if(i==100&&hintShown!=true){
        hintScreen->level100Hint();
        hintShown=true;
    }
    else if(i==100&&hintShown==true){
        setLevelNo(100);
        level100();
    }
    if(i==101){
        setLevelNo(101);
        level101();
    }
    if(i==102){
        setLevelNo(102);
        level102();
    }
    if(i==103){
        mainWindow->setVisible(true);
        this->setVisible(false);
    }
}

void Game::level1(){
    initialize();
    //SEAT LEVEL NUMBER
    setLevelNo(1);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    //SET SCENE SIZE
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    //SET BACKGROUND IMAGE
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level3.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //SET VIEW SIZE
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    //MANUALLY SET VALID THE MAZE
    //ITS CALCULATED AS ANY INDEX POSITION +2 (THE OFFSET)
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(2);

    //CREATE THE ROBOT
    robot = new Robot();
    //SET THE ROBOT POSITION
    //NOT DUE TO THE ROBOT"S THIN DESIGN, WE MUST SHIFT IT A BIT USING THE "OFFSET"
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    //SET THE INITIAL Y POSITION OF THE START BUTTON
    initialY = 100;
    step = 43;
    sequence.clear();
    //ADD THE ALGORITHM BLOCKS
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY = 100;
    //ADD THE BLOCKS TO THE SCENE
    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
        qDebug()<<sequence[i]->getDirection();
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}

void Game::level2(){
    initialize();
    //SEAT LEVEL NUMBER
    setLevelNo(2);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    //SET SCENE SIZE
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    //SET BACKGROUND IMAGE
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level8.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //SET VIEW SIZE
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    //MANUALLY SET VALID THE MAZE
    //ITS CALCULATED AS ANY INDEX POSITION +2 (THE OFFSET)
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(2);

    //CREATE THE ROBOT
    robot = new Robot();
    //SET THE ROBOT POSITION
    //NOT DUE TO THE ROBOT"S THIN DESIGN, WE MUST SHIFT IT A BIT USING THE "OFFSET"
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    //SET THE INITIAL Y POSITION OF THE START BUTTON
    initialY = 100;
    step = 43;
    sequence.clear();
    //ADD THE ALGORITHM BLOCKS
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY = 100;
    //ADD THE BLOCKS TO THE SCENE
    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
        qDebug()<<sequence[i]->getDirection();
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}

void Game::level3(){
    initialize();
    //SEAT LEVEL NUMBER
    setLevelNo(3);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    //SET SCENE SIZE
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    //SET BACKGROUND IMAGE
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level12.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //SET VIEW SIZE
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    //MANUALLY SET VALID THE MAZE
    //ITS CALCULATED AS ANY INDEX POSITION +2 (THE OFFSET)
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][3]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[5][5]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[2][6]->setTileState(2);

    //CREATE THE ROBOT
    robot = new Robot();
    //SET THE ROBOT POSITION
    //NOT DUE TO THE ROBOT"S THIN DESIGN, WE MUST SHIFT IT A BIT USING THE "OFFSET"
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    //SET THE INITIAL Y POSITION OF THE START BUTTON
    initialY = 100;
    step = 43;
    sequence.clear();
    //ADD THE ALGORITHM BLOCKS
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY = 100;
    //ADD THE BLOCKS TO THE SCENE
    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
        qDebug()<<sequence[i]->getDirection();
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}

void Game::level4(){
    initialize();
        //SEAT LEVEL NUMBER
        setLevelNo(4);
        setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
        scene = new QGraphicsScene();
        //SET SCENE SIZE
        level_height=600;
        scene->setSceneRect(0,0,900,level_height);
        //SET BACKGROUND IMAGE
        setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level1.png")));
        setScene(scene);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        //SET VIEW SIZE
        setFixedSize(900,level_height);

        tileSize = 97;
        clearEmptyMaze();
        //MANUALLY SET VALID THE MAZE
        //ITS CALCULATED AS ANY INDEX POSITION +2 (THE OFFSET)
        maze[2][2]->setTileState(1);
        maze[3][2]->setTileState(1);
        maze[4][2]->setTileState(1);
        maze[5][2]->setTileState(1);
        maze[6][2]->setTileState(1);
        maze[6][3]->setTileState(1);
        maze[6][4]->setTileState(1);
        maze[5][4]->setTileState(1);
        maze[4][4]->setTileState(1);
        maze[4][5]->setTileState(1);
        maze[4][6]->setTileState(2);

        //CREATE THE ROBOT
        robot = new Robot();
        //SET THE ROBOT POSITION
        //NOT DUE TO THE ROBOT"S THIN DESIGN, WE MUST SHIFT IT A BIT USING THE "OFFSET"
        robot->x_offset=25;
        robot->setScale(0.2);
        robot->setPos(300+robot->x_offset,100);
        robot->setFlag(QGraphicsItem::ItemIsFocusable);
        robot->setFocus();
        scene->addItem(robot);
        setMouseTracking(true);

        cursor = new AlgorithmBlock("","",0,0);

        //SET THE INITIAL Y POSITION OF THE START BUTTON
        initialY = 100;
        step = 43;
        sequence.clear();
        //ADD THE ALGORITHM BLOCKS
        if(sequence_copy.empty()){
            sequence.push_back(new AlgorithmBlock("START","",0,initialY));
            sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
            sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
            sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
            sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
            //sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        }
        else{
            sequence.clear();
            for(AlgorithmBlock* b:sequence_copy){
                sequence.push_back(b);
            }
        }
        noBlocks=sequence.size();

        initialY = 100;
        //ADD THE BLOCKS TO THE SCENE
        for(int i=0;i<noBlocks;i++){
            scene->addItem(sequence[i]);
            qDebug()<<sequence[i]->getDirection();
        }

        //TIMER
        timer=new Timer(current_timer);
        scene->addItem(timer);
        timer->start();


        //BACK HOME BUTTONS
        back = new Button("STAGE1BACK");
        back->setPos(50,3);
        home = new Button("HOME");
        home->setPos(50,53);
        volume = new Button("VOLUME");
        volume->setPos(120,3);
        scene->addItem(back);
        scene->addItem(home);
        scene->addItem(volume);

        show();
}

void Game::level5()
{
    initialize();
    setLevelNo(5);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level11.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",4,initialY+=step));
        //sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}

void Game::level6()
{
    initialize();
    setLevelNo(6);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level4.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][3]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}

void Game::level7()
{
    initialize();
    setLevelNo(7);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level5.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}

void Game::level8()
{
    initialize();
    setLevelNo(8);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level7.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[5][3]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}

void Game::level9()
{
    initialize();
    setLevelNo(9);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level10.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][6]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}

void Game::level10()
{
    initialize();
    setLevelNo(10);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level9.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}

void Game::level11()
{
    initialize();
    setLevelNo(11);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level2.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);

    show();
}


void Game::level12()
{
    initialize();
    setLevelNo(12);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level6.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[6][2]->setTileState(2);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);

    /*obstacle.push_back(new Obstacle(3,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14,obstacle[0]->getY());
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);*/

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();


    //BACK HOME BUTTONS
    back = new Button("STAGE1BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level13()
{
    initialize();
    setLevelNo(13);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level13.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[5][5]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level14()
{
    initialize();
    setLevelNo(14);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level14.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level15()
{
    initialize();
    setLevelNo(15);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level15.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level16()
{
    initialize();
    setLevelNo(16);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level16.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(-3);
    maze[4][3]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(2);

    obstacle.push_back(new Obstacle(-3,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14,obstacle[0]->getY());
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level17()
{
    initialize();
    setLevelNo(17);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level17.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[3][4]->setTileState(3);
    maze[2][4]->setTileState(2);

    obstacle.push_back(new Obstacle(3,maze[3][4]->getX(),maze[3][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14 +3,obstacle[0]->getY()-5);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("BRIDGE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level18()
{
    initialize();
    setLevelNo(18);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level18.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][4]->setTileState(-3);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(2);

    obstacle.push_back(new Obstacle(-3,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14 +3,obstacle[0]->getY()-5);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level19()
{
    initialize();
    setLevelNo(19);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level19.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[4][6]->setTileState(1);
    maze[3][6]->setTileState(3);
    maze[2][6]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[3][4]->setTileState(3);
    maze[4][4]->setTileState(1);
    maze[4][3]->setTileState(-3);
    maze[4][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(2);

    obstacle.push_back(new Obstacle(3,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14 +8,obstacle[0]->getY()-3);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(3,maze[3][4]->getX(),maze[3][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +3,obstacle[1]->getY()-3);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(-3,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 -3,obstacle[2]->getY()-2);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,294);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("BRIDGE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level20()
{
    initialize();
    setLevelNo(20);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level20.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[6][4]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level21()
{
    initialize();
    setLevelNo(21);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level21.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[5][5]->setTileState(3);
    maze[6][5]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(2);

    obstacle.push_back(new Obstacle(3,maze[5][5]->getX(),maze[5][5]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14 +8,obstacle[0]->getY()-3);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));

    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level22()
{
    initialize();
    setLevelNo(22);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level22.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[5][5]->setTileState(-3);
    maze[5][6]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[2][6]->setTileState(2);

    obstacle.push_back(new Obstacle(-3,maze[5][5]->getX(),maze[5][5]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14 +3,obstacle[0]->getY()-3);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::restart()
{
    createLevel(getLevelNo());
}


void Game::format(int initY)
{
    for(AlgorithmBlock* b:sequence){
        b->setPos(48,b->getY());
    }
    int blockNo=0;
    int blockCoords=initialY+step;

    for (int i=1;i<sequence.length();i++) {
        if(sequence[i]->newlyPlaced){
            blockNo=i;
            blockCoords=sequence[i]->getY();
            break;
        }
    }

    if(initY<blockCoords){
        //top down;
        for(int i=1;i<sequence.size()-1;i++){
            if(sequence[i]->getY()>=sequence[i+1]->getY() && sequence[i]->newlyPlaced){
                sequence.move(i+1,i);
            }
        }
    }
    else{
        //bottom up;
        for(int i=sequence.size()-1;i>0;i--){
            if(sequence[i]->getY()<=sequence[i-1]->getY() && sequence[i]->newlyPlaced){
                sequence[i]->setY(sequence[i]->getY());
                sequence[i-1]->setY(sequence[i-1]->getY());
                sequence.move(i-1,i);
            }
        }
    }
    int tempInit = initialY;
    if(sequence[0]->getBlockType()!="START"){
        sequence.move(1,0);
    }
    for(int i=0;i<sequence.size();i++){
        sequence[i]->setY(tempInit);
        tempInit+=step;
    }
    for(AlgorithmBlock* b:sequence){
        b->newlyPlaced=0;
        b->setPos(48,b->getY());
        qDebug()<<b->getDirection()<<b->getSteps()<<b->getY();
    }

}

void Game::level23()
{
    initialize();
    setLevelNo(23);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level23.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(-3);
    maze[2][6]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(2);

    obstacle.push_back(new Obstacle(-3,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14 +3,obstacle[0]->getY()-1);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,488);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level24()
{
    initialize();
    setLevelNo(24);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level2/level24.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(-3);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(3);
    maze[6][6]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(2);

    obstacle.push_back(new Obstacle(3,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14 +7,obstacle[0]->getY()-3);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-3,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +3,obstacle[1]->getY());
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,197);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE2BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level25()
{
    initialize();
    setLevelNo(25);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level25.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(5);
    maze[3][2]->setTileState(5);
    maze[5][2]->setTileState(5);
    maze[6][2]->setTileState(5);
    maze[6][4]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(4);
    maze[4][6]->setTileState(2);

    obstacle.push_back(new Obstacle(5,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+15,obstacle[0]->getY()+10);
    obstacle[0]->startFire();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+15,obstacle[1]->getY()+10);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+15,obstacle[2]->getY()+10);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[6][2]->getX(),maze[6][2]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+15,obstacle[3]->getY()+10);
    obstacle[3]->startFire();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(4,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+15,obstacle[4]->getY()+5);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,488);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level26()
{
    initialize();
    setLevelNo(26);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level26.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(4);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(5);
    maze[2][5]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[5][5]->setTileState(1);
    maze[6][5]->setTileState(2);

    obstacle.push_back(new Obstacle(5,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+15,obstacle[0]->getY()+10);
    obstacle[0]->startFire();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(4,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+3,obstacle[1]->getY()+5);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level27()
{
    initialize();
    setLevelNo(27);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level27.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(-3);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(-3);
    maze[4][6]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[6][4]->setTileState(2);

    obstacle.push_back(new Obstacle(-3,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14-5,obstacle[0]->getY());
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-3,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+3,obstacle[1]->getY());
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,488);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("BRIDGE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level28()
{
    initialize();
    setLevelNo(28);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level28.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(5);
    maze[2][4]->setTileState(5);
    maze[2][5]->setTileState(5);
    maze[2][6]->setTileState(2);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(5);
    maze[4][4]->setTileState(5);
    maze[4][5]->setTileState(5);
    maze[4][6]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(5);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(5);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(5,maze[2][3]->getX(),maze[2][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14 +20,obstacle[0]->getY()+5);
    obstacle[0]->startFire();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +20,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 +20,obstacle[2]->getY()+5);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14 +20,obstacle[3]->getY()+5);
    obstacle[3]->startFire();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(5,maze[4][4]->getX(),maze[4][4]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14 +20,obstacle[4]->getY()+5);
    obstacle[4]->startFire();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(5,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14 +20,obstacle[5]->getY()+5);
    obstacle[5]->startFire();
    scene->addItem(obstacle[5]);
    obstacle.push_back(new Obstacle(5,maze[6][3]->getX(),maze[6][3]->getY()));
    obstacle[6]->setPos(obstacle[6]->getX()+tileSize/14 +20,obstacle[6]->getY()+5);
    obstacle[6]->startFire();
    scene->addItem(obstacle[6]);
    obstacle.push_back(new Obstacle(5,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[7]->setPos(obstacle[7]->getX()+tileSize/14 +20,obstacle[7]->getY()+5);
    obstacle[7]->startFire();
    scene->addItem(obstacle[7]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level29()
{
    initialize();
    setLevelNo(29);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level29.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[3][6]->setTileState(4);
    maze[4][2]->setTileState(5);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(5);
    maze[4][5]->setTileState(1);
    maze[5][5]->setTileState(1);
    maze[6][2]->setTileState(2);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(4,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+15,obstacle[0]->getY()+5);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +20,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[4][4]->getX(),maze[4][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 +20,obstacle[2]->getY()+5);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level30()
{
    initialize();
    setLevelNo(30);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level30.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(4);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(5);
    maze[4][6]->setTileState(1);
    maze[5][4]->setTileState(5);
    maze[5][6]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(2);

    obstacle.push_back(new Obstacle(4,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY());
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +20,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 +18,obstacle[2]->getY()+10);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,294);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level31()
{
    initialize();
    setLevelNo(31);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level31.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(5);
    maze[2][3]->setTileState(1);
    maze[2][6]->setTileState(2);
    maze[3][2]->setTileState(5);
    maze[3][6]->setTileState(1);
    maze[4][2]->setTileState(5);
    maze[4][3]->setTileState(1);
    maze[4][5]->setTileState(5);
    maze[4][6]->setTileState(1);
    maze[5][3]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[5][5]->setTileState(1);
    maze[6][4]->setTileState(4);

    obstacle.push_back(new Obstacle(4,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+10,obstacle[0]->getY()+5);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +25,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 +25,obstacle[2]->getY()+5);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14 +25,obstacle[3]->getY()+5);
    obstacle[3]->startFire();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(5,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14 +25,obstacle[4]->getY()+5);
    obstacle[4]->startFire();
    scene->addItem(obstacle[4]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level32()
{
    initialize();
    setLevelNo(32);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level32.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(5);
    maze[2][4]->setTileState(5);
    maze[3][2]->setTileState(5);
    maze[4][2]->setTileState(4);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(-3);
    maze[6][6]->setTileState(2);

    obstacle.push_back(new Obstacle(4,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+5);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[2][3]->getX(),maze[2][3]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +25,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 +25,obstacle[2]->getY()+5);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14 +25,obstacle[3]->getY()+5);
    obstacle[3]->startFire();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(-3,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14,obstacle[4]->getY()+3);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level33()
{
    initialize();
    setLevelNo(33);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level33.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(5);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(5);
    maze[2][6]->setTileState(5);
    maze[3][2]->setTileState(1);
    maze[3][6]->setTileState(5);
    maze[4][4]->setTileState(4);
    maze[4][6]->setTileState(5);
    maze[5][2]->setTileState(5);
    maze[5][4]->setTileState(5);
    maze[5][6]->setTileState(5);
    maze[6][2]->setTileState(2);
    maze[6][4]->setTileState(5);
    maze[6][5]->setTileState(5);
    maze[6][6]->setTileState(5);

    obstacle.push_back(new Obstacle(4,maze[4][4]->getX(),maze[4][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+5);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[2][3]->getX(),maze[2][3]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +25,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 +25,obstacle[2]->getY()+5);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14 +25,obstacle[3]->getY()+5);
    obstacle[3]->startFire();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(5,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14 +25,obstacle[4]->getY()+5);
    obstacle[4]->startFire();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(5,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14 +25,obstacle[5]->getY()+5);
    obstacle[5]->startFire();
    scene->addItem(obstacle[5]);
    obstacle.push_back(new Obstacle(5,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[6]->setPos(obstacle[6]->getX()+tileSize/14 +25,obstacle[6]->getY()+5);
    obstacle[6]->startFire();
    scene->addItem(obstacle[6]);
    obstacle.push_back(new Obstacle(5,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[7]->setPos(obstacle[7]->getX()+tileSize/14 +25,obstacle[7]->getY()+5);
    obstacle[7]->startFire();
    scene->addItem(obstacle[7]);
    obstacle.push_back(new Obstacle(5,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[8]->setPos(obstacle[8]->getX()+tileSize/14 +25,obstacle[8]->getY()+5);
    obstacle[8]->startFire();
    scene->addItem(obstacle[8]);
    obstacle.push_back(new Obstacle(5,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[9]->setPos(obstacle[9]->getX()+tileSize/14 +25,obstacle[9]->getY()+5);
    obstacle[9]->startFire();
    scene->addItem(obstacle[9]);
    obstacle.push_back(new Obstacle(5,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[10]->setPos(obstacle[10]->getX()+tileSize/14 +25,obstacle[10]->getY()+5);
    obstacle[10]->startFire();
    scene->addItem(obstacle[10]);
    obstacle.push_back(new Obstacle(5,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[11]->setPos(obstacle[11]->getX()+tileSize/14 +25,obstacle[11]->getY()+5);
    obstacle[11]->startFire();
    scene->addItem(obstacle[11]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,197);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level34()
{
    initialize();
    setLevelNo(34);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level34.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[3][2]->setTileState(2);
    maze[3][3]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(5);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(5);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(5,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+25,obstacle[0]->getY()+5);
    obstacle[0]->startFire();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[6][3]->getX(),maze[6][3]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +25,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level35()
{
    initialize();
    setLevelNo(35);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level35.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(5);
    maze[5][3]->setTileState(1);
    maze[5][5]->setTileState(4);
    maze[6][2]->setTileState(2);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(4,maze[5][5]->getX(),maze[5][5]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+12,obstacle[0]->getY()+5);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +25,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level36()
{
    initialize();
    setLevelNo(36);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level3/level36.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[3][4]->setTileState(5);
    maze[3][5]->setTileState(1);
    maze[5][2]->setTileState(4);
    maze[5][3]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[6][4]->setTileState(2);


    obstacle.push_back(new Obstacle(4,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+5);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[3][4]->getX(),maze[3][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +25,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE3BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level37()
{
    initialize();
    setLevelNo(37);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level37.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][6]->setTileState(5);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(3);
    maze[6][2]->setTileState(2);
    maze[6][3]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(3,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+8,obstacle[0]->getY()-3);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+18,obstacle[1]->getY()-3);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level38()
{
    initialize();
    setLevelNo(38);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level38.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][4]->setTileState(2);
    maze[2][6]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(5);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][2]->setTileState(4);
    maze[6][3]->setTileState(-3);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(-3);
    maze[6][6]->setTileState(1);


    obstacle.push_back(new Obstacle(5,maze[4][4]->getX(),maze[4][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+23,obstacle[0]->getY());
    obstacle[0]->startFire();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(4,maze[6][2]->getX(),maze[6][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14,obstacle[1]->getY()+3);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(-3,maze[6][3]->getX(),maze[6][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14-3,obstacle[2]->getY()-3);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-3,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+1,obstacle[3]->getY()-3);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::setCursor(AlgorithmBlock* a)
{
    setMouseTracking(true);
    cursor = a;
    cursor->topLevelItem();
    cursor->setZValue(1);
    scene->addItem(cursor);
}

void Game::level39()
{
    initialize();
    setLevelNo(39);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level39.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[6][2]->setTileState(6);
    maze[6][4]->setTileState(-6);
    maze[5][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[4][6]->setTileState(2);


    obstacle.push_back(new Obstacle(6,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+10,obstacle[0]->getY());
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[6][2]->getX(),maze[6][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14,obstacle[1]->getY()+3);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level40()
{
    initialize();
    setLevelNo(40);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level40.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][4]->setTileState(-6);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(6);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(2);


    obstacle.push_back(new Obstacle(6,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14 +10,obstacle[0]->getY());
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +10,obstacle[1]->getY()+3);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,488);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level41()
{
    initialize();
    setLevelNo(41);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level41.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[3][2]->setTileState(2);
    maze[3][3]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(6);
    maze[6][5]->setTileState(-6);
    maze[6][6]->setTileState(1);


    obstacle.push_back(new Obstacle(6,maze[6][3]->getX(),maze[6][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+10,obstacle[0]->getY());
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +10,obstacle[1]->getY()+3);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level42()
{
    initialize();
    setLevelNo(42);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level42.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(-6);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][2]->setTileState(6);
    maze[4][4]->setTileState(2);
    maze[4][6]->setTileState(3);
    maze[5][2]->setTileState(3);
    maze[5][6]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(-3);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(-3);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(3,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+10,obstacle[0]->getY()-2);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(3,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()-1,obstacle[1]->getY()-6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(-3,maze[6][3]->getX(),maze[6][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+2,obstacle[2]->getY()+1);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-3,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+7,obstacle[3]->getY()+1);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(-6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+5,obstacle[4]->getY()+1);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(6,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+5,obstacle[5]->getY()+1);
    obstacle[5]->set_image();
    scene->addItem(obstacle[5]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","NORTH",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level43()
{
    initialize();
    setLevelNo(43);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level43.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][4]->setTileState(2);
    maze[2][6]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][6]->setTileState(-6);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+3,obstacle[0]->getY()+2);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+18,obstacle[1]->getY()+8);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,488);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level44()
{
    initialize();
    setLevelNo(44);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level44.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][6]->setTileState(6);
    maze[5][2]->setTileState(1);
    maze[5][3]->setTileState(1);
    maze[5][5]->setTileState(1);
    maze[6][2]->setTileState(2);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(-6);


    obstacle.push_back(new Obstacle(6,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+8,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+18,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level45()
{
    initialize();
    setLevelNo(45);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level45.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][2]->setTileState(6);
    maze[3][3]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[5][2]->setTileState(-6);
    maze[5][4]->setTileState(1);
    maze[6][4]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[3][2]->getX(),maze[3][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level46()
{
    initialize();
    setLevelNo(46);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level46.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(6);
    maze[3][2]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[4][3]->setTileState(-6);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(2);
    maze[5][3]->setTileState(1);
    maze[6][2]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[2][3]->getX(),maze[2][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level47()
{
    initialize();
    setLevelNo(47);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level47.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(6);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][3]->setTileState(-6);
    maze[5][4]->setTileState(1);
    maze[6][5]->setTileState(2);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[5][3]->getX(),maze[5][3]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level48()
{
    initialize();
    setLevelNo(48);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level4/level48.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(4);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(6);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(-6);
    maze[5][2]->setTileState(3);
    maze[5][3]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][4]->setTileState(5);
    maze[6][6]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][4]->getX(),maze[4][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+20,obstacle[2]->getY()+6);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(4,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+3,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(3,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14,obstacle[4]->getY()-4);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE4BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level49()
{
    initialize();
    setLevelNo(49);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level49.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[5][2]->setTileState(6);
    maze[5][4]->setTileState(-6);
    maze[5][5]->setTileState(1);
    maze[5][6]->setTileState(7);
    maze[4][6]->setTileState(5);
    maze[3][6]->setTileState(-7);
    maze[2][6]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+20,obstacle[2]->getY()+6);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(7,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+3,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(-7,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14,obstacle[4]->getY()-4);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level50()
{
    initialize();
    setLevelNo(50);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level50.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][4]->setTileState(2);
    maze[2][6]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(-6);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][6]->setTileState(7);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(-7);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(6);

    obstacle.push_back(new Obstacle(7,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][4]->getX(),maze[4][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+20,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(6,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+20,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+3,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

/*
void Game::level51()
{
    initialize();
    setLevelNo(51);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level51.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][6]->setTileState(1);
    maze[4][3]->setTileState(6);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(-6);
    maze[5][5]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+20,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    sequence.push_back(new AlgorithmBlock("START","",0,initialY));
    sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
    sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
    sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
    sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));


    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}*/

void Game::level51()
{
    initialize();
    setLevelNo(51);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level51.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(4);
    maze[2][3]->setTileState(6);
    maze[2][4]->setTileState(7);
    maze[3][2]->setTileState(-7);
    maze[3][4]->setTileState(-6);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(5);
    maze[4][6]->setTileState(1);
    maze[6][4]->setTileState(5);
    maze[5][4]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][4]->setTileState(5);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(2);

    obstacle.push_back(new Obstacle(4,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+2,obstacle[0]->getY()+3);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +20,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 +18,obstacle[2]->getY()+10);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14 +18,obstacle[3]->getY()+10);
    obstacle[3]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(6,maze[2][3]->getX(),maze[2][3]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+3,obstacle[4]->getY()+6);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(-6,maze[3][4]->getX(),maze[3][4]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+3,obstacle[5]->getY()+6);
    obstacle[5]->set_image();
    scene->addItem(obstacle[5]);
    obstacle.push_back(new Obstacle(7,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[6]->setPos(obstacle[6]->getX()+tileSize/14+3,obstacle[6]->getY()+6);
    obstacle[6]->set_image();
    scene->addItem(obstacle[6]);
    obstacle.push_back(new Obstacle(-7,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[7]->setPos(obstacle[7]->getX()+tileSize/14+3,obstacle[7]->getY()+6);
    obstacle[7]->set_image();
    scene->addItem(obstacle[7]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,294);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level52()
{
    initialize();
    setLevelNo(52);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level52.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(5);
    maze[2][3]->setTileState(1);
    maze[2][6]->setTileState(2);
    maze[3][2]->setTileState(6);
    maze[3][6]->setTileState(1);
    maze[4][2]->setTileState(5);
    maze[4][3]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][3]->setTileState(4);
    maze[5][5]->setTileState(-6);

    obstacle.push_back(new Obstacle(4,maze[5][3]->getX(),maze[5][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+3);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +20,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 +18,obstacle[2]->getY()+10);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14 +18,obstacle[3]->getY()+10);
    obstacle[3]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(6,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+3,obstacle[4]->getY()+6);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(-6,maze[5][5]->getX(),maze[5][5]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+3,obstacle[5]->getY()+6);
    obstacle[5]->set_image();
    scene->addItem(obstacle[5]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level53()
{
    initialize();
    setLevelNo(53);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level53.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][2]->setTileState(6);
    maze[3][3]->setTileState(1);
    maze[3][5]->setTileState(-6);
    maze[5][2]->setTileState(7);
    maze[5][4]->setTileState(-7);
    maze[6][4]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[3][2]->getX(),maze[3][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[3][5]->getX(),maze[3][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level54()
{
    initialize();
    setLevelNo(54);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level54.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][3]->setTileState(1);
    maze[2][5]->setTileState(6);
    maze[2][6]->setTileState(1);
    maze[3][2]->setTileState(-6);
    maze[3][3]->setTileState(7);
    maze[3][5]->setTileState(1);
    maze[5][4]->setTileState(-7);
    maze[5][5]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(2);


    obstacle.push_back(new Obstacle(6,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[3][3]->getX(),maze[3][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level55()
{
    initialize();
    setLevelNo(55);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level55.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[4][3]->setTileState(6);
    maze[4][5]->setTileState(-6);
    maze[6][2]->setTileState(2);
    maze[6][3]->setTileState(7);
    maze[6][5]->setTileState(-7);

    obstacle.push_back(new Obstacle(6,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[6][3]->getX(),maze[6][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level56()
{
    initialize();
    setLevelNo(56);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level56.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][4]->setTileState(7);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][4]->setTileState(4);
    maze[3][6]->setTileState(6);
    maze[4][2]->setTileState(-6);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[5][5]->setTileState(1);
    maze[6][2]->setTileState(2);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(5);
    maze[6][6]->setTileState(-7);


    obstacle.push_back(new Obstacle(6,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(4,maze[3][4]->getX(),maze[3][4]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+5,obstacle[4]->getY()+6);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(5,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+20,obstacle[5]->getY()+6);
    obstacle[5]->startFire();
    scene->addItem(obstacle[5]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level57()
{
    initialize();
    setLevelNo(57);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level57.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(6);
    maze[2][4]->setTileState(1);
    maze[2][6]->setTileState(-7);
    maze[3][2]->setTileState(7);
    maze[3][5]->setTileState(1);
    maze[4][3]->setTileState(-6);
    maze[4][6]->setTileState(2);
    maze[5][3]->setTileState(1);
    maze[6][5]->setTileState(1);


    obstacle.push_back(new Obstacle(6,maze[2][3]->getX(),maze[2][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level58()
{
    initialize();
    setLevelNo(58);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level58.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(-7);
    maze[3][2]->setTileState(-6);
    maze[3][3]->setTileState(1);
    maze[3][4]->setTileState(7);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][3]->setTileState(1);
    maze[5][4]->setTileState(6);
    maze[6][5]->setTileState(2);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[3][4]->getX(),maze[3][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level59()
{
    initialize();
    setLevelNo(59);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level59.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(4);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(6);
    maze[3][5]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(5);
    maze[4][6]->setTileState(-6);
    maze[6][5]->setTileState(2);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(4,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+15,obstacle[3]->getY()+6);
    obstacle[3]->startFire();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,294);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level60()
{
    initialize();
    setLevelNo(60);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level5/level60.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(-3);
    maze[2][5]->setTileState(1);
    maze[3][2]->setTileState(6);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(-6);
    maze[5][3]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(2);
    maze[6][6]->setTileState(1);


    obstacle.push_back(new Obstacle(6,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(-3,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(591+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE5BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level61()
{
    initialize();
    setLevelNo(61);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level61.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[4][2]->setTileState(7);
    maze[4][4]->setTileState(6);
    maze[4][6]->setTileState(-6);
    maze[6][2]->setTileState(2);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(-3);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(-7);

    obstacle.push_back(new Obstacle(6,maze[4][4]->getX(),maze[4][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(-3,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(7,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(-7,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14,obstacle[4]->getY()+4);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level62()
{
    initialize();
    setLevelNo(62);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level62.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][4]->setTileState(2);
    maze[2][6]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][6]->setTileState(7);
    maze[6][2]->setTileState(-6);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(-7);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(6);

    obstacle.push_back(new Obstacle(7,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[6][2]->getX(),maze[6][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+20,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(6,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+20,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+3,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level63()
{
    initialize();
    setLevelNo(63);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level63.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(7);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(2);
    maze[4][2]->setTileState(-6);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][5]->setTileState(-7);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(6);

    obstacle.push_back(new Obstacle(7,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+20,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(6,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+20,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+3,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,488);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }

    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level64()
{
    initialize();
    setLevelNo(64);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level64.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[3][4]->setTileState(4);
    maze[3][6]->setTileState(-6);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[5][4]->setTileState(5);
    maze[5][5]->setTileState(1);
    maze[6][5]->setTileState(2);

    obstacle.push_back(new Obstacle(4,maze[3][4]->getX(),maze[3][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+7,obstacle[0]->getY()+5);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +20,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+3,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-6,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+3,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,294);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level65()
{
    initialize();
    setLevelNo(65);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level65.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[6][3]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(-3);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(-3);
    maze[4][6]->setTileState(-6);
    maze[2][6]->setTileState(6);
    maze[2][5]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[6][4]->setTileState(2);

    obstacle.push_back(new Obstacle(-3,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14-5,obstacle[0]->getY());
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-3,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+3,obstacle[1]->getY());
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-6,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+20,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level66()
{
    initialize();
    setLevelNo(66);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level66.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(4);
    maze[2][3]->setTileState(6);
    maze[2][4]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(-6);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(5);
    maze[4][6]->setTileState(1);
    maze[6][4]->setTileState(5);
    maze[5][4]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][4]->setTileState(5);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(2);

    obstacle.push_back(new Obstacle(4,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+2,obstacle[0]->getY()+3);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(5,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14 +20,obstacle[1]->getY()+5);
    obstacle[1]->startFire();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14 +18,obstacle[2]->getY()+10);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14 +18,obstacle[3]->getY()+10);
    obstacle[3]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(6,maze[2][3]->getX(),maze[2][3]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+3,obstacle[4]->getY()+6);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(-6,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+3,obstacle[5]->getY()+6);
    obstacle[5]->set_image();
    scene->addItem(obstacle[5]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,294);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level67()
{
    initialize();
    setLevelNo(67);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level67.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(6);
    maze[3][2]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][2]->setTileState(-7);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][2]->setTileState(2);
    maze[6][4]->setTileState(7);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(-6);


    obstacle.push_back(new Obstacle(6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+20,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+20,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+3,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level68()
{
    initialize();
    setLevelNo(68);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level68.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(-7);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][4]->setTileState(2);
    maze[5][6]->setTileState(1);
    maze[6][2]->setTileState(7);
    maze[6][4]->setTileState(-6);
    maze[6][6]->setTileState(6);


    obstacle.push_back(new Obstacle(6,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+20,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[6][2]->getX(),maze[6][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+20,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+3,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level69()
{
    initialize();
    setLevelNo(69);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level69.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][3]->setTileState(1);
    maze[2][5]->setTileState(-7);
    maze[2][6]->setTileState(6);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(7);
    maze[3][5]->setTileState(1);
    maze[5][4]->setTileState(-6);
    maze[5][5]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(2);


    obstacle.push_back(new Obstacle(6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[3][3]->getX(),maze[3][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,197);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level70()
{
    initialize();
    setLevelNo(70);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level70.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(-7);
    maze[3][2]->setTileState(6);
    maze[3][3]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(7);
    maze[5][3]->setTileState(1);
    maze[5][4]->setTileState(-6);
    maze[6][5]->setTileState(2);
    maze[6][6]->setTileState(1);



    obstacle.push_back(new Obstacle(6,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,197);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level71()
{
    initialize();
    setLevelNo(71);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level71.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(6);
    maze[4][2]->setTileState(-6);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(7);
    maze[5][6]->setTileState(2);
    maze[6][2]->setTileState(-7);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[4][4]->getX(),maze[4][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[6][2]->getX(),maze[6][2]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level72()
{
    initialize();
    setLevelNo(72);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level6/level72.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(-3);
    maze[2][5]->setTileState(2);
    maze[3][2]->setTileState(6);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(-6);
    maze[5][3]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(1);


    obstacle.push_back(new Obstacle(6,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(-3,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(688+robot->x_offset,488);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("BRIDGE","EAST",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE6BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level73()
{
    initialize();
    setLevelNo(73);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level73.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][6]->setTileState(2);
    maze[3][2]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][2]->setTileState(6);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(7);
    maze[5][4]->setTileState(-6);
    maze[5][6]->setTileState(-7);

    obstacle.push_back(new Obstacle(6,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level74()
{
    initialize();
    setLevelNo(74);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level74.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(6);
    maze[4][2]->setTileState(7);
    maze[4][3]->setTileState(-6);
    maze[4][5]->setTileState(-7);
    maze[4][6]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(2);


    obstacle.push_back(new Obstacle(6,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level75()
{
    initialize();
    setLevelNo(75);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level75.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][4]->setTileState(6);
    maze[2][6]->setTileState(4);
    maze[3][3]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][4]->setTileState(-6);
    maze[4][6]->setTileState(5);
    maze[5][3]->setTileState(1);
    maze[5][5]->setTileState(1);
    maze[6][2]->setTileState(5);
    maze[6][4]->setTileState(5);
    maze[6][6]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][4]->getX(),maze[4][4]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(4,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+10,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[6][2]->getX(),maze[6][2]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+20,obstacle[3]->getY()+6);
    obstacle[3]->startFire();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(5,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+20,obstacle[4]->getY()+6);
    obstacle[4]->startFire();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(5,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+20,obstacle[5]->getY()+6);
    obstacle[5]->startFire();
    scene->addItem(obstacle[5]);


    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level76()
{
    initialize();
    setLevelNo(76);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level76.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][6]->setTileState(2);
    maze[3][2]->setTileState(1);
    maze[3][6]->setTileState(-6);
    maze[4][2]->setTileState(6);
    maze[4][3]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(7);
    maze[5][3]->setTileState(-7);
    maze[5][5]->setTileState(1);


    obstacle.push_back(new Obstacle(6,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[5][3]->getX(),maze[5][3]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level77()
{
    initialize();
    setLevelNo(77);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level77.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][3]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][5]->setTileState(-6);
    maze[6][2]->setTileState(2);
    maze[6][3]->setTileState(-7);
    maze[6][5]->setTileState(7);


    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[6][3]->getX(),maze[6][3]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,294);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level78()
{
    initialize();
    setLevelNo(78);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level78.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(2);
    maze[3][2]->setTileState(3);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(-6);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(6);



    obstacle.push_back(new Obstacle(6,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(3,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14,obstacle[2]->getY()+1);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,488);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("BRIDGE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level79()
{
    initialize();
    setLevelNo(79);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level79.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(-6);
    maze[3][2]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(2);
    maze[5][2]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][4]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,488);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","NORTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level80()
{
    initialize();
    setLevelNo(80);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level80.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[3][2]->setTileState(2);
    maze[3][3]->setTileState(-8);
    maze[3][5]->setTileState(8);
    maze[3][6]->setTileState(-7);
    maze[5][2]->setTileState(1);
    maze[5][6]->setTileState(7);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(6);
    maze[6][5]->setTileState(-6);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[6][3]->getX(),maze[6][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(8,maze[3][5]->getX(),maze[3][5]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+5,obstacle[4]->getY()+6);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(-8,maze[3][3]->getX(),maze[3][3]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+5,obstacle[5]->getY()+6);
    obstacle[5]->set_image();
    scene->addItem(obstacle[5]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}


void Game::level81()
{
    initialize();
    setLevelNo(81);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level81.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][4]->setTileState(2);
    maze[2][6]->setTileState(-7);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(-8);
    maze[3][5]->setTileState(8);
    maze[3][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][6]->setTileState(7);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(6);
    maze[6][5]->setTileState(-6);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[6][3]->getX(),maze[6][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[5][6]->getX(),maze[5][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(8,maze[3][5]->getX(),maze[3][5]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+5,obstacle[4]->getY()+6);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(-8,maze[3][3]->getX(),maze[3][3]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+5,obstacle[5]->getY()+6);
    obstacle[5]->set_image();
    scene->addItem(obstacle[5]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level82()
{
    initialize();
    setLevelNo(82);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level82.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(6);
    maze[3][5]->setTileState(-6);
    maze[3][6]->setTileState(1);
    maze[4][6]->setTileState(7);
    maze[5][2]->setTileState(1);
    maze[5][3]->setTileState(-8);
    maze[5][5]->setTileState(8);
    maze[6][2]->setTileState(2);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(-7);


    obstacle.push_back(new Obstacle(6,maze[3][3]->getX(),maze[3][3]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[3][5]->getX(),maze[3][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(8,maze[5][5]->getX(),maze[5][5]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+5,obstacle[4]->getY()+6);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(-8,maze[5][3]->getX(),maze[5][3]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+5,obstacle[5]->getY()+6);
    obstacle[5]->set_image();
    scene->addItem(obstacle[5]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}


void Game::level83()
{
    initialize();
    setLevelNo(83);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level83.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][3]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(-6);
    maze[3][2]->setTileState(6);
    maze[3][3]->setTileState(1);
    maze[3][5]->setTileState(7);
    maze[5][4]->setTileState(-7);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(2);


    obstacle.push_back(new Obstacle(6,maze[3][2]->getX(),maze[3][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[3][5]->getX(),maze[3][5]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+6);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level84()
{
    initialize();
    setLevelNo(84);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level7/level84.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][3]->setTileState(-8);
    maze[2][4]->setTileState(-9);
    maze[2][5]->setTileState(-6);
    maze[3][2]->setTileState(1);
    maze[3][3]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[3][6]->setTileState(-7);
    maze[4][2]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][3]->setTileState(9);
    maze[5][4]->setTileState(1);
    maze[5][5]->setTileState(7);
    maze[5][6]->setTileState(1);
    maze[6][2]->setTileState(6);
    maze[6][4]->setTileState(2);
    maze[6][6]->setTileState(8);


    obstacle.push_back(new Obstacle(6,maze[6][2]->getX(),maze[6][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[5][5]->getX(),maze[5][5]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(8,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+5,obstacle[4]->getY()+4);
    obstacle[4]->set_image();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(-8,maze[2][3]->getX(),maze[2][3]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+5,obstacle[5]->getY()+6);
    obstacle[5]->set_image();
    scene->addItem(obstacle[5]);
    obstacle.push_back(new Obstacle(9,maze[5][3]->getX(),maze[5][3]->getY()));
    obstacle[6]->setPos(obstacle[6]->getX()+tileSize/14+5,obstacle[6]->getY()+4);
    obstacle[6]->set_image();
    scene->addItem(obstacle[6]);
    obstacle.push_back(new Obstacle(-9,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[7]->setPos(obstacle[7]->getX()+tileSize/14+5,obstacle[7]->getY()+6);
    obstacle[7]->set_image();
    scene->addItem(obstacle[7]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,197);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE7BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level85()
{
    initialize();
    setLevelNo(85);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level85.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(-6);
    maze[3][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[6][4]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level86()
{
    initialize();
    setLevelNo(86);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level86.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(-6);
    maze[3][4]->setTileState(1);
    maze[4][3]->setTileState(7);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(-7);
    maze[4][5]->setTileState(1);
    maze[5][5]->setTileState(1);
    maze[6][5]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[4][6]->getX(),maze[4][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level87()
{
    initialize();
    setLevelNo(87);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level87.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[3][2]->setTileState(1);
    maze[3][4]->setTileState(7);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[5][2]->setTileState(-6);
    maze[5][4]->setTileState(1);
    maze[6][4]->setTileState(-7);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(2);


    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[3][4]->getX(),maze[3][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[6][4]->getX(),maze[6][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,197);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level88()
{
    initialize();
    setLevelNo(88);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level88.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][4]->setTileState(7);
    maze[2][6]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[3][5]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(-6);
    maze[5][4]->setTileState(-7);
    maze[5][6]->setTileState(1);
    maze[6][3]->setTileState(2);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[5][2]->getX(),maze[5][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,197);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level89()
{
    initialize();
    setLevelNo(89);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level89.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(-6);
    maze[3][4]->setTileState(1);
    maze[3][6]->setTileState(7);
    maze[4][4]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][3]->setTileState(2);
    maze[5][5]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][6]->setTileState(-7);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[3][6]->getX(),maze[3][6]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(397+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("JUMP","EAST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level90()
{
    initialize();
    setLevelNo(90);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level90.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(-6);
    maze[3][3]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[6][3]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(591+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level91()
{
    initialize();
    setLevelNo(91);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level91.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][4]->setTileState(7);
    maze[3][2]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][4]->setTileState(-7);
    maze[5][5]->setTileState(2);
    maze[6][2]->setTileState(-6);


    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[6][2]->getX(),maze[6][2]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[2][4]->getX(),maze[2][4]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[5][4]->getX(),maze[5][4]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(300+robot->x_offset,391);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",1,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level92()
{
    initialize();
    setLevelNo(92);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level92.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(-6);
    maze[3][3]->setTileState(1);
    maze[4][2]->setTileState(7);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(-7);
    maze[5][4]->setTileState(1);
    maze[6][2]->setTileState(2);
    maze[6][4]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][5]->getX(),maze[2][5]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(7,maze[4][2]->getX(),maze[4][2]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->set_image();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(-7,maze[4][5]->getX(),maze[4][5]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+6);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",4,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level93()
{
    initialize();
    setLevelNo(93);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level93.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(-6);
    maze[3][3]->setTileState(5);
    maze[3][5]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[5][3]->setTileState(2);
    maze[5][5]->setTileState(1);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[3][3]->getX(),maze[3][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level94()
{
    initialize();
    setLevelNo(94);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level94.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(-6);
    maze[3][3]->setTileState(5);
    maze[3][5]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[5][5]->setTileState(4);
    maze[6][3]->setTileState(2);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[3][3]->getX(),maze[3][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+5,obstacle[2]->getY()+4);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(4,maze[5][5]->getX(),maze[5][5]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+5,obstacle[3]->getY()+4);
    obstacle[3]->set_image();
    scene->addItem(obstacle[3]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","NORTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","SOUTH",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level95()
{
    initialize();
    setLevelNo(95);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level95.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(6);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(-6);
    maze[3][3]->setTileState(5);
    maze[3][5]->setTileState(1);
    maze[4][3]->setTileState(5);
    maze[4][5]->setTileState(1);
    maze[5][3]->setTileState(7);
    maze[5][5]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(2);
    maze[6][5]->setTileState(5);
    maze[6][6]->setTileState(-7);

    obstacle.push_back(new Obstacle(6,maze[2][2]->getX(),maze[2][2]->getY()));
    obstacle[0]->setPos(obstacle[0]->getX()+tileSize/14+5,obstacle[0]->getY()+4);
    obstacle[0]->set_image();
    scene->addItem(obstacle[0]);
    obstacle.push_back(new Obstacle(-6,maze[2][6]->getX(),maze[2][6]->getY()));
    obstacle[1]->setPos(obstacle[1]->getX()+tileSize/14+5,obstacle[1]->getY()+6);
    obstacle[1]->set_image();
    scene->addItem(obstacle[1]);
    obstacle.push_back(new Obstacle(5,maze[3][3]->getX(),maze[3][3]->getY()));
    obstacle[2]->setPos(obstacle[2]->getX()+tileSize/14+15,obstacle[2]->getY()+4);
    obstacle[2]->startFire();
    scene->addItem(obstacle[2]);
    obstacle.push_back(new Obstacle(5,maze[4][3]->getX(),maze[4][3]->getY()));
    obstacle[3]->setPos(obstacle[3]->getX()+tileSize/14+15,obstacle[3]->getY()+4);
    obstacle[3]->startFire();
    scene->addItem(obstacle[3]);
    obstacle.push_back(new Obstacle(5,maze[6][5]->getX(),maze[6][5]->getY()));
    obstacle[4]->setPos(obstacle[4]->getX()+tileSize/14+15,obstacle[4]->getY()+4);
    obstacle[4]->startFire();
    scene->addItem(obstacle[4]);
    obstacle.push_back(new Obstacle(7,maze[5][3]->getX(),maze[5][3]->getY()));
    obstacle[5]->setPos(obstacle[5]->getX()+tileSize/14+5,obstacle[5]->getY()+4);
    obstacle[5]->set_image();
    scene->addItem(obstacle[5]);
    obstacle.push_back(new Obstacle(-7,maze[6][6]->getX(),maze[6][6]->getY()));
    obstacle[6]->setPos(obstacle[6]->getX()+tileSize/14+5,obstacle[6]->getY()+6);
    obstacle[6]->set_image();
    scene->addItem(obstacle[6]);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();
    scene->addItem(robot);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
        sequence.push_back(new AlgorithmBlock("MOVE","EAST",3,initialY+=step));
        sequence.push_back(new AlgorithmBlock("JUMP","WEST",2,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level96()
{
    initialize();
    setLevelNo(96);
    setWindowTitle(currentPlayerName+" Level"+QString::number(getLevelNo()));
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,900,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level8/level96.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][4]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[5][4]->setTileState(2);

    robot = new Robot();
    robot->x_offset=25;
    robot->setScale(0.2);
    robot->setPos(494+robot->x_offset,100);
    scene->addItem(robot);
    setMouseTracking(true);

    Robot *partyRobot1 = new Robot();
    partyRobot1->x_offset=25;
    partyRobot1->setScale(0.2);
    partyRobot1->setPos(300+robot->x_offset,100);
    partyRobot1->startDance();
    scene->addItem(partyRobot1);

    Robot *partyRobot2 = new Robot();
    partyRobot2->x_offset=25;
    partyRobot2->setScale(0.2);
    partyRobot2->setPos(688+robot->x_offset,100);
    partyRobot2->startDance();
    scene->addItem(partyRobot2);

    Robot *partyRobot3 = new Robot();
    partyRobot3->x_offset=25;
    partyRobot3->setScale(0.2);
    partyRobot3->setPos(300+robot->x_offset,197);
    partyRobot3->startDance();
    scene->addItem(partyRobot3);

    Robot *partyRobot4 = new Robot();
    partyRobot4->x_offset=25;
    partyRobot4->setScale(0.2);
    partyRobot4->setPos(688+robot->x_offset,197);
    partyRobot4->startDance();
    scene->addItem(partyRobot4);

    Robot *partyRobot5 = new Robot();
    partyRobot5->x_offset=25;
    partyRobot5->setScale(0.2);
    partyRobot5->setPos(300+robot->x_offset,284);
    partyRobot5->startDance();
    scene->addItem(partyRobot5);

    Robot *partyRobot6 = new Robot();
    partyRobot6->x_offset=25;
    partyRobot6->setScale(0.2);
    partyRobot6->setPos(688+robot->x_offset,284);
    partyRobot6->startDance();
    scene->addItem(partyRobot6);

    Robot *partyRobot7 = new Robot();
    partyRobot7->x_offset=25;
    partyRobot7->setScale(0.2);
    partyRobot7->setPos(300+robot->x_offset,381);
    partyRobot7->startDance();
    scene->addItem(partyRobot7);

    Robot *partyRobot8 = new Robot();
    partyRobot8->x_offset=25;
    partyRobot8->setScale(0.2);
    partyRobot8->setPos(688+robot->x_offset,381);
    partyRobot8->startDance();
    scene->addItem(partyRobot8);

    Robot *partyRobot9 = new Robot();
    partyRobot9->x_offset=25;
    partyRobot9->setScale(0.2);
    partyRobot9->setPos(300+robot->x_offset,478);
    partyRobot9->startDance();
    scene->addItem(partyRobot9);

    Robot *partyRobot10 = new Robot();
    partyRobot10->x_offset=25;
    partyRobot10->setScale(0.2);
    partyRobot10->setPos(688+robot->x_offset,478);
    partyRobot10->startDance();
    scene->addItem(partyRobot10);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence.clear();
    if(sequence_copy.empty()){
        sequence.push_back(new AlgorithmBlock("START","",0,initialY));
        sequence.push_back(new AlgorithmBlock("MOVE","SOUTH",3,initialY+=step));
    }
    else{
        sequence.clear();
        for(AlgorithmBlock* b:sequence_copy){
            sequence.push_back(b);
        }
    }
    noBlocks=sequence.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        scene->addItem(sequence[i]);
    }

    //TIMER
    timer=new Timer(current_timer);
    scene->addItem(timer);
    timer->start();

    //BACK HOME BUTTONS
    back = new Button("STAGE8BACK");
    back->setPos(50,3);
    home = new Button("HOME");
    home->setPos(50,53);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(back);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level100()
{
    clearMP();
    winner=0;
    player1ingame=0;
    player2ingame=0;
    setLevelNo(100);
    setWindowTitle("Plaver vs Player Level 1");
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,1200,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level100.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[3][2]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[5][4]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(2);

    robot = new Robot();
    robot->x_offset=10;
    robot->setScale(0.15);
    robot->setPos(300+robot->x_offset,100);
    scene->addItem(robot);

    robot2 = new Robot();
    robot2->skin=1;
    robot2->setImage();
    robot2->x_offset=55;
    robot2->setScale(0.15);
    robot2->setPos(300+robot2->x_offset,100);
    scene->addItem(robot2);
    setMouseTracking(true);

    initialY = 100;
    step = 43;
    sequence1.clear();
    sequence1.push_back(new AlgorithmBlockPlayer1("START","",0,initialY));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","EAST",2,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","NORTH",2,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","SOUTH",4,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","EAST",2,initialY+=step));
    noBlocks=sequence1.size();


    initialY = 100;
    step = 43;
    sequence2.clear();
    sequence2.push_back(new AlgorithmBlockPlayer2("START","",0,initialY));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","EAST",2,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","NORTH",2,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","SOUTH",4,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","EAST",2,initialY+=step));
    noBlocks=sequence2.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        sequence1[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        scene->addItem(sequence1[i]);
        sequence2[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        scene->addItem(sequence2[i]);
    }
    currentlySelected=0;
    sequence1[1]->setSelectedImage();
    sequence1[1]->setFocus();

    currentlySelected2=0;
    sequence2[1]->setSelectedImage();
    sequence2[1]->setFocus();

    //TIMER
    //BACK HOME BUTTONS
    home = new Button("HOME");
    home->setPos(50,3);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level101()
{
    clearMP();
    winner=0;
    player1ingame=0;
    player2ingame=0;
    setLevelNo(101);
    setWindowTitle("Plaver vs Player Level 2");
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,1200,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level101.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][3]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(1);
    maze[3][6]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][3]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(2);

    robot = new Robot();
    robot->x_offset=10;
    robot->setScale(0.15);
    robot->setPos(300+robot->x_offset,100);
    scene->addItem(robot);

    robot2 = new Robot();
    robot2->skin=1;
    robot2->setImage();
    robot2->x_offset=55;
    robot2->setScale(0.15);
    robot2->setPos(300+robot2->x_offset,100);
    scene->addItem(robot2);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence1.clear();
    sequence1.push_back(new AlgorithmBlockPlayer1("START","",0,initialY));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","SOUTH",2,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","WEST",4,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","SOUTH",2,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","EAST",4,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","EAST",4,initialY+=step));
    noBlocks=sequence1.size();


    initialY = 100;
    step = 43;
    sequence2.clear();
    sequence2.push_back(new AlgorithmBlockPlayer2("START","",0,initialY));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","SOUTH",2,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","WEST",4,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","SOUTH",2,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","EAST",4,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","EAST",4,initialY+=step));
    noBlocks=sequence2.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        sequence1[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        scene->addItem(sequence1[i]);
        sequence2[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        scene->addItem(sequence2[i]);
    }
    currentlySelected=0;
    sequence1[1]->setSelectedImage();
    sequence1[1]->setFocus();

    currentlySelected2=0;
    sequence2[1]->setSelectedImage();
    sequence2[1]->setFocus();

    //TIMER
    //BACK HOME BUTTONS
    home = new Button("HOME");
    home->setPos(50,3);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::level102()
{
    clearMP();
    winner=0;
    player1ingame=0;
    player2ingame=0;
    setLevelNo(102);
    setWindowTitle("Plaver vs Player Level 3");
    scene = new QGraphicsScene();
    level_height=600;
    scene->setSceneRect(0,0,1200,level_height);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/Level/level103.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,level_height);

    tileSize = 97;
    clearEmptyMaze();
    maze[2][2]->setTileState(1);
    maze[2][4]->setTileState(1);
    maze[2][5]->setTileState(1);
    maze[2][6]->setTileState(2);
    maze[3][2]->setTileState(1);
    maze[3][4]->setTileState(1);
    maze[4][2]->setTileState(1);
    maze[4][4]->setTileState(1);
    maze[4][5]->setTileState(1);
    maze[4][6]->setTileState(1);
    maze[5][2]->setTileState(1);
    maze[5][6]->setTileState(1);
    maze[6][2]->setTileState(1);
    maze[6][3]->setTileState(1);
    maze[6][4]->setTileState(1);
    maze[6][5]->setTileState(1);
    maze[6][6]->setTileState(1);

    robot = new Robot();
    robot->x_offset=10;
    robot->setScale(0.15);
    robot->setPos(300+robot->x_offset,100);
    scene->addItem(robot);

    robot2 = new Robot();
    robot2->skin=1;
    robot2->setImage();
    robot2->x_offset=55;
    robot2->setScale(0.15);
    robot2->setPos(300+robot2->x_offset,100);
    scene->addItem(robot2);
    setMouseTracking(true);

    cursor = new AlgorithmBlock("","",0,0);

    initialY = 100;
    step = 43;
    sequence1.clear();
    sequence1.push_back(new AlgorithmBlockPlayer1("START","",0,initialY));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","NORTH",2,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","WEST",2,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","SOUTH",4,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","EAST",2,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","EAST",4,initialY+=step));
    sequence1.push_back(new AlgorithmBlockPlayer1("MOVE","NORTH",2,initialY+=step));
    noBlocks=sequence1.size();


    initialY = 100;
    step = 43;
    sequence2.clear();
    sequence2.push_back(new AlgorithmBlockPlayer2("START","",0,initialY));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","NORTH",2,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","WEST",2,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","SOUTH",4,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","EAST",2,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","EAST",4,initialY+=step));
    sequence2.push_back(new AlgorithmBlockPlayer2("MOVE","NORTH",2,initialY+=step));
    noBlocks=sequence2.size();

    initialY=100;

    for(int i=0;i<noBlocks;i++){
        sequence1[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        scene->addItem(sequence1[i]);
        sequence2[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        scene->addItem(sequence2[i]);
    }
    currentlySelected=0;
    sequence1[1]->setSelectedImage();
    sequence1[1]->setFocus();

    currentlySelected2=0;
    sequence2[1]->setSelectedImage();
    sequence2[1]->setFocus();

    //TIMER
    //BACK HOME BUTTONS
    home = new Button("HOME");
    home->setPos(50,3);
    volume = new Button("VOLUME");
    volume->setPos(120,3);
    scene->addItem(home);
    scene->addItem(volume);
    show();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(player1ingame!=1){
        if(event->key() == Qt::Key_Space){
            startMulitplayerGame1();
        }
        if(event->key() == Qt::Key_E){
            if(currentlySelected!=0){
                index1=currentlySelected;
                currentlySelected=0;
                drawMulitplayer();
                sequence1[index1]->setSelectedImage();
            }
            else{
                currentlySelected=index1;
                sequence1[currentlySelected]->setSelectedImage();
                sequence1[currentlySelected]->setX(55);
            }
        }
        if(event->key() == Qt::Key_W){
            if(currentlySelected>1 &&currentlySelected < sequence1.size()){
                sequence1[currentlySelected-1]->setY(sequence1[currentlySelected]->getY());
                sequence1[currentlySelected]->setY(sequence1[currentlySelected]->getY()-43);
                sequence1.move(currentlySelected,currentlySelected-1);
                drawMulitplayer();

                sequence1[currentlySelected-1]->setSelectedImage();
                sequence1[currentlySelected-1]->setX(55);
                currentlySelected=currentlySelected-1;
                index1=currentlySelected;
            }
            else if(currentlySelected==0){
                index1=index1-1;
                drawMulitplayer();
                if(index1<=1){
                    index1=1;
                }
                sequence1[index1]->setSelectedImage();
            }
        }
        if(event->key() == Qt::Key_S){
            if(currentlySelected>0 &&currentlySelected < sequence1.size()-1){
                sequence1[currentlySelected+1]->setY(sequence1[currentlySelected]->getY());
                sequence1[currentlySelected]->setY(sequence1[currentlySelected]->getY()+43);
                sequence1.move(currentlySelected,currentlySelected+1);
                drawMulitplayer();

                sequence1[currentlySelected+1]->setSelectedImage();
                sequence1[currentlySelected+1]->setX(55);
                currentlySelected=currentlySelected+1;
                index1=currentlySelected;
            }
            else if(currentlySelected==0){
                index1=index1+1;
                drawMulitplayer();
                if(index1>sequence1.size()-1){
                    index1=sequence1.size()-1;
                }
                sequence1[index1]->setSelectedImage();
            }
        }
    }

    if(player2ingame!=1){
        if(event->key() == Qt::Key_0){
            qDebug()<<"GOT HERE";
            startMulitplayerGame2();
        }
        if(event->key() == Qt::Key_Shift){
            if(currentlySelected2!=0){
                index2=currentlySelected2;
                currentlySelected2=0;
                drawMulitplayer2();
                sequence2[index2]->setSelectedImage();
            }
            else{
                currentlySelected2=index2;
                sequence2[currentlySelected2]->setSelectedImage();
                sequence2[currentlySelected2]->setX(955);
            }
        }
        if(event->key() == Qt::Key_Up){
            if(currentlySelected2>1 &&currentlySelected2 < sequence2.size()){
                sequence2[currentlySelected2-1]->setY(sequence2[currentlySelected2]->getY());
                sequence2[currentlySelected2]->setY(sequence2[currentlySelected2]->getY()-43);
                sequence2.move(currentlySelected2,currentlySelected2-1);
                drawMulitplayer2();

                sequence2[currentlySelected2-1]->setSelectedImage();
                sequence2[currentlySelected2-1]->setX(955);
                currentlySelected2=currentlySelected2-1;
                index2=currentlySelected2;
            }
            else if(currentlySelected2==0){
                index2=index2-1;
                drawMulitplayer2();
                if(index2<=1){
                    index2=1;
                }
                sequence2[index2]->setSelectedImage();
            }
        }
        if(event->key() == Qt::Key_Down){
            if(currentlySelected2>0 &&currentlySelected2 < sequence2.size()-1){
                sequence2[currentlySelected2+1]->setY(sequence2[currentlySelected2]->getY());
                sequence2[currentlySelected2]->setY(sequence2[currentlySelected2]->getY()+43);
                sequence2.move(currentlySelected2,currentlySelected2+1);
                drawMulitplayer2();

                sequence2[currentlySelected2+1]->setSelectedImage();
                sequence2[currentlySelected2+1]->setX(955);
                currentlySelected2=currentlySelected2+1;
                index2=currentlySelected2;
            }
            else if(currentlySelected2==0){
                index2=index2+1;
                drawMulitplayer2();
                if(index2>sequence2.size()-1){
                    index2=sequence2.size()-1;
                }
                sequence2[index2]->setSelectedImage();
            }
        }
        qDebug()<<currentlySelected<<index1<<"::::"<<currentlySelected2<<index2;
    }
}

void Game::drawMulitplayer()
{
    for(int i=0;i<noBlocks;i++){
        qDebug()<<sequence1[i]->getDirection();
        sequence1[i]->setPos(48,sequence1[i]->getY());
        sequence1[i]->setImage();
    }
}


void Game::drawMulitplayer2()
{
    for(int i=0;i<noBlocks;i++){
        qDebug()<<sequence2[i]->getDirection();
        sequence2[i]->setPos(948,sequence2[i]->getY());
        sequence2[i]->setImage();
    }
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        if(event->pos().y()<level_height-step &&event->pos().y()>0){
            cursor->setPos(48,event->pos().y());
            cursor->setY(event->pos().y());
        }
        for(int i=0;i<14;i++){
            for(int j=0; j<14;j++){
                maze[i][j]->check(event->pos());
            }
        }
    }
}



void Game::finish(bool gameOver)
{
    if(gameOver){
        if(getLevelNo()<100){
            sequence_copy.clear();
            qDebug()<<"GJ";
            hintShown=false;
            qDebug()<<getLevelNo()+1;
            user->addTime(getLevelNo(),timer->timer);
            user->read_current_user_level();

            qDebug()<<"RESULTS "<<user->user_score;
            timer->end();
            current_timer=0;
            get_high_score(getLevelNo());
            //createLevel(getLevelNo()+1);
        }
        else{
            qDebug()<<"GJ";
            hintShown=false;
            high_score->display_high_score(getLevelNo(),winner);
        }
    }
    else{
        if(getLevelNo()<100){
            qDebug()<<"OOF";
            //mainWindow = new MainWindow();
            //mainWindow->setVisible(true);
            sequence_copy.clear();
            for(AlgorithmBlock* b:sequence){
                sequence_copy.push_back(b);
                b->setImage();
                b->newlyPlaced=0;
                b->setStart(0);
            }
            robot->stop();
            current_timer=timer->timer;
            robot=nullptr;
            sequence.clear();
            restart();
        }
        else{
            hintShown=false;
            high_score->display_high_score(getLevelNo(),winner);
        }
    }
}


void Game::get_high_score(int i)
{
    high_score->display_high_score(i);
    high_score->setVisible(true);
}

void Game::startGame()
{
    //disables block selection
    timer->end();
    qDebug()<<timer->timer;
    for(AlgorithmBlock* b:sequence){
        b->newlyPlaced=1;
        b->setImage();
        b->setStart(1);
        b->setPos(48,b->getY());
    }
    //starts sequence
    robot->startSequence(sequence,maze,obstacle);

}

void Game::startMulitplayerGame1()
{
    //disables block selection
    for(AlgorithmBlockPlayer1* b:sequence1){
        b->newlyPlaced=1;
        b->setImage();
        b->setStart(1);
        b->setPos(48,b->getY());
    }
    //starts sequence
    player1ingame=1;
    robot->startSequence1(sequence1,maze,obstacle);

}
void Game::startMulitplayerGame2()
{
    //disables block selection
    for(AlgorithmBlockPlayer2* b:sequence2){
        b->newlyPlaced=1;
        b->setImage();
        b->setStart(1);
        b->setPos(948,b->getY());
    }
    //starts sequence
    player2ingame=1;
    robot2->startSequence2(sequence2,maze,obstacle);

}
