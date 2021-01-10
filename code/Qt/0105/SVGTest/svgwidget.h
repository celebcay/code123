#ifndef SVGWIDGET_H
#define SVGWIDGET_H

#include <QWidget>
#include <QtSvg>
#include <QSvgWidget>
#include <QSvgRenderer>

class SvgWidget : public QSvgWidget
{
    Q_OBJECT
public:
    explicit SvgWidget(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent*);

signals:

public slots:
private:
    QSvgRenderer* render;
};

#endif // SVGWIDGET_H
