#ifndef WIDGETS_H
#define WIDGETS_H

#include <QMainWindow>

namespace Ui {
class widgets;
}

class widgets : public QMainWindow
{
    Q_OBJECT

public:
    explicit widgets(QWidget *parent = nullptr);
    ~widgets();

private:
    Ui::widgets *ui;
};

#endif // WIDGETS_H
