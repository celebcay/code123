#include "dialog.h"
#include <QGridLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("各种标准对话框的实例"));

    fileBtn = new QPushButton;
    fileBtn->setText(tr("文件标准对话框实例"));
    fileLineEdit = new QLineEdit;

    colorBtn = new QPushButton;
    colorBtn->setText(tr("颜色标准对话框实例"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);

    fontBtn = new QPushButton;
    fontBtn->setText(tr("字体标准对话框实例"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(tr("Welcome!"));

    inputBtn = new QPushButton;
    inputBtn->setText(tr("标准输入对话框实例"));

    msgBtn = new QPushButton;
    msgBtn->setText(tr("标准消息对话框实例"));

    customBtn = new QPushButton;
    customBtn->setText(tr("用户自定义消息对话框实例"));
    customLabel = new QLabel;
    customLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileBtn, 0, 0);
    mainLayout->addWidget(fileLineEdit, 0, 1);

    mainLayout->addWidget(colorBtn, 1, 0);
    mainLayout->addWidget(colorFrame, 1, 1);

    mainLayout->addWidget(fontBtn, 2, 0);
    mainLayout->addWidget(fontLineEdit, 2, 1);

    mainLayout->addWidget(inputBtn, 3, 0);
    mainLayout->addWidget(msgBtn, 3, 1);

    mainLayout->addWidget(customBtn, 4, 0);
    mainLayout->addWidget(customLabel, 4, 1);

    connect(fileBtn, SIGNAL(clicked()), this, SLOT(showFile()));
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColor()));
    connect(fontBtn, SIGNAL(clicked()), this, SLOT(showFont()));
    connect(inputBtn, SIGNAL(clicked()), this, SLOT(showInputDlg()));
    connect(msgBtn, SIGNAL(clicked()), this, SLOT(showMsgDlg()));
    connect(customBtn, SIGNAL(clicked()), this, SLOT(showCustomDlg()));

}

Dialog::~Dialog()
{

}

void Dialog::showFile()
{
    QString s = QFileDialog::getOpenFileName(this, "Open file dialog", "/",
                                             "C++ file(*.cpp)::C files(*.c)::Head files(*.h)");
    fileLineEdit->setText(s);
}

void Dialog::showColor()
{
    QColor c = QColorDialog::getColor(Qt::blue);
    if (c.isValid()) {
        colorFrame->setPalette(QPalette(c));
    }
}

void Dialog::showFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if (ok) {
        fontLineEdit->setFont(f);
    }
}

void Dialog::showInputDlg()
{
    inputDlg = new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg = new MsgBoxDlg();
    msgDlg->show();
}

void Dialog::showCustomDlg()
{
    customLabel->setText(tr("Cuetom Message Box"));
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("用户自定义消息框"));

    QPushButton* yesBtn = customMsgBox.addButton(tr("Yes"), QMessageBox::ActionRole);
    QPushButton* noBtn = customMsgBox.addButton(tr("No"), QMessageBox::ActionRole);
    QPushButton* cancelBtn = customMsgBox.addButton(QMessageBox::Cancel);

    customMsgBox.setText(tr("这是一个用户自定义消息框！"));
    customMsgBox.setIconPixmap(QPixmap("Qt.png"));
    customMsgBox.exec();

    if (customMsgBox.clickedButton() == yesBtn) {
        customLabel->setText(tr("Custom Message Box/Yes"));
    }
    if (customMsgBox.clickedButton() == noBtn) {
        customLabel->setText(tr("Custom Message Box/No"));
    }
    if (customMsgBox.clickedButton() == cancelBtn) {
        customLabel->setText(tr("Custom Message Box/Cancel"));
    }
    return;
}
