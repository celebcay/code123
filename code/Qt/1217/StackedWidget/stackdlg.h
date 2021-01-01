/*
 * File Name: StackedWidget
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月17日
 */

#ifndef STACKDLG_H
#define STACKDLG_H

#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>

class StackDlg : public QDialog
{
    Q_OBJECT

private:
    QListWidget* list;
    QStackedWidget* stack;
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;

public:
    StackDlg(QWidget *parent = 0);
    ~StackDlg();
};

#endif // STACKDLG_H
