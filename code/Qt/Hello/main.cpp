#include "hello.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Hello createHello;
    createHello.CreateLable();
    createHello.CreateButton(app);

    return app.exec();
}
