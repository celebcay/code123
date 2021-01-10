#include "drawwidget.h"
#include <QPen>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    setMinimumSize(600, 400);
}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
    startPos = e->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{
    QPainter* painter = new QPainter;
    QPen pen;
    pen.setWidth(weight);
    pen.setColor(color);
    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(startPos, e->pos());
    painter->end();
    startPos = e->pos();
    update();
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(QPoint(0, 0), *pix);
}

void DrawWidget::resizeEvent(QResizeEvent *e)
{
    if (height() > pix->height() || width() > pix->width()) {
        QPixmap* newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0, 0), *pix);
        pix = newPix;
    }
    QWidget::resizeEvent(e);
}

void DrawWidget::SetStyle(int s)
{
    style = s;
}

void DrawWidget::SetWidth(int w)
{
    weight = w;
}

void DrawWidget::SetColor(QColor c)
{
    color = c;
}

void DrawWidget::Clear()
{
    QPixmap* clearPix = new QPixmap(size());
    clearPix->fill(Qt::white);
    pix = clearPix;
    update();
}


