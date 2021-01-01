/*
 * File Name: Example
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月21日
 */

#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfo(QWidget *parent = nullptr);

private:
    QLabel* userNameLabel;
    QLabel* nameLabel;
    QLabel* sexLabel;
    QLabel* departmentLabel;
    QLabel* ageLabel;
    QLabel* otherLabel;

    QLineEdit* userNameLineEidt;
    QLineEdit* nameLineEidt;
    QComboBox* sexComboBox;
    QTextEdit* departmentTextEidt;
    QLineEdit* ageLineEidt;
    QGridLayout* leftLayout;

    QLabel* headLabel;
    QLabel* headIconLabel;
    QPushButton* updateHeadBtn;
    QHBoxLayout* topRightLayout;
    QLabel* introductionLabel;
    QTextEdit* introductionTextEdit;
    QVBoxLayout* rightLayout;
signals:

public slots:
};

#endif // BASEINFO_H
