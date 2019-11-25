#include "NextLevel.h"
#include "ui_nextlevel.h"
#include "Game.h"

NextLevel::NextLevel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextLevel)
{
    ui->setupUi(this);
}

NextLevel::~NextLevel()
{
    delete ui;
}


void NextLevel::on_pushButton_clicked()
{
    Game *level = new Game();
    level->createLevel(getLevel_number());
    this->setVisible(false);
}

int NextLevel::getLevel_number() const
{
    return level_number;
}

void NextLevel::setLevel_number(int value)
{
    level_number = value;
}
