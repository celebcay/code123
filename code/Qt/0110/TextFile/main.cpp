#include <QCoreApplication>
#include <QFile>
#include <QtDebug>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("data.txt");
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&file);
        out<<QObject::tr("Score:")<<qSetFieldWidth(10)<<left<<90<<endl;
    }
    /*if (file.open(QIODevice::ReadOnly)) {
        char buf[2024];
        qint64 lineLen = file.readLine(buf, sizeof (buf));
        if (lineLen != -1) {
            qDebug()<<buf;
        }
    }*/

    return a.exec();
}
