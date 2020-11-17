#ifndef HELLO_H
#define HELLO_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

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

private:
    Ui::Hello *ui;
};

#endif // HELLO_H
