/*
 * File Name: Example
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月21日
 */

#include "content.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Content::Content(QWidget *parent)
    : QFrame(parent)
{
    stack = new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);

    baseInfo = new BaseInfo();
    contact = new Contact();

    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);
    amendBtn = new QPushButton(tr("修改"));
    closeBtn = new QPushButton(tr("关闭"));

    QHBoxLayout* btnLayout = new QHBoxLayout;
    btnLayout->addStretch(1);
    btnLayout->addWidget(amendBtn);
    btnLayout->addWidget(closeBtn);

    QVBoxLayout* rightLayout = new QVBoxLayout(this);
    rightLayout->setMargin(10);
    rightLayout->setSpacing(6);
    rightLayout->addWidget(stack);
    rightLayout->addLayout(btnLayout);
}

Content::~Content()
{

}
