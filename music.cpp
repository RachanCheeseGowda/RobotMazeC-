#include<QMediaPlayer>
#include "music.h"
#include <QtDebug>
#include <QMediaPlaylist>
#include "Game.h"

extern Game *level;

Music::Music()
{
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/Sounds/Sounds/Music/cat.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
}

Music::~Music()
{
    delete music;
    delete playlist;
}


void Music::play()
{
    is_playing=1;
    music->play();
}

void Music::mute()
{
    qDebug()<<is_playing;
    if(is_playing==1){
        music->setMuted(true);
        //level->robot->moveSound->setMuted(true);
        is_playing=0;
    }
    else if(is_playing==0){
        music->setMuted(false);
        //level->robot->moveSound->setMuted(false);
        is_playing=1;
    }
}

