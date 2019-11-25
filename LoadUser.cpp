#include "LoadUser.h"
#include "ui_loaduser.h"
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

LoadUser::LoadUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadUser)
{
    setWindowFlags(Qt::Window| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    ui->setupUi(this);

    ui->accountExistsLabel->setVisible(false);
    ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
}


extern QString currentPlayerName;
extern LevelSelection *levelSelectionScreen;
extern MainWindow *mainWindow;

LoadUser::~LoadUser()
{
    delete ui;
}

void LoadUser::on_pushButton_clicked()
{
    QString name =   ui->textEditName->toPlainText();
    name = name.trimmed().toUpper();

    QFile mainUserFile("Users.txt");
    QTextStream txtStreamMainUserFile(&mainUserFile);
    if(mainUserFile.open(QIODevice::ReadOnly |QIODevice::Text))
    {
        if(!mainUserFile.exists()){
            qDebug()<<mainUserFile.fileName()<<" does not exist";
        }
        //check if the user isn't already present
        while(!txtStreamMainUserFile.atEnd()){
            if(txtStreamMainUserFile.readLine()==name){
                qDebug()<<"DUPLICATE NAME DETECTED, LOADING USER :"<<name;
                User *user = new User(name);
                user->setUsername(name);
                user->read_current_user_level();
                this->hide();
                if(currentPlayerName!=""){
                    levelSelectionScreen->setVisible(true);
                    levelSelectionScreen->display();
                    mainWindow->setVisible(false);
                    this->setVisible(false);
                }
                ui->accountExistsLabel->setVisible(false);
                return;
            }
        }
        txtStreamMainUserFile<<name<<"\n";
        //  txtStream.seek(0);
        while(!txtStreamMainUserFile.atEnd()){
            qDebug()<<txtStreamMainUserFile.readLine();
        }
        ui->accountExistsLabel->setVisible(true);
        mainUserFile.close();
    }
    else{
      qDebug()<<"Could not open the file";
      return;
    }

}
