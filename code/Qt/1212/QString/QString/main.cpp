#include "qstring.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qstring w;
    w.show();

    return a.exec();
}
