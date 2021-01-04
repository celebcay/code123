#include "geometry.h"

Geometry::Geometry(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Geometry"));
    xLabel = new QLabel(tr("x():"));
    xValueLabel = new QLabel;
    yLabel = new QLabel(tr("y():"));
    yValueLabel = new QLabel;
    frmLabel = new QLabel(tr("frame:"));
    frmValueLabel = new QLabel;
    posLabel = new QLabel(tr("pos():"));
    posValueLabel = new QLabel;
    geoLabel = new QLabel(tr("geometry():"));
    geoValueLabel = new QLabel;
    widthLabel = new QLabel(tr("width():"));
    widthValueLabel = new QLabel;
    heightLabel = new QLabel(tr("height():"));
    heightValueLabel = new QLabel;
    rectLabel = new QLabel(tr("rect():"));
    rectValueLabel = new QLabel;
    sizeLabel = new QLabel(tr("size():"));
    sizeValueLabel = new QLabel;
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(xLabel, 0, 0);
    mainLayout->addWidget(xValueLabel, 0, 1);
    mainLayout->addWidget(yLabel, 1, 0);
    mainLayout->addWidget(yValueLabel, 1, 1);
    mainLayout->addWidget(frmLabel, 2, 0);
    mainLayout->addWidget(frmValueLabel, 2, 1);
    mainLayout->addWidget(posLabel, 3, 0);
    mainLayout->addWidget(posValueLabel, 3, 1);
    mainLayout->addWidget(geoLabel, 4, 0);
    mainLayout->addWidget(geoValueLabel, 4, 1);
    mainLayout->addWidget(widthLabel, 5, 0);
    mainLayout->addWidget(widthValueLabel, 5, 1);
    mainLayout->addWidget(heightLabel, 6, 0);
    mainLayout->addWidget(heightValueLabel, 6, 1);
    mainLayout->addWidget(rectLabel, 7, 0);
    mainLayout->addWidget(rectValueLabel, 7, 1);
    mainLayout->addWidget(sizeLabel, 8, 0);
    mainLayout->addWidget(sizeValueLabel, 8, 1);
    UpdateLabel();
}

Geometry::~Geometry()
{

}

void Geometry::UpdateLabel()
{
    QString xStr;
    xValueLabel->setText(xStr.setNum(x()));
    QString yStr;
    yValueLabel->setText(yStr.setNum(y()));
    QString frameStr[5];
    frameStr[0] = frameStr[1].setNum(frameGeometry().x()) + "," +
            frameStr[2].setNum(frameGeometry().y()) + "," +
            frameStr[3].setNum(frameGeometry().width()) + "," +
            frameStr[4].setNum(frameGeometry().height());
    frmValueLabel->setText(frameStr[0]);
    QString positionStr[3];
    positionStr[0] = positionStr[1].setNum(pos().x()) + "," +
            positionStr[2].setNum(pos().y());
    posValueLabel->setText(positionStr[0]);
    QString geoStr[5];
    geoStr[0] = geoStr[1].setNum(geometry().x()) + "," +
            geoStr[2].setNum(geometry().y()) + "," +
            geoStr[3].setNum(geometry().width()) + "," +
            geoStr[4].setNum(geometry().height());
    geoValueLabel->setText(geoStr[0]);
    QString wStr, hStr;
    widthValueLabel->setText(wStr.setNum(width()));
    heightValueLabel->setText(hStr.setNum(height()));
    QString rectStr[5];
    rectStr[0] = rectStr[1].setNum(rect().x()) + "," +
            rectStr[2].setNum(rect().y()) + "," +
            rectStr[3].setNum(rect().width()) + "," +
            rectStr[4].setNum(rect().height());
    rectValueLabel->setText(rectStr[0]);
    QString sizeStr[3];
    sizeStr[0] = sizeStr[1].setNum(size().width()) + "," +
            sizeStr[2].setNum(size().height());
    sizeValueLabel->setText(sizeStr[0]);
}

void Geometry::MoveEvent(QMoveEvent *)
{
    UpdateLabel();
}

void Geometry::ResizeEvent(QResizeEvent *)
{
    UpdateLabel();
}
