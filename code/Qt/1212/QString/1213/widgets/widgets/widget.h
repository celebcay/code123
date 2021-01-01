/*
 * File Name: widgets
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月13日
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void init();
    void updateParentItem(QTreeWidgetItem* item);

public slots:
    void treeItemChanged(QTreeWidgetItem* item, int column);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
