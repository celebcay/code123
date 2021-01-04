#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include <QWidget>

class ShapeWidget : public QWidget
{
    Q_OBJECT

public:
    ShapeWidget(QWidget *parent = nullptr);
    ~ShapeWidget();
protected:
    void MousePressEvent(QMouseEvent*);
    void MouseMoveEvent(QMouseEvent*);
    void PaintEvent(QPaintEvent*);
private:
    QPoint dragPosition;
};

#endif // SHAPEWIDGET_H
