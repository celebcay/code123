/*
 * File Name: DockWindows
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年12月16日
 */

#ifndef DOCKWINDOW_H
#define DOCKWINDOW_H

#include <QMainWindow>

class DockWindow : public QMainWindow
{
    Q_OBJECT

public:
    DockWindow(QWidget *parent = 0);
    ~DockWindow();
};

#endif // DOCKWINDOW_H
