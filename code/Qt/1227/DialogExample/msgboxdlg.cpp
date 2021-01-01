#include "msgboxdlg.h"
#include <QMessageBox>

MsgBoxDlg::MsgBoxDlg(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle(tr("标准消息对话框实例"));

    label = new QLabel;
    label->setText(tr("请选择一种消息框"));

    questionBtn = new QPushButton;
    questionBtn->setText(tr("QuestionMsg"));

    informationBtn = new QPushButton;
    informationBtn->setText(tr("InformationMsg"));

    warnnigBtn = new QPushButton;
    warnnigBtn->setText(tr("WarningMsg"));

    criticalBtn = new QPushButton;
    criticalBtn->setText(tr("CriticalMsg"));

    aboutBtn = new QPushButton;
    aboutBtn->setText(tr("AboutMsg"));

    aboutQtBtn = new QPushButton;
    aboutQtBtn->setText(tr("AboutQtMsg"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label, 0, 0, 1, 2);
    mainLayout->addWidget(questionBtn, 1, 0);
    mainLayout->addWidget(informationBtn, 1, 1);
    mainLayout->addWidget(warnnigBtn, 2, 0);
    mainLayout->addWidget(criticalBtn, 2, 1);
    mainLayout->addWidget(aboutBtn, 3, 0);
    mainLayout->addWidget(aboutQtBtn, 3, 1);

    connect(questionBtn, SIGNAL(clicked()), this, SLOT(ShowQuestionMsg()));
    connect(informationBtn, SIGNAL(clicked()), this, SLOT(ShowInformationMsg()));
    connect(warnnigBtn, SIGNAL(clicked()), this, SLOT(ShowWarningMag()));
    connect(criticalBtn, SIGNAL(clicked()), this, SLOT(ShowCriticalMsg()));
    connect(aboutBtn, SIGNAL(clicked()), this, SLOT(ShowAboutMsg()));
    connect(aboutQtBtn, SIGNAL(clicked()), this, SLOT(ShowAboutQtMsg()));
}

void MsgBoxDlg::ShowQuestionMsg()
{
    label->setText(tr("Question Message Box"));
    switch (QMessageBox::question(this, tr("Question 消息框"),
        tr("您现在已经修改完成，是否要结束程序？"),
        QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok)) {
    case QMessageBox::Ok:
        label->setText(tr("Question button/Ok"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("Question button/Cancel"));
        break;
    default:
        break;
    }
    return;
}

void MsgBoxDlg::ShowInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this, tr("Information 消息框"),
        tr("这是Information消息框测试，欢迎你！"));
    return;
}

void MsgBoxDlg::ShowWarningMag()
{
    label->setText(tr("Warning Message Box"));
    switch (QMessageBox::warning(this, tr("Warning 消息框"),
        tr("您修改的内容还未保存，是否要保存对文档的修改？"),
        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Save)) {
    case QMessageBox::Save:
        label->setText(tr("Warning button/Ok"));
        break;
    case QMessageBox::Discard:
        label->setText(tr("Warning button/Discard"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("Warning button/Cancel"));
        break;
    default:
        break;
    }
    return;
}

void MsgBoxDlg::ShowCriticalMsg()
{
    label->setText(tr("Critical Message Box"));
    QMessageBox::critical(this, tr("Critical 消息框"),
        tr("这是Critical消息框测试，欢迎你！"));
    return;
}

void MsgBoxDlg::ShowAboutMsg()
{
    label->setText(tr("About Message Box"));
    QMessageBox::about(this, tr("About 消息框"),
        tr("这是About消息框测试，欢迎你！"));
    return;
}

void MsgBoxDlg::ShowAboutQtMsg()
{
    label->setText(tr("About Qt Message Box"));
    QMessageBox::aboutQt(this, tr("About Qt 消息框"));
    return;
}
