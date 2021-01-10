#include "datedelegate.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>
#include <QFile>
#include <QTextStream>
#include "combodelegate.h"
#include "spindelegate.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStandardItemModel model(4, 4);
    QTableView tableView;
    tableView.setModel(&model);
    ComboDelegate comboDelegate;
    DateDelegate dateDelegate;
    SpinDelegate spindelegate;
    tableView.setItemDelegateForColumn(1, &dateDelegate);
    tableView.setItemDelegateForColumn(2, &comboDelegate);
    tableView.setItemDelegateForColumn(3, &spindelegate);
    model.setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));;
    model.setHeaderData(1, Qt::Horizontal, QObject::tr("Birthday"));
    model.setHeaderData(2, Qt::Horizontal, QObject::tr("Job"));
    model.setHeaderData(3, Qt::Horizontal, QObject::tr("Income"));
    QFile file("test.txt");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString line;
        model.removeRows(0, model.rowCount(QModelIndex()), QModelIndex());
        int row = 0;
        do {
            line = stream.readLine();
            if (!line.isEmpty()) {
                model.insertRows(row, 1, QModelIndex());
                QStringList pieces = line.split(",", QString::SkipEmptyParts);
                model.setData(model.index(row, 0, QModelIndex()),
                                            pieces.value(0));
                model.setData(model.index(row, 1, QModelIndex()),
                                            pieces.value(1));
                model.setData(model.index(row, 2, QModelIndex()),
                                            pieces.value(2));
                model.setData(model.index(row, 3, QModelIndex()),
                                            pieces.value(3));
                row++;
                }
        } while (!line.isEmpty());
        file.close();
    }
    tableView.setWindowTitle(QObject::tr("Delegate"));
    tableView.show();
    return a.exec();
}
