#ifndef QSTRING_H
#define QSTRING_H

#include <QMainWindow>

namespace Ui {
class qstring;
}

class qstring : public QMainWindow
{
    Q_OBJECT

public:
    explicit qstring(QWidget *parent = nullptr);
    ~qstring();

private:
    Ui::qstring *ui;
};

#endif // QSTRING_H
