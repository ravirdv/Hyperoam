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

#include "widget.h"
#include "ui_widget.h"

//Qt
#include <QDebug>
#include <QByteArray>
#include <QSqlQuery>
#include <QThread>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();
    manager1 = new QNetworkAccessManager();
    timer = new QTimer(this);
    timer1 = new QTimer(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this, SLOT(loginFinished(QNetworkReply*)));
    connect(manager1,SIGNAL(finished(QNetworkReply*)),this, SLOT(logoutFinished(QNetworkReply*)));
    connect(timer, SIGNAL(timeout()),this, SLOT(on_switchAccount_clicked()));
    connect(timer1, SIGNAL(timeout()),this, SLOT(changeOpacity()));

    setupTray();
    settings = new QSettings("HyperTech", "HypeRoam");
    req.setUrl(QUrl("http://10.100.56.55:8090/corporate/servlet/CyberoamHTTPClient"));


    //ui->switchTimeSlider->setValue(settings->value("Time").toInt());


    //Stuff related to QSettings
        ui->disableBalloonTips->setChecked(settings->value("disableBalloonTips").toBool());
        ui->autoSwitch->setChecked(settings->value("autoSwitch").toBool());
        if(settings->value("AutoConnect").toBool() && ui->accountList->count())
            {
                ui->checkBox->setChecked(true);
                on_switchAccount_clicked();
                QTimer::singleShot(0, this, SLOT(hide()));
            }
//Initializations
    idIndex = 0;
    failCounter = 0;
    sleepTime = 3000;
    initOpacity();
    fillList();
    ui->logout->setVisible(false);
    ui->switchAccount->setVisible(false);
    ui->label_6->setText(QString::number(ui->switchTimeSlider->value()));
}

Widget::~Widget()
{
    tryLogout(uid);
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    case QEvent::WindowStateChange:
         if( isMinimized() )
             QTimer::singleShot(0, this, SLOT(hide()));
        break;
    case QEvent::Quit:
            qDebug()<<"tesT";
            //emit aboutToQuit();
        break;
    default:
        break;
    }
}

void Widget::on_addButton_clicked()
{
   if(!db.userExists(ui->username->text()))
    {
        db.addUser(ui->username->text(),ui->password->text());
        fillList();
    }else
   {
        Notify("User Already in List");
    }
}

void Widget::on_startButton_clicked()
{
        if(ui->accountList->count() > 0)
        {

            uid = ui->accountList->itemAt(0,0)->text();
            pwd = db.getPassword(uid);
            tryConnect(uid,pwd);
            if(ui->autoSwitch->isChecked())
            {
            timer->start(ui->switchTimeSlider->value() * 60000);
            hide();
            }
        }
        else
        {
            Notify("Please Add an account");
        }

}

void Widget::loginFinished(QNetworkReply*)
{
        QString s = reply->readAll();
        //qDebug()<< s;
        if (s.contains("have"))
        {
            Notify(QString("You Have Successfully Logged in using ").append(uid));
            ui->inUseLabel->setText(uid);
             mTray->setIcon ( QIcon(":/icons/connected") );
            mTray->setToolTip(QString("HypeRoam - Connected using ").append(uid));
            failCounter = 0;
            sleepTime = 3000;
        }
        else if(s.contains("Multiple+login+not+allowed"))
        {
            ui->inUseLabel->setText("Multiple login not allowed");
            tryLogout(uid);
            failCounter++;
            if(failCounter < 10) QTimer::singleShot(4000, this, SLOT(on_switchAccount_clicked()));
           // mTray->setIcon( QIcon(":/icons/switch"));
        }
        else
        {
            QTimer::singleShot(3000,this,SLOT());

            Notify("Some error :S");
            qDebug()<<s;
            mTray->setIcon( QIcon(":/icons/switch"));
            if (failCounter < 10 )
            {
                    QTimer::singleShot(sleepTime, this, SLOT(on_switchAccount_clicked()));
                    sleepTime = sleepTime * 2;
                    Notify("Account Automatically Switched");
                    failCounter++;
             }

        }
 }

void Widget::logoutFinished(QNetworkReply*)
{
    QString s = logoutReply->readAll();
    if(s.contains("You+have+successfully+logged+off"))
    {
            Notify("You have successfully logged off");
            ui->inUseLabel->setText("None");
            mTray->setIcon ( QIcon(":/icons/notConnected") );
    }
}

