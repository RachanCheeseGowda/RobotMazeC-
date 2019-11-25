#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "Game.h"
#include "User.h"
#include "Newgame.h"
#include "Levelselection.h"
#include "highscore.h"
#include "stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"
#include "Stage6.h"
#include "Stage7.h"
#include "Stage8.h"
#include "Hint.h"
#include "music.h"
#include "LoadUser.h"

extern Game *level;
extern Game *level2;
LevelSelection *levelSelectionScreen;
Hint *hintScreen;
Stage1 *stage1Screen;
Stage2 *stage2Screen;
Stage3 *stage3Screen;
Stage4 *stage4Screen;
Stage5 *stage5Screen;
Stage6 *stage6Screen;
Stage7 *stage7Screen;
Stage8 *stage8Screen;
//Stage4 *stage4Screen;
extern int currentLevel;
extern QString currentPlayerName;
HighScore *menuHighScore;
HighScore *high_score;

extern Music *music;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    ui->pushButton_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton_7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton_8->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->pushButton_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton_12->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton_4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    menuHighScore = new HighScore();
    menuHighScore->setVisible(false);

    high_score = new HighScore();
    high_score->setVisible(false);

    levelSelectionScreen=new LevelSelection();
    levelSelectionScreen->setVisible(false);

    stage1Screen=new Stage1();
    stage1Screen->setVisible(false);

    stage2Screen=new Stage2();
    stage2Screen->setVisible(false);

    stage3Screen=new Stage3();
    stage3Screen->setVisible(false);

    stage4Screen=new Stage4();
    stage4Screen->setVisible(false);

    stage5Screen=new Stage5();
    stage5Screen->setVisible(false);

    stage6Screen=new Stage6();
    stage6Screen->setVisible(false);

    stage7Screen=new Stage7();
    stage7Screen->setVisible(false);

    stage8Screen=new Stage8();
    stage8Screen->setVisible(false);

    hintScreen=new Hint();
    hintScreen->setVisible(false);
}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_3_clicked()
{
    /*QIcon ico;
    ico.addPixmap(QPixmap(":/Images/Images/Buttons/newgameblue.png"),QIcon::Normal,QIcon::On);
    ui->pushButton_3->setIcon(ico);*/
    NewGame *new_game = new NewGame();
    new_game->show();
}



void MainWindow::on_pushButton_7_clicked()
{
    if(currentPlayerName!=""){
        levelSelectionScreen->setVisible(true);
        levelSelectionScreen->display();
        this->setVisible(false);
    }
    //LevelSelection *level = new LevelSelection();
    //level->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    menuHighScore = new HighScore();
    menuHighScore->display_high_score();
}

void MainWindow::on_pushButton_12_clicked()
{
    User *usr = new User(currentPlayerName);
    usr->deleteUser(currentPlayerName);
}

void MainWindow::on_pushButton_clicked()
{
    music->mute();
}

void MainWindow::on_pushButton_2_clicked()
{
    LoadUser *load = new LoadUser();
    load->show();
}

void MainWindow::on_pushButton_4_clicked()
{

    level->createLevel(100);
    this->setVisible(false);
}



