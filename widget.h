#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QSqlDatabase>
#include <QSystemTrayIcon>
#include <database.h>
#include <QListWidgetItem>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QSettings>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    int Opacity, idIndex, failCounter;
    unsigned int sleepTime;
    Widget(QWidget *parent = 0);
    ~Widget();
    QNetworkAccessManager *manager, *manager1;
    QNetworkRequest req;
    QNetworkReply *reply, *logoutReply;
    QString uid,pwd;
    QSystemTrayIcon *mTray;
    database db;
    QTimer *timer, *timer1;
    QMenu *trayIconMenu;
    QAction *minimizeAction, *restoreAction, *quitAction,*switchAction;
    QSettings *settings;
    bool disableBalloonTips;
protected:
    void changeEvent(QEvent *e);

private:
    Ui::Widget *ui;

    void fillList();
    void setupTray();
    void Notify(QString str);
    void initOpacity();

private slots:
    void on_autoSwitch_toggled(bool checked);
    void on_switchTimeSlider_valueChanged(int value);
    void on_disableBalloonTips_toggled(bool checked);
    void tryLogout(QString id);
    void tryConnect(QString id, QString pwd);
    void on_logout_clicked();
    void on_checkBox_toggled(bool checked);
    void on_accountList_itemDoubleClicked(QListWidgetItem* item);
    void on_switchAccount_clicked();
    void on_removeAccount_clicked();
    void on_startButton_clicked();
    void on_addButton_clicked();
    void loginFinished(QNetworkReply*);
    void logoutFinished(QNetworkReply*);
    void changeOpacity();
    void trayActivated(QSystemTrayIcon::ActivationReason reason);
};

#endif // WIDGET_H
