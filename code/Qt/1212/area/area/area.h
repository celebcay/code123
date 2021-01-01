/*
 * File Name: area
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月12日
 */


#ifndef AREA_H
#define AREA_H

#include <QDialog>

namespace Ui {
class area;
}

class area : public QDialog
{
    Q_OBJECT

public:
    explicit area(QWidget *parent = nullptr);
    ~area();

private slots:
    void on_countButton_clicked();

    void on_radiusLineEidt_textChanged(const QString &arg1);

private:
    Ui::area *ui;
};

#endif // AREA_H
