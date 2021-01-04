#include "digiclock.h"
#include <QTime>
#include <QTimer>
#include <QMouseEvent>

DigiClock::DigiClock(QWidget *parent)
    : QLCDNumber(parent)
{
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::blue);
    setPalette(p);
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowTime()));
    timer->start(1000);
    ShowTime();
    resize(150, 60);
    showColon = true;
}

DigiClock::~DigiClock()
{

}

void DigiClock::MousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    if (event->button() == Qt::RightButton) {
        close();
    }
}

void DigiClock::MouseMoveEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void DigiClock::ShowTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if (showColon) {
        text[2] = ':';
        showColon = false;
    } else {
        text[2] = ' ';
        showColon = true;
    }
    display(text);
}
