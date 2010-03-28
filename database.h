#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlResult>
#include <QVariant>
#include <QSettings>
class database
{
public:
    QSqlDatabase db;
    QSettings *settings;
    QString getPassword(QString uid);
    void addUser(QString uid, QString pwd);
    void removeUser(QString uid);
    int getRandom(int max);
    QSqlQuery populate();
    database();
    void initDatabase();
    bool userExists(QString uid);
};

#endif // DATABASE_H
