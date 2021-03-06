#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QImage>
#include <QHBoxLayout>

class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = nullptr);
    QImage img;
    QLabel* imageLabel;
    QTextEdit* text;
    QHBoxLayout* mainLayout;

signals:

public slots:
};

#endif // SHOWWIDGET_H
