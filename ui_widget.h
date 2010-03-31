/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed Mar 31 19:43:08 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *addButton;
    QLabel *label;
    QLineEdit *username;
    QLabel *label_2;
    QLineEdit *password;
    QPushButton *startButton;
    QListWidget *accountList;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *inUseLabel;
    QPushButton *removeAccount;
    QPushButton *switchAccount;
    QLabel *label_5;
    QLabel *notificationLabel;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_8;
    QCheckBox *checkBox;
    QCheckBox *autoSwitch;
    QCheckBox *disableBalloonTips;
    QSlider *switchTimeSlider;
    QLabel *label_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(405, 343);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(405, 343));
        Widget->setMaximumSize(QSize(405, 343));
        addButton = new QPushButton(Widget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(90, 99, 95, 24));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(21, 54, 61, 16));
        username = new QLineEdit(Widget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(88, 50, 121, 25));
        username->setMaxLength(32);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(21, 77, 61, 16));
        password = new QLineEdit(Widget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(88, 73, 121, 25));
        password->setMaxLength(64);
        password->setEchoMode(QLineEdit::Password);
        startButton = new QPushButton(Widget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(10, 230, 95, 24));
        accountList = new QListWidget(Widget);
        accountList->setObjectName(QString::fromUtf8("accountList"));
        accountList->setGeometry(QRect(230, 50, 161, 141));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 197, 61, 16));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 30, 61, 16));
        inUseLabel = new QLabel(Widget);
        inUseLabel->setObjectName(QString::fromUtf8("inUseLabel"));
        inUseLabel->setGeometry(QRect(300, 197, 101, 16));
        removeAccount = new QPushButton(Widget);
        removeAccount->setObjectName(QString::fromUtf8("removeAccount"));
        removeAccount->setGeometry(QRect(90, 126, 95, 24));
        switchAccount = new QPushButton(Widget);
        switchAccount->setObjectName(QString::fromUtf8("switchAccount"));
        switchAccount->setGeometry(QRect(20, 20, 101, 24));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 164, 111, 16));
        notificationLabel = new QLabel(Widget);
        notificationLabel->setObjectName(QString::fromUtf8("notificationLabel"));
        notificationLabel->setGeometry(QRect(20, 280, 371, 20));
        notificationLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 85, 127, 0);"));
        notificationLabel->setAlignment(Qt::AlignCenter);
        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 268, 401, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 1, 401, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(Widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 300, 401, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setEnabled(false);
        label_8->setGeometry(QRect(277, 318, 121, 20));
        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(246, 246, 131, 23));
        autoSwitch = new QCheckBox(Widget);
        autoSwitch->setObjectName(QString::fromUtf8("autoSwitch"));
        autoSwitch->setGeometry(QRect(247, 225, 131, 23));
        disableBalloonTips = new QCheckBox(Widget);
        disableBalloonTips->setObjectName(QString::fromUtf8("disableBalloonTips"));
        disableBalloonTips->setGeometry(QRect(10, 310, 141, 23));
        switchTimeSlider = new QSlider(Widget);
        switchTimeSlider->setObjectName(QString::fromUtf8("switchTimeSlider"));
        switchTimeSlider->setGeometry(QRect(20, 193, 160, 20));
        switchTimeSlider->setMinimum(10);
        switchTimeSlider->setMaximum(90);
        switchTimeSlider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 164, 91, 16));
        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, addButton);
        QWidget::setTabOrder(addButton, removeAccount);
        QWidget::setTabOrder(removeAccount, startButton);
        QWidget::setTabOrder(startButton, checkBox);
        QWidget::setTabOrder(checkBox, switchAccount);
        QWidget::setTabOrder(switchAccount, accountList);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("Widget", "Add ->", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "Username", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "Password", 0, QApplication::UnicodeUTF8));
        password->setInputMask(QString());
        startButton->setText(QApplication::translate("Widget", "Login", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "In Use :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "Accounts:", 0, QApplication::UnicodeUTF8));
        inUseLabel->setText(QApplication::translate("Widget", "None", 0, QApplication::UnicodeUTF8));
        removeAccount->setText(QApplication::translate("Widget", "Remove", 0, QApplication::UnicodeUTF8));
        switchAccount->setText(QApplication::translate("Widget", "Switch Account", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "Auto Switch Time", 0, QApplication::UnicodeUTF8));
        notificationLabel->setText(QApplication::translate("Widget", "Notifications", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget", "Author: HyperDUDe", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Widget", "Connect on Starup", 0, QApplication::UnicodeUTF8));
        autoSwitch->setText(QApplication::translate("Widget", "Auto Switch", 0, QApplication::UnicodeUTF8));
        disableBalloonTips->setText(QApplication::translate("Widget", "Disable balloon tips", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "Minutes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
