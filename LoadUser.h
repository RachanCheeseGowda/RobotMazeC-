#ifndef LOADUSER_H
#define LOADUSER_H

#include <QDialog>

namespace Ui {
class LoadUser;
}

class LoadUser : public QDialog
{
    Q_OBJECT

public:
    explicit LoadUser(QWidget *parent = nullptr);
    ~LoadUser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoadUser *ui;
};

#endif // LOADUSER_H
