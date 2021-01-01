/*
 * File Name: UserInfo
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月19日
 */

#include "userinfo.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QPixmap>

UserInfo::UserInfo(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UserInfo"));

    // 左侧
    userNameLabel = new QLabel(tr("用户名："));
    userNameLineEdit = new QLineEdit;

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
    leftLayout->addWidget(userNameLineEdit, 0, 1);
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

    // 右侧
    headLabel = new QLabel(tr("头像："));
    headIconLabel = new QLabel;

    const QPixmap icon("312.png");
    headIconLabel->setPixmap(icon);
    headIconLabel->resize(icon.width(), icon.height());

    updateHeadBtn = new QPushButton(tr("更新"));

    topRightLayout = new QHBoxLayout();
    topRightLayout->setSpacing(20);
    topRightLayout->addWidget(headLabel);
    topRightLayout->addWidget(headIconLabel);
    topRightLayout->addWidget(updateHeadBtn);

    introductionLabel = new QLabel("个人说明：");
    introductionTextEdit = new QTextEdit;

    rightLayout = new QVBoxLayout();
    rightLayout->setMargin(10);
    rightLayout->addLayout(topRightLayout);
    rightLayout->addWidget(introductionLabel);
    rightLayout->addWidget(introductionTextEdit);

    okBtn = new QPushButton(tr("确定"));
    cancelBtn = new QPushButton(tr("取消"));

    buttomLayout = new QHBoxLayout();
    buttomLayout->addStretch();
    buttomLayout->addWidget(okBtn);
    buttomLayout->addWidget(cancelBtn);

    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addLayout(rightLayout, 0, 1);
    mainLayout->addLayout(buttomLayout, 1, 0, 1, 2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}

UserInfo::~UserInfo()
{

}
