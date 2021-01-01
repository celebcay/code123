/*
 * File Name: DockWindows
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月16日
 */

#include "dockwindow.h"
#include <QTextEdit>
#include <QDockWidget>

DockWindow::DockWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("DockWindows")); // 设置主窗口标题栏文字

    QTextEdit* text = new QTextEdit(this); // 定义一个主窗口
    text->setText(tr("Mian Windows"));
    text->setAlignment(Qt::AlignCenter);
    setCentralWidget(text); // 将此编辑框设为主窗口的中央窗体

    // 停靠窗口一
    QDockWidget* dock = new QDockWidget(tr("DockWindows1"), this);
    dock->setFeatures(QDockWidget::DockWidgetMovable); // 可移动
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QTextEdit* text1 = new QTextEdit();
    text1->setText(tr("Windows1, The dock widget can be moved between docks by the user" ""));
    dock->setWidget(text1);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    // 停靠窗口2
    dock = new QDockWidget(tr("DockWindows2"), this);
    dock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable); // 可关闭 可浮动

    QTextEdit* text2 = new QTextEdit();
    text2->setText(tr("Windows2, The dock widget can be datached from the main windows,"
                      "and floated as an independent windows, and can be closed"));
    dock->setWidget(text2);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    // 停靠窗口3
    dock = new QDockWidget(tr("DockWindows3"), this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures); // 全部特性

    QTextEdit* text3 = new QTextEdit();
    text3->setText(tr("Windows3, The dock widget can be closed, moved and floated"));
    dock->setWidget(text3);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

DockWindow::~DockWindow()
{

}
