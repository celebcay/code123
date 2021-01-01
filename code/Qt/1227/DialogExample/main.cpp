#include "dialog.h"
#include "inputdlg.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //::setCodecForTr(QTextCodec::codecForLocale());
    Dialog w;
    w.show();

    return a.exec();
}
