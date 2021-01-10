#include "flashitem.h"

FlashItem::FlashItem(QObject *parent) : QObject(parent)
{
    flash = 0;
    setFlag(QGraphicsItem::ItemIsMovable);
    startTimer(1000);
}

QRectF FlashItem::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-10 - adjust, -10 - adjust, 43 + adjust, 43 + adjust);
}

void FlashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7, -7, 40, 40);
    painter->setPen(QPen(Qt::black, 0));
    //painter->setBrush(flash ? (Qt::red) : (Qt::yellow));
    setCurrentBrush(painter);
    painter->drawEllipse(-10, -10, 40, 40);
}

void FlashItem::timerEvent(QTimerEvent *)
{
    flash++;
    if (flash == 3) {
        flash = 0;
    }

    update();
}

void FlashItem::setCurrentBrush(QPainter *painter)
{
    if (flash == 0) {
        painter->setBrush(Qt::red);
    } else if (flash == 1) {
        painter->setBrush(Qt::yellow);
    } else if (flash == 2) {
        painter->setBrush(Qt::green);
    }
}
