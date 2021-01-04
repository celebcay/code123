#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "paintarea.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QGradient>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    PaintArea* paintArea;
    QLabel* shapeLabel;
    QComboBox* shapeComboBox;
    QLabel* penWidthLabel;
    QSpinBox* penWidthSpinBox;
    QLabel* penColorLabel;
    QFrame* penColorFrame;
    QPushButton* penColorButton;
    QLabel* penStyleLabel;
    QComboBox* penStyleComboBox;
    QLabel* penCapLabel;
    QComboBox* penCapComboBox;
    QLabel* penJoinLabel;
    QComboBox* penJoinComboBox;
    QLabel* fillRuleLabel;
    QComboBox* fillRuleComboBox;
    QLabel* spreadLabel;
    QComboBox* spreadComboBox;
    QGradient::Spread spread;
    QLabel* brushStyleLabel;
    QComboBox* brushStyleComboBox;
    QLabel* brushColorLabel;
    QFrame* brushColorFrame;
    QPushButton* brushColorBtn;
    QGridLayout* rightLayout;

private slots:
    void ShowShape(int);
    void ShowPenWidth(int);
    void ShowPenColor();
    void ShowPenStyle(int);
    void ShowPenCap(int);
    void ShowPenJoin(int);
    void ShowSpreadStyle();
    void ShowFillRule();
    void ShowBrushColor();
    void ShowBrush(int);
};

#endif // MAINWINDOW_H
