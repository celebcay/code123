#include "finding.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Finding w;
    w.show();

    return a.exec();
}
