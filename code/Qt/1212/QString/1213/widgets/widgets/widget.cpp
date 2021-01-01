#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)),
            this, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->treeWidget->clear();

    QTreeWidgetItem* group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "group1");
    group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group1->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* subItem1 = new QTreeWidgetItem(group1);
    subItem1->setText(0, "subItem1");
    subItem1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem1->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* subItem2 = new QTreeWidgetItem(group1);
    subItem2->setText(0, "subItem2");
    subItem2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem2->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* subItem3 = new QTreeWidgetItem(group1);
    subItem3->setText(0, "subItem3");
    subItem3->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem3->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* subItem4 = new QTreeWidgetItem(group1);
    subItem4->setText(0, "subItem4");
    subItem4->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem4->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0, "group2");
    group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group2->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* subItem21 = new QTreeWidgetItem(group2);
    subItem21->setText(0, "subItem21");
    subItem21->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem21->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* subItem22 = new QTreeWidgetItem(group2);
    subItem22->setText(0, "subItem22");
    subItem22->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem22->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* subItem23 = new QTreeWidgetItem(group2);
    subItem23->setText(0, "subItem23");
    subItem23->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem23->setCheckState(0, Qt::Unchecked);
}

void Widget::treeItemChanged(QTreeWidgetItem* item, int column)
{
    QString itemText = item->text(0);

    if (item->checkState(0) == Qt::Checked) {
        int count = item->childCount();
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                item->child(i)->setCheckState(0, Qt::Checked);
            }
        } else {
            updateParentItem(item);
        }
    }  else if (item->checkState(0) == Qt::Unchecked) {
        int count = item->childCount();
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                item->child(i)->setCheckState(0, Qt::Unchecked);
            }
        } else {
            updateParentItem(item);
        }
    }
}

void Widget::updateParentItem(QTreeWidgetItem* item)
{
    QTreeWidgetItem* parent = item->parent();
    if (parent == nullptr) {
        return;
    }

    int selectedCount = 0;
    int childCount = parent->childCount();
    for (int i = 0; i < childCount; ++i) {
        QTreeWidgetItem* childItem = parent->child(i);
        if (childItem->checkState(0) == Qt::Checked) {
            selectedCount++;
        }
    }
    if (selectedCount <= 0) {
        parent->setCheckState(0, Qt::Unchecked);
    } else if (selectedCount > 0 && selectedCount < childCount) {
        parent->setCheckState(0, Qt::PartiallyChecked);
    } else if (selectedCount == childCount) {
        parent->setCheckState(0, Qt::Checked);
    }
}
