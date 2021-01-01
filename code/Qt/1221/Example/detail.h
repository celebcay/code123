#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = nullptr);
private:
    QLabel* nationalLabel;
    QComboBox* nationalComboBox;
    QLabel* provinceLabel;
    QComboBox* provinceComboBox;
    QLabel* cityLabel;
    QLineEdit* cityLineEidt;
    QLabel* introductionLabel;
    QTextEdit* introductionTextEidt;
    QGridLayout* mainLayout;
signals:

public slots:
};

#endif // DETAIL_H
