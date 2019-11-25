#include "user.h"
#include <QStringList>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

QString currentPlayerName;
int currentLevel=0;
ifstream inputFile;


User::User(QString username)
{
    this->username=username.toUpper();
    qDebug()<<this->username;
}

User::~User()
{

}


void User::create_new_user()
{
    QString user_path = username+".txt";
    qDebug()<<this->username;
    QFile file(user_path);
    if(!file.open(QFile::WriteOnly |QFile::Text))
    {
        qDebug() << " Could not open file for writing";
        return;
    }
    QTextStream out(&file);
    user_score[1]=0;
    file.flush();
    file.close();
    currentLevel=user_score.size();
}

void User::read_current_user_level()
{
    QString user_path = username+".txt";
    QFile file(user_path);
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
           QString line = in.readLine();
           QStringList s = line.split(":");
           if(user_score[s[0].toInt()]==0){
               user_score[s[0].toInt()]=s[1].toInt();
           }
           else{
               if(user_score[s[0].toInt()]>s[1].toInt()){
                   user_score[s[0].toInt()]=s[1].toInt();
               }
           }
       }
       file.close();
    }
    qDebug()<<user_score;
    currentLevel=user_score.size()+1;
    qDebug()<<currentLevel;
}

void User::read_user_level()
{
    QString user_path = username+".txt";
    QFile file(user_path);
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
           QString line = in.readLine();
           QStringList s = line.split(":");
           if(user_score[s[0].toInt()]==0){
               user_score[s[0].toInt()]=s[1].toInt();
           }
           else{
               if(user_score[s[0].toInt()]>s[1].toInt()){
                   user_score[s[0].toInt()]=s[1].toInt();
               }
           }
       }
       file.close();
    }
    qDebug()<<user_score;
}

void User::deleteUser(QString username)
{
    QString name =  username;
    name = name.trimmed().toUpper();

    vector<QString> v;
    QString tempName;

    QFile mainUserFile("Users.txt");
    QTextStream txtStreamMainUserFile(&mainUserFile);
    if(mainUserFile.open(QIODevice::ReadOnly | QIODevice::WriteOnly|QIODevice::Text))
    {
        if(!mainUserFile.exists()){
            qDebug()<<mainUserFile.fileName()<<" does not exist";
        }
        txtStreamMainUserFile<<name<<"\n";
        //  txtStream.seek(0);
        while(!txtStreamMainUserFile.atEnd()){
            tempName = txtStreamMainUserFile.readLine();
            if(tempName!=username){
                v.push_back(tempName);
            }
        }
        mainUserFile.close();
    }
    else{
      qDebug()<<"Could not open the file";
      return;
    }
    QFile mFile("temp.txt");
    if(!mFile.open(QFile::WriteOnly|QFile::Text)){
        qDebug()<< "could not open file for writing";
        return;
    }
    QString arrayNamesNonDuplicate[v.size()];
    for(int i=0; i<v.size();i++){
        if(!arrayNamesNonDuplicate->contains(v[i])){
         arrayNamesNonDuplicate[i] = v[i];
        }
    }
    QTextStream out(&mFile);
    for(int i = 0; i<v.size();i++){
        out<<arrayNamesNonDuplicate[i]<<"\n";

    }
    mFile.close();
    remove("Users.txt");
    rename("temp.txt", "Users.txt");
    remove("temp.txt");

    QString userStatsFilePathQString  = username+ ".txt";
    string userStatsFilePathString = userStatsFilePathQString.toUtf8().constData();
    const char* chr =userStatsFilePathString.c_str();
    remove(chr);

    currentPlayerName="";

}

void User::add_next_level()
{
    user_score[user_score.size()+1]=0;
}

void User::edit_level_score(int level_number,int score)
{
    user_score[level_number]=score;
}


QString User::getUsername() const
{
    return username;
}

void User::setUsername(const QString &value)
{
    username = value;
    currentPlayerName = username;
}

void User::addTime(int level, int time)
{
    //From what I can tell, this method writes to the textfile
    QString filepath = currentPlayerName+".txt";
    int medalColour = 0;
    if(time<30){
        medalColour = 3;
    }
    if(time>=30&&time<60){
        medalColour = 2;
    }
    if(time>=60){
        medalColour = 1;
    }
    QFile userFile(filepath);
    QTextStream txtStreamUserFile(&userFile);
    if(userFile.open(QIODevice::ReadOnly | QIODevice::WriteOnly|QIODevice::Text))
    {
        if(!userFile.exists()){
            qDebug()<<userFile.fileName()<<" does not exist";
        }
        qDebug()<<level<<time;
        txtStreamUserFile<<level<<":"<<(time)<<":"<<medalColour<<"\n";
        //  txtStream.seek(0);


    while(!txtStreamUserFile.atEnd()){
        qDebug()<<txtStreamUserFile.readLine();
    }
    userFile.close();
    }
    else{
        qDebug()<<"Could not open the file";
        return;
    }

}
