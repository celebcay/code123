#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include "inputdlg.h"
#include "msgboxdlg.h"
#include "customdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    // 文件
    QPushButton* fileBtn;
    QLineEdit* fileLineEdit;
    QGridLayout* mainLayout;

    // 颜色
    QPushButton* colorBtn;
    QFrame* colorFrame;

    // 字体
    QPushButton* fontBtn;
    QLineEdit* fontLineEdit;

    // 输入
    QPushButton* inputBtn;
    InputDlg* inputDlg;

    // 消息框
    QPushButton* msgBtn;
    MsgBoxDlg* msgDlg;

    // 自定义消息框
    QPushButton* customBtn;
    QLabel* customLabel;

private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgDlg();
    void showCustomDlg();
};

#endif // DIALOG_H
