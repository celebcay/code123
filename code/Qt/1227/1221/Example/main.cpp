#include "content.h"
#include <QApplication>
#include <QTextCodec>
#include <QSplitter>
#include <QListWidget>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("AR PL KaitiM GB", 12);
    a.setFont(font);

    QSplitter* splitterMain = new QSplitter(Qt::Horizontal, nullptr);
    splitterMain->setOpaqueResize(true);
    QListWidget* listMain = new QListWidget(splitterMain);
    listMain->insertItem(0, QObject::tr("基本信息："));
    listMain->insertItem(1, QObject::tr("联系方式："));
    listMain->insertItem(2, QObject::tr("详细资料："));

    Content* content = new Content(splitterMain);
    QObject::connect(listMain, SIGNAL(currentRowChanged(int)),
                     content->stack, SLOT(setCurrentIndex(int)));
    splitterMain->setWindowTitle(QObject::tr("修改用户资料"));
    //splitterMain->setMinimumSize(splitterMain->setMinimumSize());
    splitterMain->show();

    return a.exec();
}
