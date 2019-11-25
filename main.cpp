#include "MainWindow.h"
#include <QApplication>
#include "music.h"
#include "Game.h"

Music *music;
Game *level;
Game *level2;
MainWindow *mainWindow;
int main(int argc, char *argv[])
{
    music = new Music();
    music->play();

    QApplication a(argc, argv);
    level = new Game();
    level2 = new Game();
    mainWindow = new MainWindow();
    mainWindow->show();
    //MainWindow w;
    //w.show();


    return a.exec();
}
