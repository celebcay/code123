#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class FlashItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit FlashItem(QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void timerEvent(QTimerEvent*);
private:
    void setCurrentBrush(QPainter *painter);
    int flash;
    QTimer* timer;
signals:

public slots:
};

#endif // FLASHITEM_H
