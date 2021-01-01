/*
 * File Name: untitled
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月13日
 */

#include "widgets.h"
#include "ui_widgets.h"

widgets::widgets(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::widgets)
{
    ui->setupUi(this);
}

widgets::~widgets()
{
    delete ui;
}
