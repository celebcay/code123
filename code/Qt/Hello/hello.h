#ifndef HELLO_H
#define HELLO_H

#include <QMainWindow>
#include <QLabel>

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

private:
    Ui::Hello *ui;
};

#endif // HELLO_H
