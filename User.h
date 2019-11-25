#ifndef USER_H
#define USER_H
#include <QMediaPlayer>
#include <QFile>
#include <QMap>
#include <QPointer>

class User{
public:
    User(QString username);
    ~User();
    void create_new_user();
    void read_current_user_level();
    void add_next_level();
    void edit_level_score(int level_number, int score);

    QString getUsername() const;
    QMap<int, int> user_score;
    void setUsername(const QString &value);

    void addTime(int level,int time);

    void read_user_level();
    void deleteUser(QString username);
private:
    QString username;
};


#endif // USER_H
