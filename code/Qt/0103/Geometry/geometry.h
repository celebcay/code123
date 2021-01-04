#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>

class Geometry : public QDialog
{
    Q_OBJECT

public:
    Geometry(QWidget *parent = nullptr);
    ~Geometry();
    void UpdateLabel();

private:
    QLabel* xLabel;
    QLabel* xValueLabel;
    QLabel* yLabel;
    QLabel* yValueLabel;
    QLabel* frmLabel;
    QLabel* frmValueLabel;
    QLabel* posLabel;
    QLabel* posValueLabel;
    QLabel* geoLabel;
    QLabel* geoValueLabel;
    QLabel* widthLabel;
    QLabel* widthValueLabel;
    QLabel* heightLabel;
    QLabel* heightValueLabel;
    QLabel* rectLabel;
    QLabel* rectValueLabel;
    QLabel* sizeLabel;
    QLabel* sizeValueLabel;
    QGridLayout* mainLayout;
protected:
    void MoveEvent(QMoveEvent*);
    void ResizeEvent(QResizeEvent*);
};

#endif // GEOMETRY_H
