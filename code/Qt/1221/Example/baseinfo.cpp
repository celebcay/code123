/*
 * File Name: Example
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月21日
 */

#include "baseinfo.h"

BaseInfo::BaseInfo(QWidget *parent) : QWidget(parent)
{
    userNameLabel = new QLabel(tr("用户名："));
    userNameLineEidt = new QLineEdit;
    nameLabel = new QLabel(tr("姓名："));
    nameLineEidt = new QLineEdit;
    sexLabel = new QLabel(tr("性别："));
    sexComboBox = new QComboBox;
    sexComboBox->addItem(tr("女"));
    sexComboBox->addItem(tr("男"));
    departmentLabel = new QLabel(tr("部门："));
    departmentTextEidt = new QTextEdit;
    ageLabel = new QLabel(tr("年龄："));
    ageLineEidt = new QLineEdit;
    otherLabel = new QLabel(tr("备注："));
    otherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    leftLayout = new QGridLayout();
    leftLayout->addWidget(userNameLabel, 0, 0);
    leftLayout->addWidget(userNameLineEidt, 0, 1);
    leftLayout->addWidget(nameLabel, 1, 0);
    leftLayout->addWidget(nameLineEidt, 1, 1);
    leftLayout->addWidget(sexLabel, 2, 0);
    leftLayout->addWidget(sexComboBox, 2, 1);
    leftLayout->addWidget(departmentLabel, 3, 0);
    leftLayout->addWidget(departmentTextEidt, 3, 1);
    leftLayout->addWidget(ageLabel, 4, 0);
    leftLayout->addWidget(ageLineEidt, 4, 1);
    leftLayout->addWidget(otherLabel, 5, 0, 1, 2);
    leftLayout->setColumnStretch(0, 1);
    leftLayout->setColumnStretch(1, 3);

    headLabel = new QLabel(tr("头像："));
    headIconLabel = new QLabel;
    QPixmap icon("123.png");
    headIconLabel->setPixmap(icon);
    headIconLabel->resize(icon.width(), icon.height());
    updateHeadBtn = new QPushButton(tr("更新"));
    topRightLayout = new QHBoxLayout();
    topRightLayout->setSpacing(20);
    topRightLayout->addWidget(headLabel);
    topRightLayout->addWidget(headIconLabel);
    topRightLayout->addWidget(updateHeadBtn);
    introductionLabel = new QLabel(tr("个人说明："));
    introductionTextEdit = new QTextEdit;
    rightLayout = new QVBoxLayout();
    rightLayout->setMargin(10);
    rightLayout->addLayout(topRightLayout);
    rightLayout->addWidget(introductionLabel);
    rightLayout->addWidget(introductionTextEdit);

    QGridLayout* mainLayput = new QGridLayout(this);
    mainLayput->setMargin(15);
    mainLayput->setSpacing(10);
    mainLayput->addLayout(leftLayout, 0, 0);
    mainLayput->addLayout(rightLayout, 0, 1);
    mainLayput->setSizeConstraint(QLayout::SetFixedSize);
}
