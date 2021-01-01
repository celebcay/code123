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
    // 新建一个QSplitter类对象，作为主分割窗口，设定此分割窗口为水平分割窗口
    QSplitter* splitterMain = new QSplitter(Qt::Horizontal);

    // 新建一个QTextEdit类对象，并将其插入主分割窗口
    QTextEdit* textLeft = new QTextEdit(QObject::tr("Left Widget"), splitterMain);
    // 设置TextEdit中文字对齐方式，常用对齐方式Left、Right、Center、Up、Down
    textLeft->setAlignment(Qt::AlignCenter);
    // 新建一个QSplitter类对象，作为右分割窗口，设定次分割窗口为垂直分割窗口，并以主分割窗口为父窗口
    QSplitter* splitterRight = new QSplitter(Qt::Vertical, splitterMain);
    // 用于设定分割窗口的分割条在拖拽时是否为时时更新显示
    splitterRight->setOpaqueResize(false);

    QTextEdit* textUp = new QTextEdit(QObject::tr("Top Widget"), splitterRight);
    textUp->setAlignment(Qt::AlignCenter);

    QTextEdit* textBottom = new QTextEdit(QObject::tr("Bottom Widget"), splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);

    // 设定可伸缩控件，arg1用于指定设置的控件序号，控件序号按插入的先后次序0起，
    // arg2大于0表示此控件为可伸缩控件，当整个对话框宽度发生改变时，左边保持不变，右边进行调整
    splitterMain->setStretchFactor(1, 1);
    splitterMain->setWindowTitle(QObject::tr("Splitter"));
    splitterMain->show();

//    MainWindow w;
//    w.show();

    return a.exec();
}
