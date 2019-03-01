/********************************************************************************
** Form generated from reading UI file 'laba1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABA1_H
#define UI_LABA1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_laba1Class
{
public:
    QAction *actionClose;
    QWidget *centralWidget;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QLabel *label_login;
    QLabel *label_password;
    QPushButton *pushButton_authorize;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *laba1Class)
    {
        if (laba1Class->objectName().isEmpty())
            laba1Class->setObjectName(QString::fromUtf8("laba1Class"));
        laba1Class->resize(600, 400);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        laba1Class->setFont(font);
        actionClose = new QAction(laba1Class);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralWidget = new QWidget(laba1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit_login = new QLineEdit(centralWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(180, 70, 113, 20));
        lineEdit_password = new QLineEdit(centralWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(180, 130, 113, 20));
        label_login = new QLabel(centralWidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(70, 62, 71, 31));
        label_password = new QLabel(centralWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(70, 120, 91, 31));
        pushButton_authorize = new QPushButton(centralWidget);
        pushButton_authorize->setObjectName(QString::fromUtf8("pushButton_authorize"));
        pushButton_authorize->setGeometry(QRect(200, 210, 101, 41));
        laba1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(laba1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        laba1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(laba1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        laba1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(laba1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        laba1Class->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionClose);

        retranslateUi(laba1Class);
        QObject::connect(actionClose, SIGNAL(triggered()), laba1Class, SLOT(close()));

        QMetaObject::connectSlotsByName(laba1Class);
    } // setupUi

    void retranslateUi(QMainWindow *laba1Class)
    {
        laba1Class->setWindowTitle(QApplication::translate("laba1Class", "laba1", nullptr));
        actionClose->setText(QApplication::translate("laba1Class", "Close", nullptr));
        label_login->setText(QApplication::translate("laba1Class", "Login:", nullptr));
        label_password->setText(QApplication::translate("laba1Class", "Password:", nullptr));
        pushButton_authorize->setText(QApplication::translate("laba1Class", "LOGIN", nullptr));
        menuFile->setTitle(QApplication::translate("laba1Class", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("laba1Class", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class laba1Class: public Ui_laba1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABA1_H