void Widget::tryConnect(QString id, QString pwd)
{
    reply = manager->post(req, (QString("mode=191&isAccessDenied=null&url=null&message=&username=").append(id).append("@da-iict.org&password=").append(pwd).append("&saveinfo=saveinfo&login=Login")).toLocal8Bit());
}

void Widget::tryLogout(QString id)
{
    logoutReply = manager1->post(req, (QString("mode=193&isAccessDenied=&url=&message=&username=").append(id).append("@da-iict.org&password=****&btnSubmit=Logout")).toLocal8Bit());
}

void Widget::fillList()
{
    ui->accountList->clear();
    settings->sync();
    settings->beginGroup("users");
    QStringList keys = settings->allKeys();
    foreach (QString str, keys)
      {
                      ui->accountList->addItem(str);
       }
    settings->endGroup();
}

void Widget::on_removeAccount_clicked()
{
            db.removeUser(ui->accountList->currentItem()->text());
            fillList();
}

void Widget::on_switchAccount_clicked()
{
    qDebug() << ui->accountList->selectedItems();
    if(ui->accountList->count())
    {
    if (idIndex == ui->accountList->count() - 1)
            idIndex = 0;
    else
            idIndex++;
    tryLogout(uid);
    uid = ui->accountList->item(idIndex)->text();
    tryConnect(uid,db.getPassword(uid));
    Notify(QString("Trying to Connect using ").append(uid));
    }
}

void Widget::setupTray()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    restoreAction = new QAction(tr("&Restore"), this);
    quitAction = new QAction(tr("&Quit"), this);
    switchAction = new QAction(tr("&Switch Account"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect(switchAction, SIGNAL(triggered()), this, SLOT(on_switchAccount_clicked()));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
        mTray = new QSystemTrayIcon( this );
        connect(mTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                  this, SLOT(trayActivated(QSystemTrayIcon::ActivationReason)));

        mTray->setIcon ( QIcon(":/icons/app") );
        mTray->setToolTip("HypeRoam");
        trayIconMenu = new QMenu(this);
        trayIconMenu->addAction(minimizeAction);
        trayIconMenu->addAction(restoreAction);
        trayIconMenu->addSeparator();
        trayIconMenu->addAction(switchAction);
        trayIconMenu->addAction(quitAction);
        mTray->setContextMenu(trayIconMenu);
        mTray->show();
}

void Widget::on_accountList_itemDoubleClicked(QListWidgetItem* item)
{
    on_startButton_clicked();
}

void Widget::changeOpacity()
{
   if((Opacity > 0))
    {
        ui->notificationLabel->setStyleSheet(QString("background-color: rgba(255, 85, 127, ").append(QString::number(Opacity -=2).append("%);")));
    }
    else
    {
        timer1->stop();
    }
}

void Widget::Notify(QString str)
{
    ui->notificationLabel->setText(str);
    ui->notificationLabel->setStyleSheet(QString("background-color: rgba(255, 85, 127, 100%);"));
    if(!Widget::isVisible() && !ui->disableBalloonTips->checkState())mTray->showMessage(QString("HypeRoam"), str, QSystemTrayIcon::Information , 2000);
    initOpacity();
    timer1->start(100);
}

void Widget::initOpacity()
{
    Opacity = 100;
}

void Widget::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        Notify("Auto Connect Mode Enabled");
        settings->setValue("AutoConnect",true);
    }
    else
    {
        Notify("Auto Connect Mode Disabled");
        settings->setValue("AutoConnect",false);
    }
}

void Widget::on_logout_clicked()
{
    tryLogout(ui->accountList->currentItem()->text());
}
void Widget::trayActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
        case QSystemTrayIcon::DoubleClick:
             restoreAction->trigger();
             break;
         case QSystemTrayIcon::MiddleClick:
             on_switchAccount_clicked();
             break;

}
}

void Widget::on_disableBalloonTips_toggled(bool checked)
{
    if(checked)
    {
        settings->setValue("disableBalloonTips",true);
    }
    else
    {
        settings->setValue("disableBalloonTips",false);
    }
}



void Widget::on_switchTimeSlider_valueChanged(int value)
{
    ui->label_6->setText(QString::number(value));
    settings->setValue("Time",ui->switchTimeSlider->value());
}



void Widget::on_autoSwitch_toggled(bool checked)
{
    if(checked)
    {
        settings->setValue("autoSwitch",true);
    }
    else
    {
        settings->setValue("autoSwitch",false);
    }
}
