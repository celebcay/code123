/*
 * File Name: UserInfo
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月19日
 */

#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>

class UserInfo : public QDialog
{
    Q_OBJECT

public:
    UserInfo(QWidget *parent = 0);
    ~UserInfo();

private:
    QLabel* userNameLabel;
    QLabel* nameLabel;
    QLabel* sexLabel;
    QLabel* departmentLabel;
    QLabel* ageLabel;
    QLabel* otherLabel;

    QLineEdit* userNameLineEdit;
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

    QPushButton* okBtn;
    QPushButton* cancelBtn;
    QHBoxLayout* buttomLayout;
};

#endif // USERINFO_H
