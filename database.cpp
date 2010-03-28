/*
    HyperRoam - CybeRoam client with automatic account switching
    Copyright (C) 2009-10  Ravi Vagadia

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//HypeRoam
#include <database.h>
//Qt
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

/*Database Code is not removed just in case someone wants to use RDBMS to store login credentials */

database::database()
{
    settings = new QSettings("HyperTech", "HypeRoam");
  /*  if (db.isDriverAvailable("QSQLITE"))
    {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    db.open();
    db.isDriverAvailable("QSQLITE");
    initDatabase();

    }
    else
    {
       QMessageBox msg;
       msg.setText("QSLITE Driver Not Available");
       msg.exec();
    }
    */
 }

void database::addUser(QString uid, QString pwd)
{
      /*      QSqlQuery query;
            query.prepare("INSERT INTO users VALUES (:uid, :password)");
            query.bindValue(":uid", uid);
            query.bindValue(":password", pwd);
            if(query.exec())  qDebug()<<"User Added "<< uid;
      */
       settings->setValue(QString("users/").append(uid),pwd);
}


QString database::getPassword(QString uid)
{
    /*QSqlQuery query;
    query.prepare("select password from users where uname = :uid");
    query.bindValue(":uid", uid);
    query.exec();
    query.next();
    return query.value(0).toString();
    */
    return settings->value(QString("users/").append(uid)).toString();
}

void database::removeUser(QString uid)
{
            /*QSqlQuery query;
            query.prepare("delete from users where uname =:uid");
            query.bindValue(":uid", uid);
            query.exec();
            qDebug()<< "User Nuked :" << uid;
            */
    settings->remove(QString("users/").append(uid));
}

QSqlQuery database::populate()
{

    QSqlQuery query("SELECT * FROM users");
    return query;
}

int database::getRandom(int max)
{
    //srand ( time(NULL) );
    return rand() % max + 1;
}

void database::initDatabase()
{
    QSqlQuery query("create table if not exists users (uname text, password text);");
    query.exec();
}

bool database::userExists(QString uid)
{
    bool exists = false;
    settings->sync();
    settings->beginGroup("users");
    QStringList keys = settings->allKeys();
    foreach (QString str, keys)
      {
        if (uid.compare(str) == 0)
        {
           exists = true;
        }

       }

    settings->endGroup();
    qDebug()<<exists;
    return exists;
}
