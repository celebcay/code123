#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

class Butterfly : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = nullptr);
    void timerEvent(QTimerEvent*);
    QRectF boundingRect() const;
signals:
protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
               QWidget* widget);
private:
    bool up;
    QPixmap pixUp;
    QPixmap pixDown;
    qreal angle;

public slots:
};

#endif // BUTTERFLY_H
