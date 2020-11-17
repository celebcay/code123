/*
 * File Name: Hello
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年11月17日
 */

#include "hello.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Hello createHello;
    createHello.CreateWidget();

    return app.exec();
}
