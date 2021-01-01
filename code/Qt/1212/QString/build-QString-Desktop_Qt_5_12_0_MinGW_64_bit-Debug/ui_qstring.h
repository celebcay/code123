/********************************************************************************
** Form generated from reading UI file 'qstring.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSTRING_H
#define UI_QSTRING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qstring
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qstring)
    {
        if (qstring->objectName().isEmpty())
            qstring->setObjectName(QString::fromUtf8("qstring"));
        qstring->resize(400, 300);
        menuBar = new QMenuBar(qstring);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        qstring->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qstring);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        qstring->addToolBar(mainToolBar);
        centralWidget = new QWidget(qstring);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qstring->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qstring);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        qstring->setStatusBar(statusBar);

        retranslateUi(qstring);

        QMetaObject::connectSlotsByName(qstring);
    } // setupUi

    void retranslateUi(QMainWindow *qstring)
    {
        qstring->setWindowTitle(QApplication::translate("qstring", "qstring", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qstring: public Ui_qstring {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSTRING_H
