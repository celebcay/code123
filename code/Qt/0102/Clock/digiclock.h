#ifndef DIGICLOCK_H
#define DIGICLOCK_H

#include <QDialog>
#include <QLCDNumber>

class DigiClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigiClock(QWidget *parent = nullptr);
    ~DigiClock();
    void MousePressEvent(QMouseEvent*);
    void MouseMoveEvent(QMouseEvent*);
private slots:
    void ShowTime();
private:
    QPoint dragPosition;
    bool showColon;
};

#endif // DIGICLOCK_H
