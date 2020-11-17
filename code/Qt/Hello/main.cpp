#include "hello.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Hello createHello;
    createHello.CreateWidget();

    return app.exec();
}
