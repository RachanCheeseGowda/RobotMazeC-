#-------------------------------------------------
#
# Project created by QtCreator 2019-04-01T10:23:36
#
#-------------------------------------------------

QT       += core gui \
         multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RobotMaze
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    MainWindow.cpp \
    Robot.cpp \
    AlgorithmBlock.cpp \
    Game.cpp \
    Tile.cpp \
    Music.cpp \
    User.cpp \
    Timer.cpp \
    Button.cpp \
    Newgame.cpp \
    LevelSelection.cpp \
    HighScore.cpp \
    Text.cpp \
    Obstacle.cpp \
    Stage1.cpp \
    Stage2.cpp \
    Stage3.cpp \
    Stage4.cpp \
    Stage5.cpp \
    Stage6.cpp \
    Stage7.cpp \
    Stage8.cpp \
    Hint.cpp \
    LoadUser.cpp \
    AlgorithmBlockPlayer1.cpp \
    AlgorithmBlockPlayer2.cpp

HEADERS += \
    MainWindow.h \
    Robot.h \
    AlgorithmBlock.h \
    Game.h \
    Tile.h \
    Music.h \
    User.h \
    Timer.h \
    Button.h \
    Newgame.h \
    LevelSelection.h \
    HighScore.h \
    Text.h \
    Obstacle.h \
    Stage1.h \
    Stage2.h \
    Stage3.h \
    Stage4.h \
    Stage5.h \
    Stage6.h \
    Stage7.h \
    Stage8.h \
    Hint.h \
    LoadUser.h \
    AlgorithmBlockPlayer2.h \
    AlgorithmBlockPlayer1.h

FORMS += \
    MainWindow.ui \
    Newgame.ui \
    loaduser.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
CONFIG += resources_big
