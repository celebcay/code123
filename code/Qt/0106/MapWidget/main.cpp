#include "mainwindow.h"
#include <QApplication>
#include "mapwidget.h"
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("ARPL KaitiM GB", 16);
    font.setBold(true);
    a.setFont(font);
    MainWindow w;
    w.show();

    return a.exec();
}
