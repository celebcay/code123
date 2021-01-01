#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<int> list;
    list<<1<<2<<3<<4<<5;
    QListIterator<int> i(list);
    for (; i.hasNext();) {
        qDebug() << i.next();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
