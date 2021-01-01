/*
 * File Name: StackedWidget
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月17日
 */

#include "stackdlg.h"
#include <QHBoxLayout>

StackDlg::StackDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("StackedWidget"));
    list = new QListWidget(this);
    list->insertItem(0, tr("Windows1"));
    list->insertItem(1, tr("Windows2"));
    list->insertItem(2, tr("Windows3"));

    label1 = new QLabel(tr("WindowsTest1"));
    label2 = new QLabel(tr("WindowsTest2"));
    label3 = new QLabel(tr("WindowsTest3"));

    stack = new QStackedWidget(this);

    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack, 0, Qt::AlignCenter);
    mainLayout->setStretchFactor(list, 1); // 可伸缩控件
    mainLayout->setStretchFactor(stack, 3);

    connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
}

StackDlg::~StackDlg()
{

}
