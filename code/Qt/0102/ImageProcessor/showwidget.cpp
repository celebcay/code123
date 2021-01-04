#include "showwidget.h"
#include <QtDebug>

ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{
    imageLabel = new QLabel;
    imageLabel->setScaledContents(true);
    text = new QTextEdit;
    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(text);
    mainLayout->spacing();
    qDebug()<<"ImageProcrssor::ShowWidget()";
}
