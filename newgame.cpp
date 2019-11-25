#include "Newgame.h"
#include "ui_newgame.h"
#include <string>
#include <fstream>
#include  <iostream>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QObject>
#include "mainwindow.h"
#include "user.h"
#include "Levelselection.h"

using namespace std;
QString newUserfilename;
extern QString currentPlayerName;
extern LevelSelection *levelSelectionScreen;
extern MainWindow *mainWindow;

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    ui->accountExistsLabel->setVisible(false);

  //Just incase you need to convert from string to qstring
  //  std::string str = "Hello world";
  //  QString qstr = QString::fromStdString(str);

    ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
}

NewGame::~NewGame()
{
    delete ui;
}


void NewGame::on_pushButton_clicked()
{
    ui->accountExistsLabel->setVisible(false);
    if(ui->textEditName->toPlainText()!=NULL){
        QString name =   ui->textEditName->toPlainText();
        name = name.trimmed().toUpper();

        User *user = new User(name);
        QFile mainUserFile("Users.txt");
        QTextStream txtStreamMainUserFile(&mainUserFile);
        if(mainUserFile.open(QIODevice::ReadOnly | QIODevice::WriteOnly|QIODevice::Text))
        {
            if(!mainUserFile.exists()){
                qDebug()<<mainUserFile.fileName()<<" does not exist";
            }
            //check if the user isn't already present
            while(!txtStreamMainUserFile.atEnd()){
                if(txtStreamMainUserFile.readLine()==name){
                    ui->accountExistsLabel->setVisible(true);
                    return;
                    /*qDebug()<<"DUPLICATE NAME DETECTED, LOADING USER :"<<name;
                    User *user = new User(name);
                    user->setUsername(name);
                    user->read_current_user_level();
                    this->hide();
                    return;*/
                }
            }
            txtStreamMainUserFile<<name<<"\n";
            //  txtStream.seek(0);
            while(!txtStreamMainUserFile.atEnd()){
                qDebug()<<txtStreamMainUserFile.readLine();
            }
            mainUserFile.close();
        }
        else{
          qDebug()<<"Could not open the file";
          return;
        }
        user->read_current_user_level();
        user->setUsername(name);
        user->create_new_user();
        levelSelectionScreen->setVisible(true);
        levelSelectionScreen->display();
        mainWindow->setVisible(false);
        this->hide();
    }
    else{

    }
}
