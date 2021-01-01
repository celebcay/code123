/*
 * File Name: qmap
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月12日
 */

#include <QDebug>
#include <QCoreApplication>

void q_map_temp()
{
    QMap<QString, QString> map;
    map.insert("beijing", "111");
    map.insert("sahgbahi", "021");
    map.insert("nanjing", "025");

    QMapIterator<QString, QString> i(map);
    for (; i.hasNext();) {
        qDebug()<<" "<<i.key()<<" "<<i.next().value();
    }

    QMutableMapIterator<QString, QString> mi(map);
    if (mi.findNext("111")) {
        mi.setValue("010");
    }
    QMapIterator<QString, QString> modi(map);
    qDebug()<< " ";
    for (; modi.hasNext();) {
        qDebug()<<" "<<modi.key()<<" "<<modi.next().value();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    q_map_temp();
    return a.exec();
}
