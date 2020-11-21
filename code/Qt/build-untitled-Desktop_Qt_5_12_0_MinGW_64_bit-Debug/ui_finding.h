/********************************************************************************
** Form generated from reading UI file 'finding.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDING_H
#define UI_FINDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finding
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Finding)
    {
        if (Finding->objectName().isEmpty())
            Finding->setObjectName(QString::fromUtf8("Finding"));
        Finding->resize(400, 300);
        menuBar = new QMenuBar(Finding);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Finding->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Finding);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Finding->addToolBar(mainToolBar);
        centralWidget = new QWidget(Finding);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Finding->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Finding);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Finding->setStatusBar(statusBar);

        retranslateUi(Finding);

        QMetaObject::connectSlotsByName(Finding);
    } // setupUi

    void retranslateUi(QMainWindow *Finding)
    {
        Finding->setWindowTitle(QApplication::translate("Finding", "Finding", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finding: public Ui_Finding {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDING_H
