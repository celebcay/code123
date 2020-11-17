/*
 * File Name: Hello
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年11月17日
 */

#ifndef HELLO_H
#define HELLO_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

namespace Ui {
class Hello;
}

class Hello : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hello(QWidget *parent = nullptr);
    ~Hello();
    void CreateLable();
    void CreateButton(QApplication& app);
    void CreateWidget();

private:
    Ui::Hello *ui;
};

#endif // HELLO_H
