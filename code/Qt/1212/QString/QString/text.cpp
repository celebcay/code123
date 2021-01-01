/*
 * File Name: QString
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月12日
 */

#include <QDebug>
#include <QString>
#include <QList>

int main()
{
    QList<QString> list;
    {
        QString str("hello world");
        list << str;
    }
    qDebug() << list[0] << "hoe are you!";
    return 0;
}
