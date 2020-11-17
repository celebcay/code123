#include "hello.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hello createLable;
    createLable.CreateLable();

    return a.exec();
}
