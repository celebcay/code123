/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H
#define UI_HELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hello
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Hello)
    {
        if (Hello->objectName().isEmpty())
            Hello->setObjectName(QString::fromUtf8("Hello"));
        Hello->resize(400, 300);
        menuBar = new QMenuBar(Hello);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Hello->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Hello);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Hello->addToolBar(mainToolBar);
        centralWidget = new QWidget(Hello);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Hello->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Hello);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Hello->setStatusBar(statusBar);

        retranslateUi(Hello);

        QMetaObject::connectSlotsByName(Hello);
    } // setupUi

    void retranslateUi(QMainWindow *Hello)
    {
        Hello->setWindowTitle(QApplication::translate("Hello", "Hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hello: public Ui_Hello {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_H
