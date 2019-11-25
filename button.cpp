#include "Button.h"
#include "mainwindow.h"
#include <QtDebug>
#include "Game.h"
#include "music.h"
#include "Levelselection.h"
#include "highscore.h"
#include "User.h"
#include "obstacle.h"
#include "stage1.h"
#include "Stage2.h"
#include "stage3.h"
#include "Stage4.h"
#include "Stage5.h"
#include "Stage6.h"
#include "Stage7.h"
#include "Stage8.h"
#include "hint.h"

Button::Button(QString button_name)
{
    this->button_name=button_name;
    set_image();
}

Button::~Button()
{

}

extern MainWindow *mainWindow;
extern Music *music;
extern Game *level;
extern int currentLevel;
extern QString currentPlayerName;
extern LevelSelection *levelSelectionScreen;
extern Stage1 *stage1Screen;
extern Stage2 *stage2Screen;
extern Stage3 *stage3Screen;
extern Stage4 *stage4Screen;
extern Stage5 *stage5Screen;
extern Stage6 *stage6Screen;
extern Stage7 *stage7Screen;
extern Stage8 *stage8Screen;
extern HighScore *high_score;
extern HighScore *menuHighScore;
extern Hint *hintScreen;
extern bool hintShown;

void Button::set_image()
{
    if(button_name=="ALGORITHMBLOCK"){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarN4S.png"));
    }
    if(button_name=="START"){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/STARTgreen.png"));
    }
    if(button_name=="BRIDGEBLOCK"){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarBS.png"));
    }
    if(button_name=="ROBOT1"){
        setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-01gold.png"));
    }
    if(button_name=="ROBOT2"){
        setPixmap(QPixmap(":/Images/Images/Robot/nadia robot-02.png"));
    }
    if(button_name=="BRIDGE"){
        setPixmap(QPixmap(":/Images/Images/Obstacles/bridge-01.png"));
    }
    if(button_name=="FIRE"){
        setPixmap(QPixmap(":/Images/Images/Obstacles/FLAMES-01.png"));
    }
    if(button_name=="PORTAL1"){
        qDebug()<<"test";
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal1.png"));
    }
    if(button_name=="PORTAL2"){
        setPixmap(QPixmap(":/Images/Images/Obstacles/portal2.png"));
    }
    if(button_name=="BRIDGE2"){
        setPixmap(QPixmap(":/Images/Images/Obstacles/bridge-04.png"));
    }
    if(button_name=="JUMP"){
        setPixmap(QPixmap(":/Images/Images/Algorithm Blocks/goldbarJS.png"));
    }
    if(button_name=="BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACK.png"));
    }
    if(button_name=="STAGE1BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACK.png"));
    }
    if(button_name=="STAGE2BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACK.png"));
    }
    if(button_name=="STAGE3BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACK.png"));
    }
    if(button_name=="STAGE4BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACK.png"));
    }
    if(button_name=="STAGE5BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACK.png"));
    }
    if(button_name=="STAGE6BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACK.png"));
    }
    if(button_name=="STAGE7BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACK.png"));
    }
    if(button_name=="STAGE8BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACK.png"));
    }
    if(button_name=="NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT1NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT2NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT10NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT12NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT13NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT14NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT25NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT28NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT39NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT49NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT54NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT85NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HINT100NEXT"){
        qDebug()<<"NEXT";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/next.png"));
    }
    if(button_name=="HOME"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOME.png"));
    }
    if(button_name=="HINTHOME"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOME.png"));
    }
    if(button_name=="STAGEHOME"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOME.png"));
    }
    if(button_name=="LSHOME"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOME.png"));
    }
    if(button_name=="HSHOME"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOME.png"));
    }
    if(button_name=="LHSHOME"){
        qDebug()<<"HERE";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOME.png"));
    }
    if(button_name=="GOLDMEDAL"){
        setPixmap(QPixmap(":/Images/Images/Medal/goldmedal.png"));
    }
    if(button_name=="SILVERMEDAL"){
        setPixmap(QPixmap(":/Images/Images/Medal/silvermedal.png"));
    }
    if(button_name=="BRONZEMEDAL"){
        setPixmap(QPixmap(":/Images/Images/Medal/bronzemedal.png"));
    }
    if(button_name=="VOLUME"){
        setScale(0.05);
        if(music->is_playing){
            setPixmap(QPixmap(":/Images/Images/Buttons/volume.png"));
        }
        else{
            set_selected_image();
        }
    }

    if(button_name=="STAGE1"){
        setScale(0.9);
        setOpacity(0.01);
        setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
    }
    if(button_name=="STAGE2"){
        setScale(0.65);
        setOpacity(0.5);
        if(currentLevel<=12){
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1lock.png"));
        }
        else{
            setOpacity(0.01);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE3"){
        setScale(0.7);
        setOpacity(0.5);
        if(currentLevel<=24){
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1lock.png"));
        }
        else{
            setOpacity(0.01);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE4"){
        setOpacity(0.5);
        if(currentLevel<=36){
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1lock.png"));
        }
        else{
            setOpacity(0.01);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE5"){
        setScale(1.75);
        setOpacity(0.5);
        if(currentLevel<=48){
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1lock.png"));
        }
        else{
            setOpacity(0.01);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE6"){
        setOpacity(0.5);
        setScale(0.7);
        if(currentLevel<=60){
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1lock.png"));
        }
        else{
            setOpacity(0.01);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }

    if(button_name=="STAGE7"){
        setOpacity(0.5);
        setScale(0.7);
        if(currentLevel<=72){
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1lock.png"));
        }
        else{
            setOpacity(0.01);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE8"){
        setOpacity(0.5);
        setScale(0.97);
        if(currentLevel<=84){
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1lock.png"));
        }
        else{
            setOpacity(0.01);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }

    if(button_name=="LEVEL1"){
        setScale(0.35);
        setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold1.png"));
    }
    if(button_name=="LEVEL2"){
        setScale(0.35);
        if(currentLevel>1){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold2.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL3"){
        setScale(0.35);
        if(currentLevel>2){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold3.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL4"){
        setScale(0.35);
        if(currentLevel>3){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold4.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL5"){
        setScale(0.35);
        if(currentLevel>4){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold5.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL6"){
        setScale(0.35);
        if(currentLevel>5){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold6.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL7"){
        setScale(0.35);
        if(currentLevel>6){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold7.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL8"){
        setScale(0.35);
        if(currentLevel>7){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold8.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL9"){
        setScale(0.35);
        if(currentLevel>8){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold9.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL10"){
        setScale(0.35);
        if(currentLevel>9){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold10.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL11"){
        setScale(0.35);
        if(currentLevel>10){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold11.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL12"){
        setScale(0.35);
        if(currentLevel>11){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold12.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }

    if(button_name=="LEVEL13"){
        setScale(0.35);
        if(currentLevel>12){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold13.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL14"){
        setScale(0.35);
        if(currentLevel>13){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold14.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL15"){
        setScale(0.35);
        if(currentLevel>14){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold15.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL16"){
        setScale(0.35);
        if(currentLevel>15){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold16.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL17"){
        setScale(0.35);
        if(currentLevel>16){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold17.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL18"){
        setScale(0.35);
        if(currentLevel>17){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold18.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL19"){
        setScale(0.35);
        if(currentLevel>18){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold19.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL20"){
        setScale(0.35);
        if(currentLevel>19){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold20.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL21"){
        setScale(0.35);
        if(currentLevel>20){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold21.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL22"){
        setScale(0.35);
        if(currentLevel>21){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold22.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL23"){
        setScale(0.35);
        if(currentLevel>22){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold23.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL24"){
        setScale(0.35);
        if(currentLevel>23){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold24.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }

    if(button_name=="LEVEL25"){
        setScale(0.35);
        if(currentLevel>24){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold25.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL26"){
        setScale(0.35);
        if(currentLevel>25){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold26.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL27"){
        setScale(0.35);
        if(currentLevel>26){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold27.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL28"){
        setScale(0.35);
        if(currentLevel>27){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold28.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL29"){
        setScale(0.35);
        if(currentLevel>28){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold29.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL30"){
        setScale(0.35);
        if(currentLevel>29){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold30.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL31"){
        setScale(0.35);
        if(currentLevel>30){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold31.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL32"){
        setScale(0.35);
        if(currentLevel>31){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold32.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL33"){
        setScale(0.35);
        if(currentLevel>32){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold33.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL34"){
        setScale(0.35);
        if(currentLevel>33){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold34.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL35"){
        setScale(0.35);
        if(currentLevel>34){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold35.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL36"){
        setScale(0.35);
        if(currentLevel>35){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold36.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }

    if(button_name=="LEVEL37"){
        setScale(0.35);
        if(currentLevel>36){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold37.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL38"){
        setScale(0.35);
        if(currentLevel>37){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold38.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL39"){
        setScale(0.35);
        if(currentLevel>38){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold39.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL40"){
        setScale(0.35);
        if(currentLevel>39){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold40.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL41"){
        setScale(0.35);
        if(currentLevel>40){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold41.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL42"){
        setScale(0.35);
        if(currentLevel>41){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold42.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL43"){
        setScale(0.35);
        if(currentLevel>42){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold43.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL44"){
        setScale(0.35);
        if(currentLevel>43){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold44.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL45"){
        setScale(0.35);
        if(currentLevel>44){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold45.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL46"){
        setScale(0.35);
        if(currentLevel>45){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold46.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL47"){
        setScale(0.35);
        if(currentLevel>46){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold47.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL48"){
        setScale(0.35);
        if(currentLevel>47){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold48.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }

    if(button_name=="LEVEL49"){
        setScale(0.35);
        if(currentLevel>48){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold49.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL50"){
        setScale(0.35);
        if(currentLevel>49){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold50.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL51"){
        setScale(0.35);
        if(currentLevel>50){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold51.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL52"){
        setScale(0.35);
        if(currentLevel>51){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold52.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL53"){
        setScale(0.35);
        if(currentLevel>52){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold53.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL54"){
        setScale(0.35);
        if(currentLevel>53){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold54.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL55"){
        setScale(0.35);
        if(currentLevel>54){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold55.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL56"){
        setScale(0.35);
        if(currentLevel>55){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold56.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL57"){
        setScale(0.35);
        if(currentLevel>56){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold57.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL58"){
        setScale(0.35);
        if(currentLevel>57){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold58.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL59"){
        setScale(0.35);
        if(currentLevel>58){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold59.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL60"){
        setScale(0.35);
        if(currentLevel>59){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold60.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }

    if(button_name=="LEVEL61"){
        setScale(0.35);
        if(currentLevel>60){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold61.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL62"){
        setScale(0.35);
        if(currentLevel>61){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold62.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL63"){
        setScale(0.35);
        if(currentLevel>62){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold63.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL64"){
        setScale(0.35);
        if(currentLevel>63){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold64.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL65"){
        setScale(0.35);
        if(currentLevel>64){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold65.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL66"){
        setScale(0.35);
        if(currentLevel>65){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold66.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL67"){
        setScale(0.35);
        if(currentLevel>66){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold67.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL68"){
        setScale(0.35);
        if(currentLevel>67){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold68.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL69"){
        setScale(0.35);
        if(currentLevel>68){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold69.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL70"){
        setScale(0.35);
        if(currentLevel>69){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold70.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL71"){
        setScale(0.35);
        if(currentLevel>70){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold71.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL72"){
        setScale(0.35);
        if(currentLevel>71){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold72.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }

    if(button_name=="LEVEL73"){
        setScale(0.35);
        if(currentLevel>72){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold73.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL74"){
        setScale(0.35);
        if(currentLevel>73){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold74.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL75"){
        setScale(0.35);
        if(currentLevel>74){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold75.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL76"){
        setScale(0.35);
        if(currentLevel>75){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold76.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL77"){
        setScale(0.35);
        if(currentLevel>76){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold77.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL78"){
        setScale(0.35);
        if(currentLevel>77){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold78.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL79"){
        setScale(0.35);
        if(currentLevel>78){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold79.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL80"){
        setScale(0.35);
        if(currentLevel>79){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold80.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL81"){
        setScale(0.35);
        if(currentLevel>80){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold81.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL82"){
        setScale(0.35);
        if(currentLevel>81){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold82.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL83"){
        setScale(0.35);
        if(currentLevel>82){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold83.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL84"){
        setScale(0.35);
        if(currentLevel>83){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold84.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }

    if(button_name=="LEVEL85"){
        setScale(0.35);
        if(currentLevel>84){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold85.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL86"){
        setScale(0.35);
        if(currentLevel>85){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold86.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL87"){
        setScale(0.35);
        if(currentLevel>86){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold87.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL88"){
        setScale(0.35);
        if(currentLevel>87){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold88.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL89"){
        setScale(0.35);
        if(currentLevel>88){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold89.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL90"){
        setScale(0.35);
        if(currentLevel>89){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold90.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL91"){
        setScale(0.35);
        if(currentLevel>90){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold91.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL92"){
        setScale(0.35);
        if(currentLevel>91){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold92.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL93"){
        setScale(0.35);
        if(currentLevel>92){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold93.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL94"){
        setScale(0.35);
        if(currentLevel>93){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold94.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL95"){
        setScale(0.35);
        if(currentLevel>94){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold95.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }
    if(button_name=="LEVEL96"){
        setScale(0.35);
        if(currentLevel>95){
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/gold96.png"));
        }
        else{
            setPixmap(QPixmap(":/Images/Images/Level Selection Buttons/silverlock.png"));
        }
    }

}

void Button::set_selected_image()
{
    if(button_name=="BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACKblue.png"));
    }
    if(button_name=="STAGE1BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACKblue.png"));
    }
    if(button_name=="STAGE2BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACKblue.png"));
    }
    if(button_name=="STAGE3BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACKblue.png"));
    }
    if(button_name=="STAGE4BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACKblue.png"));
    }
    if(button_name=="STAGE5BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACKblue.png"));
    }
    if(button_name=="STAGE6BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACKblue.png"));
    }
    if(button_name=="STAGE7BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACKblue.png"));
    }
    if(button_name=="STAGE8BACK"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/BACKblue.png"));
    }
    if(button_name=="NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT1NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT2NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT10NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT12NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT14NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT25NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT28NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT39NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT49NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT54NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HINT85NEXT"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/nextblue.png"));
    }
    if(button_name=="HOME"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOMEblue.png"));
    }
    if(button_name=="STAGEHOME"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOMEblue.png"));
    }
    if(button_name=="HINTHOME"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOMEblue.png"));
    }
    if(button_name=="LSHOME"){
        setScale(0.13);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOMEblue.png"));
    }
    if(button_name=="HSHOME"){
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOMEblue.png"));
    }
    if(button_name=="LHSHOME"){
        qDebug()<<"HERE";
        setScale(0.3);
        setPixmap(QPixmap(":/Images/Images/Buttons/HOMEblue.png"));
    }
    if(button_name=="VOLUME"){
        setScale(0.05);
        setPixmap(QPixmap(":/Images/Images/Buttons/mute.png"));
    }

    if(button_name=="STAGE1"){
        setScale(0.85);
        setOpacity(0.5);
        setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
    }
    if(button_name=="STAGE2"){
        if(currentLevel>12){
            setScale(0.65);
            setOpacity(0.5);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE3"){
        if(currentLevel>24){
            setScale(0.7);
            setOpacity(0.5);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE4"){
        if(currentLevel>36){
            setOpacity(0.5);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE5"){
        if(currentLevel>48){
            setScale(1.75);
            setOpacity(0.5);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE6"){
        if(currentLevel>60){
            setScale(0.7);
            setOpacity(0.5);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE7"){
        if(currentLevel>72){
            setScale(0.7);
            setOpacity(0.5);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
    if(button_name=="STAGE8"){
        if(currentLevel>84){
            setScale(0.97);
            setOpacity(0.5);
            setPixmap(QPixmap(":/Images/Images/Level Selection Planets/planet1green.png"));
        }
    }
}

//DO NOT TOUCH
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    set_selected_image();
}

void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(button_name=="HOME"){
        level->robot->stop();
        mainWindow->setVisible(true);
        level->setVisible(false);
    }
    if(button_name=="HINTHOME"){
        level->robot->stop();
        mainWindow->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="STAGEHOME"){
        mainWindow->setVisible(true);
        stage1Screen->setVisible(false);
        stage2Screen->setVisible(false);
        stage3Screen->setVisible(false);
        stage4Screen->setVisible(false);
    }
    if(button_name=="LSHOME"){
        qDebug()<<"lsHOME";
        mainWindow->setVisible(true);
        levelSelectionScreen->setVisible(false);
    }
    if(button_name=="HSHOME"){
        qDebug()<<"HOME";
        menuHighScore->setVisible(false);
    }
    if(button_name=="LHSHOME"){
        mainWindow->setVisible(true);
        level->setVisible(false);
        high_score->setVisible(false);
    }
    if(button_name=="BACK"){
        if(currentPlayerName!=""){
            stage1Screen->setVisible(false);
            stage2Screen->setVisible(false);
            stage3Screen->setVisible(false);
            stage4Screen->setVisible(false);
            stage5Screen->setVisible(false);
            stage6Screen->setVisible(false);
            stage7Screen->setVisible(false);
            stage8Screen->setVisible(false);
            levelSelectionScreen->display();
            levelSelectionScreen->setVisible(true);
        }
    }
    if(button_name=="STAGE1BACK"){
        if(currentPlayerName!=""){
            for(QPointer<Obstacle> b:level->obstacle){
                b->stopFire();
            }
            level->setVisible(false);
            level->obstacle.clear();
            level->robot->stop();
            stage1Screen->display();
            stage1Screen->setVisible(true);
        }
    }
    if(button_name=="STAGE2BACK"){
        if(currentPlayerName!=""){
            for(QPointer<Obstacle> b:level->obstacle){
                b->stopFire();
            }
            level->setVisible(false);
            level->obstacle.clear();
            level->robot->stop();
            stage2Screen->display();
            stage2Screen->setVisible(true);
        }
    }
    if(button_name=="STAGE3BACK"){
        if(currentPlayerName!=""){
            for(QPointer<Obstacle> b:level->obstacle){
                b->stopFire();
            }
            level->setVisible(false);
            level->obstacle.clear();
            level->robot->stop();
            stage3Screen->display();
            stage3Screen->setVisible(true);
        }
    }
    if(button_name=="STAGE4BACK"){
        if(currentPlayerName!=""){
            for(QPointer<Obstacle> b:level->obstacle){
                b->stopFire();
            }
            level->setVisible(false);
            level->obstacle.clear();
            level->robot->stop();
            stage4Screen->display();
            stage4Screen->setVisible(true);
        }
    }
    if(button_name=="STAGE5BACK"){
        if(currentPlayerName!=""){
            for(QPointer<Obstacle> b:level->obstacle){
                b->stopFire();
            }
            level->setVisible(false);
            level->obstacle.clear();
            level->robot->stop();
            stage5Screen->display();
            stage5Screen->setVisible(true);
        }
    }
    if(button_name=="STAGE6BACK"){
        if(currentPlayerName!=""){
            for(QPointer<Obstacle> b:level->obstacle){
                b->stopFire();
            }
            level->setVisible(false);
            level->obstacle.clear();
            level->robot->stop();
            stage6Screen->display();
            stage6Screen->setVisible(true);
        }
    }
    if(button_name=="STAGE7BACK"){
        if(currentPlayerName!=""){
            for(QPointer<Obstacle> b:level->obstacle){
                b->stopFire();
            }
            level->setVisible(false);
            level->obstacle.clear();
            level->robot->stop();
            stage7Screen->display();
            stage7Screen->setVisible(true);
        }
    }
    if(button_name=="STAGE8BACK"){
        if(currentPlayerName!=""){
            for(QPointer<Obstacle> b:level->obstacle){
                b->stopFire();
            }
            level->setVisible(false);
            level->obstacle.clear();
            level->robot->stop();
            stage8Screen->display();
            stage8Screen->setVisible(true);
        }
    }
    if(button_name=="VOLUME"){
        music->mute();
        set_image();
    }
    if(button_name=="NEXT"){
        level->current_timer=0;
        hintShown=false;
        level->setVisible(false);
        level->createLevel(level->getLevelNo()+1);
        high_score->setVisible(false);
    }
    if(button_name=="HINT1NEXT"){
        level->current_timer=0;
        hintShown=true;
        level->createLevel(1);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT2NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(2);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT10NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(10);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT12NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(12);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT13NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(13);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT14NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(16);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT25NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(25);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT28NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(28);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT39NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(39);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT49NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(49);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT54NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(54);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT85NEXT"){
        level->current_timer=0;
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(85);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="HINT100NEXT"){
        hintShown=true;
        qDebug()<<"TRUE!!";
        level->createLevel(100);
        level->setVisible(true);
        hintScreen->setVisible(false);
    }
    if(button_name=="STAGE1"){
        if(currentPlayerName!=""&&currentLevel>=1){
            setOpacity(0.1);
            stage1Screen->display();
            levelSelectionScreen->setVisible(false);
        }
    }
    if(button_name=="STAGE2"){
        if(currentPlayerName!=""&&currentLevel>12){
            setOpacity(0.1);
            stage2Screen->display();
            levelSelectionScreen->setVisible(false);
        }
    }
    if(button_name=="STAGE3"){
        if(currentPlayerName!=""&&currentLevel>24){
            setOpacity(0.1);
            stage3Screen->display();
            levelSelectionScreen->setVisible(false);
        }
    }
    if(button_name=="STAGE4"){
        if(currentPlayerName!=""&&currentLevel>36){
            setOpacity(0.1);
            stage4Screen->display();
            levelSelectionScreen->setVisible(false);
        }
    }
    if(button_name=="STAGE5"){
        if(currentPlayerName!=""&&currentLevel>48){
            setOpacity(1.5);
            stage5Screen->display();
            levelSelectionScreen->setVisible(false);
        }
    }
    if(button_name=="STAGE6"){
        if(currentPlayerName!=""&&currentLevel>60){
            setOpacity(1.5);
            stage6Screen->display();
            levelSelectionScreen->setVisible(false);
        }
    }
    if(button_name=="STAGE7"){
        if(currentPlayerName!=""&&currentLevel>72){
            setOpacity(1.5);
            stage7Screen->display();
            levelSelectionScreen->setVisible(false);
        }
    }
    if(button_name=="STAGE8"){
        if(currentPlayerName!=""&&currentLevel>84){
            setOpacity(1.5);
            stage8Screen->display();
            levelSelectionScreen->setVisible(false);
        }
    }

    if(button_name=="LEVEL1"){
        if(currentPlayerName!=""&&currentLevel>=1){
            qDebug()<<"LEVEL1";
            hintScreen->level1Hint();
            hintScreen->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL2"){
        if(currentPlayerName!=""&&currentLevel>=2){
            qDebug()<<"LEVEL2";
            hintScreen->level2Hint();
            hintScreen->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL3"){
        if(currentPlayerName!=""&&currentLevel>=3){
            qDebug()<<"LEVEL3";
            level->createLevel(3);
            level->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL4"){
        if(currentPlayerName!=""&&currentLevel>=4){
            qDebug()<<"LEVEL4";
            level->createLevel(4);
            level->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL5"){
        if(currentPlayerName!=""&&currentLevel>=5){
            qDebug()<<"LEVEL5";
            level->createLevel(5);
            level->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL6"){
        if(currentPlayerName!=""&&currentLevel>=6){
            qDebug()<<"LEVEL6";
            level->createLevel(6);
            level->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL7"){
        if(currentPlayerName!=""&&currentLevel>=7){
            qDebug()<<"LEVEL7";
            level->createLevel(7);
            level->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL8"){
        if(currentPlayerName!=""&&currentLevel>=8){
            qDebug()<<"LEVEL8";
            level->createLevel(8);
            level->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL9"){
        if(currentPlayerName!=""&&currentLevel>=9){
            qDebug()<<"LEVEL9";
            hintScreen->level10Hint();
            level->createLevel(9);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL10"){
        if(currentPlayerName!=""&&currentLevel>=10){
            qDebug()<<"LEVEL10";
            hintScreen->level10Hint();
            hintScreen->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL11"){
        if(currentPlayerName!=""&&currentLevel>=11){
            qDebug()<<"LEVEL11";
            level->createLevel(11);
            level->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL12"){
        if(currentPlayerName!=""&&currentLevel>=12){
            qDebug()<<"LEVEL12";
            hintScreen->level12Hint();
            hintScreen->setVisible(true);
            stage1Screen->setVisible(false);
        }
    }

    if(button_name=="LEVEL13"){
        if(currentPlayerName!=""&&currentLevel>=13){
            qDebug()<<"LEVEL13";
            hintScreen->level13Hint();
            hintScreen->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL14"){
        if(currentPlayerName!=""&&currentLevel>=14){
            qDebug()<<"LEVEL14";
            level->createLevel(14);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL15"){
        if(currentPlayerName!=""&&currentLevel>=15){
            qDebug()<<"LEVEL15";
            level->createLevel(15);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL16"){
        if(currentPlayerName!=""&&currentLevel>=16){
            qDebug()<<"LEVEL16";
            hintScreen->level14Hint();
            hintScreen->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL17"){
        if(currentPlayerName!=""&&currentLevel>=17){
            qDebug()<<"LEVEL17";
            level->createLevel(17);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL18"){
        if(currentPlayerName!=""&&currentLevel>=18){
            qDebug()<<"LEVEL18";
            level->createLevel(18);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL19"){
        if(currentPlayerName!=""&&currentLevel>=19){
            qDebug()<<"LEVEL19";
            level->createLevel(19);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL20"){
        if(currentPlayerName!=""&&currentLevel>=20){
            qDebug()<<"LEVEL20";
            level->createLevel(20);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL21"){
        if(currentPlayerName!=""&&currentLevel>=21){
            qDebug()<<"LEVEL21";
            level->createLevel(21);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL22"){
        if(currentPlayerName!=""&&currentLevel>=22){
            qDebug()<<"LEVEL22";
            level->createLevel(22);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL23"){
        if(currentPlayerName!=""&&currentLevel>=23){
            qDebug()<<"LEVEL23";
            level->createLevel(23);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL24"){
        if(currentPlayerName!=""&&currentLevel>=24){
            qDebug()<<"LEVEL24";
            level->createLevel(24);
            level->setVisible(true);
            stage2Screen->setVisible(false);
        }
    }

    if(button_name=="LEVEL25"){
        if(currentPlayerName!=""&&currentLevel>=25){
            qDebug()<<"LEVEL25";
            hintScreen->level25Hint();
            hintScreen->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL26"){
        if(currentPlayerName!=""&&currentLevel>=26){
            qDebug()<<"LEVEL26";
            level->createLevel(26);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL27"){
        if(currentPlayerName!=""&&currentLevel>=27){
            qDebug()<<"LEVEL27";
            level->createLevel(27);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL28"){
        if(currentPlayerName!=""&&currentLevel>=28){
            qDebug()<<"LEVEL28";
            hintScreen->level28Hint();
            hintScreen->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL29"){
        if(currentPlayerName!=""&&currentLevel>=29){
            qDebug()<<"LEVEL29";
            level->createLevel(29);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL30"){
        if(currentPlayerName!=""&&currentLevel>=30){
            qDebug()<<"LEVEL30";
            level->createLevel(30);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL31"){
        if(currentPlayerName!=""&&currentLevel>=31){
            qDebug()<<"LEVEL31";
            level->createLevel(31);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL32"){
        if(currentPlayerName!=""&&currentLevel>=32){
            qDebug()<<"LEVEL32";
            level->createLevel(32);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL33"){
        if(currentPlayerName!=""&&currentLevel>=33){
            qDebug()<<"LEVEL33";
            level->createLevel(33);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL34"){
        if(currentPlayerName!=""&&currentLevel>=34){
            qDebug()<<"LEVEL34";
            level->createLevel(34);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL35"){
        if(currentPlayerName!=""&&currentLevel>=35){
            qDebug()<<"LEVEL35";
            level->createLevel(35);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL36"){
        if(currentPlayerName!=""&&currentLevel>=36){
            qDebug()<<"LEVEL36";
            level->createLevel(36);
            level->setVisible(true);
            stage3Screen->setVisible(false);
        }
    }

    if(button_name=="LEVEL37"){
        if(currentPlayerName!=""&&currentLevel>=37){
            qDebug()<<"LEVEL37";
            level->createLevel(37);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL38"){
        if(currentPlayerName!=""&&currentLevel>=38){
            qDebug()<<"LEVEL38";
            level->createLevel(38);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL39"){
        if(currentPlayerName!=""&&currentLevel>=39){
            qDebug()<<"LEVEL39";
            hintScreen->level39Hint();
            hintScreen->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL40"){
        if(currentPlayerName!=""&&currentLevel>=40){
            qDebug()<<"LEVEL40";
            level->createLevel(40);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL41"){
        if(currentPlayerName!=""&&currentLevel>=41){
            qDebug()<<"LEVEL41";
            level->createLevel(41);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL42"){
        if(currentPlayerName!=""&&currentLevel>=42){
            qDebug()<<"LEVEL42";
            level->createLevel(42);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL43"){
        if(currentPlayerName!=""&&currentLevel>=43){
            qDebug()<<"LEVEL43";
            level->createLevel(43);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL44"){
        if(currentPlayerName!=""&&currentLevel>=44){
            qDebug()<<"LEVEL44";
            level->createLevel(44);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL45"){
        if(currentPlayerName!=""&&currentLevel>=45){
            qDebug()<<"LEVEL45";
            level->createLevel(45);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL46"){
        if(currentPlayerName!=""&&currentLevel>=46){
            qDebug()<<"LEVEL46";
            level->createLevel(46);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL47"){
        if(currentPlayerName!=""&&currentLevel>=47){
            qDebug()<<"LEVEL47";
            level->createLevel(47);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL48"){
        if(currentPlayerName!=""&&currentLevel>=48){
            qDebug()<<"LEVEL48";
            level->createLevel(48);
            level->setVisible(true);
            stage4Screen->setVisible(false);
        }
    }

    if(button_name=="LEVEL49"){
        if(currentPlayerName!=""&&currentLevel>=49){
            qDebug()<<"LEVEL49";
            hintScreen->level49Hint();
            hintScreen->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL50"){
        if(currentPlayerName!=""&&currentLevel>=50){
            qDebug()<<"LEVEL50";
            level->createLevel(50);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL51"){
        if(currentPlayerName!=""&&currentLevel>=51){
            qDebug()<<"LEVEL51";
            level->createLevel(51);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL52"){
        if(currentPlayerName!=""&&currentLevel>=52){
            qDebug()<<"LEVEL52";
            level->createLevel(52);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL53"){
        if(currentPlayerName!=""&&currentLevel>=53){
            qDebug()<<"LEVEL53";
            level->createLevel(53);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL54"){
        if(currentPlayerName!=""&&currentLevel>=54){
            qDebug()<<"LEVEL54";
            hintScreen->level54Hint();
            hintScreen->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL55"){
        if(currentPlayerName!=""&&currentLevel>=55){
            qDebug()<<"LEVEL55";
            level->createLevel(55);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL56"){
        if(currentPlayerName!=""&&currentLevel>=56){
            qDebug()<<"LEVEL56";
            level->createLevel(56);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL57"){
        if(currentPlayerName!=""&&currentLevel>=57){
            qDebug()<<"LEVEL57";
            level->createLevel(57);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL58"){
        if(currentPlayerName!=""&&currentLevel>=58){
            qDebug()<<"LEVEL58";
            level->createLevel(58);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL59"){
        if(currentPlayerName!=""&&currentLevel>=59){
            qDebug()<<"LEVEL59";
            level->createLevel(59);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL60"){
        if(currentPlayerName!=""&&currentLevel>=60){
            qDebug()<<"LEVEL60";
            level->createLevel(60);
            level->setVisible(true);
            stage5Screen->setVisible(false);
        }
    }

    if(button_name=="LEVEL61"){
        if(currentPlayerName!=""&&currentLevel>=61){
            qDebug()<<"LEVEL61";
            level->createLevel(61);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL62"){
        if(currentPlayerName!=""&&currentLevel>=62){
            qDebug()<<"LEVEL62";
            level->createLevel(62);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL63"){
        if(currentPlayerName!=""&&currentLevel>=63){
            qDebug()<<"LEVEL63";
            level->createLevel(63);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL64"){
        if(currentPlayerName!=""&&currentLevel>=64){
            qDebug()<<"LEVEL64";
            level->createLevel(64);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL65"){
        if(currentPlayerName!=""&&currentLevel>=65){
            qDebug()<<"LEVEL65";
            level->createLevel(65);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL66"){
        if(currentPlayerName!=""&&currentLevel>=66){
            qDebug()<<"LEVEL66";
            level->createLevel(66);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL67"){
        if(currentPlayerName!=""&&currentLevel>=67){
            qDebug()<<"LEVEL67";
            level->createLevel(67);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL68"){
        if(currentPlayerName!=""&&currentLevel>=68){
            qDebug()<<"LEVEL68";
            level->createLevel(68);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL69"){
        if(currentPlayerName!=""&&currentLevel>=69){
            qDebug()<<"LEVEL69";
            level->createLevel(69);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL70"){
        if(currentPlayerName!=""&&currentLevel>=70){
            qDebug()<<"LEVEL70";
            level->createLevel(70);
            level->setVisible(true);
            stage6Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL71"){
        if(currentPlayerName!=""&&currentLevel>=71){
            qDebug()<<"LEVEL71";
            level->createLevel(71);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL72"){
        if(currentPlayerName!=""&&currentLevel>=72){
            qDebug()<<"LEVEL72";
            level->createLevel(72);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }

    if(button_name=="LEVEL73"){
        if(currentPlayerName!=""&&currentLevel>=73){
            qDebug()<<"LEVEL73";
            level->createLevel(73);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL74"){
        if(currentPlayerName!=""&&currentLevel>=74){
            qDebug()<<"LEVEL74";
            level->createLevel(74);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL75"){
        if(currentPlayerName!=""&&currentLevel>=75){
            qDebug()<<"LEVEL75";
            level->createLevel(75);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL76"){
        if(currentPlayerName!=""&&currentLevel>=76){
            qDebug()<<"LEVEL76";
            level->createLevel(76);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL77"){
        if(currentPlayerName!=""&&currentLevel>=77){
            qDebug()<<"LEVEL77";
            level->createLevel(77);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL78"){
        if(currentPlayerName!=""&&currentLevel>=78){
            qDebug()<<"LEVEL78";
            level->createLevel(78);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL79"){
        if(currentPlayerName!=""&&currentLevel>=79){
            qDebug()<<"LEVEL79";
            level->createLevel(79);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL80"){
        if(currentPlayerName!=""&&currentLevel>=80){
            qDebug()<<"LEVEL80";
            level->createLevel(80);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL81"){
        if(currentPlayerName!=""&&currentLevel>=81){
            qDebug()<<"LEVEL81";
            level->createLevel(81);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL82"){
        if(currentPlayerName!=""&&currentLevel>=82){
            qDebug()<<"LEVEL82";
            level->createLevel(82);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL83"){
        if(currentPlayerName!=""&&currentLevel>=83){
            qDebug()<<"LEVEL83";
            level->createLevel(83);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL84"){
        if(currentPlayerName!=""&&currentLevel>=84){
            qDebug()<<"LEVEL84";
            level->createLevel(84);
            level->setVisible(true);
            stage7Screen->setVisible(false);
        }
    }

    if(button_name=="LEVEL85"){
        if(currentPlayerName!=""&&currentLevel>=85){
            qDebug()<<"LEVEL85";
            hintScreen->level85Hint();
            hintScreen->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL86"){
        if(currentPlayerName!=""&&currentLevel>=86){
            qDebug()<<"LEVEL86";
            level->createLevel(86);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL87"){
        if(currentPlayerName!=""&&currentLevel>=87){
            qDebug()<<"LEVEL87";
            level->createLevel(87);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL88"){
        if(currentPlayerName!=""&&currentLevel>=88){
            qDebug()<<"LEVEL88";
            level->createLevel(88);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL89"){
        if(currentPlayerName!=""&&currentLevel>=89){
            qDebug()<<"LEVEL89";
            level->createLevel(89);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL90"){
        if(currentPlayerName!=""&&currentLevel>=90){
            qDebug()<<"LEVEL90";
            level->createLevel(90);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL91"){
        if(currentPlayerName!=""&&currentLevel>=91){
            qDebug()<<"LEVEL91";
            level->createLevel(91);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL92"){
        if(currentPlayerName!=""&&currentLevel>=92){
            qDebug()<<"LEVEL92";
            level->createLevel(92);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL93"){
        if(currentPlayerName!=""&&currentLevel>=93){
            qDebug()<<"LEVEL93";
            level->createLevel(93);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL94"){
        if(currentPlayerName!=""&&currentLevel>=94){
            qDebug()<<"LEVEL94";
            level->createLevel(94);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL95"){
        if(currentPlayerName!=""&&currentLevel>=95){
            qDebug()<<"LEVEL95";
            level->createLevel(95);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
    if(button_name=="LEVEL96"){
        if(currentPlayerName!=""&&currentLevel>=96){
            qDebug()<<"LEVEL96";
            level->createLevel(96);
            level->setVisible(true);
            stage8Screen->setVisible(false);
        }
    }
}





QString Button::getButton_name() const
{
    return button_name;
}

void Button::setButton_name(const QString &value)
{
    button_name = value;
    set_image();
}
