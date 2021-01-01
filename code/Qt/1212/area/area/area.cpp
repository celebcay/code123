/*
 * File Name: area
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月12日
 */


#include "area.h"
#include "ui_area.h"
#include <QGridLayout>

namespace {
    const double PI = 3.1415926;
}

area::area(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::area)
{
    ui->setupUi(this);
}

area::~area()
{
    delete ui;
}

// 通过点击按键计算圆面积
void area::on_countButton_clicked()
{
    bool isOk = false;
    QString tempTest;
    QString valueText = ui->radiusLineEidt->text();
    int valueRadius = valueText.toInt(&isOk);
    double area = valueRadius * valueRadius * PI; // 计算面积
    ui->areaLabel2->setText(tempTest.setNum(area));
}

// 直接在文本框输入半径计算圆面积
void area::on_radiusLineEidt_textChanged(const QString &arg1)
{
    bool isOk = false;
    QString tempTest;
    QString valueText = ui->radiusLineEidt->text();
    int valueRadius = valueText.toInt(&isOk);
    double area = valueRadius * valueRadius * PI; // 计算面积
    ui->areaLabel2->setText(tempTest.setNum(area));
}
