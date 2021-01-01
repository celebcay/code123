/*
 * File Name: Example
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月21日
 */

#ifndef CONTENT_H
#define CONTENT_H

#include <QDialog>
#include <QStackedWidget>
#include <QPushButton>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"

class Content : public QFrame
{
    Q_OBJECT

public:
    Content(QWidget *parent = 0);
    ~Content();

    QStackedWidget* stack;
    QPushButton* amendBtn;
    QPushButton* closeBtn;
    Contact* contact;
    BaseInfo* baseInfo;
    Detail* detail;
};

#endif // CONTENT_H
