#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("HZtu201215", 12);
    a.setFont(font);

    // 主分割窗口
    QSplitter* splitterMain = new QSplitter(Qt::Horizontal, 0);

    QTextEdit* textLeft = new QTextEdit(QObject::tr("Left Widget"));
    textLeft->setAlignment(Qt::AlignCenter);

    QSplitter* splitterRight = new QSplitter(Qt::Vertical, splitterMain);
    splitterRight->setOpaqueResize(false);

    QTextEdit* textUp = new QTextEdit(QObject::tr("Top Widget"));
    textUp->setAlignment(Qt::AlignCenter);

    QTextEdit* textBottom = new QTextEdit(QObject::tr("Bottom Widget"));
    textBottom->setAlignment(Qt::AlignCenter);

    splitterMain->setStretchFactor(1, 1);
    splitterMain->setWindowTitle(QObject::tr("Splitter"));
    splitterMain->show();

//    MainWindow w;
//    w.show();

    return a.exec();
}
