#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    enum Shape{
        Line,
        Rectangle,
        RoundRect,
        Ellipse,
        Polygon,
        Polyline,
        Points,
        Arc,
        Path,
        Text,
        Pixmap
    };
    explicit PaintArea(QWidget *parent = nullptr);
    void SetShape(Shape);
    void SetPen(QPen);
    void SetBrush(QBrush);
    void SetFillRule(Qt::FillRule);
    void paintEvent(QPaintEvent*);

signals:

public slots:
private:
    Shape shape;
    QPen pen;
    QBrush brush;
    Qt::FillRule fillRule;
};

#endif // PAINTAREA_H
