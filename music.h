#ifndef MUSIC_H
#define MUSIC_H
#include <QObject>
#include <QMediaPlayer>
#include <QPointer>

class Music: public QObject{
    Q_OBJECT
public:
    Music();
    ~Music();
    QPointer<QMediaPlayer> music;
    QMediaPlaylist *playlist;
    void play();
    void mute();
    bool is_playing;
private:
};

#endif // MUSIC_H
