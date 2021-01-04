#include "contact.h"

Contact::Contact(QWidget *parent) : QWidget(parent)
{
    emailLabel = new QLabel(tr("电子邮件："));
    emailLineEidt = new QLineEdit;
    addrLabel = new QLabel(tr("联系地址："));
    addrLineEidt = new QLineEdit;
    codeLabel = new QLabel("邮政编码：");
    codeLineEidt = new QLineEdit;
    movieTelLabel = new QLabel(tr("移动电话："));
    movieTelLineEidt = new QLineEdit;
    movieTelCheckBox = new QCheckBox(tr("接收留言"));
    proTelLabel = new QLabel(tr("办公电话："));
    proTelLineEidt = new QLineEdit;
    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(emailLabel, 0, 0);
    mainLayout->addWidget(emailLineEidt, 0, 1);
    mainLayout->addWidget(addrLabel, 1, 0);
    mainLayout->addWidget(addrLineEidt, 1, 1);
    mainLayout->addWidget(codeLabel, 2, 0);
    mainLayout->addWidget(codeLineEidt, 2, 1);
    mainLayout->addWidget(movieTelLabel, 3, 0);
    mainLayout->addWidget(movieTelLineEidt, 3, 1);
    mainLayout->addWidget(movieTelCheckBox, 3, 2);
    mainLayout->addWidget(proTelLabel, 4, 0);
    mainLayout->addWidget(proTelLineEidt, 4, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
