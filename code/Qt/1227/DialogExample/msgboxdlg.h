#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class MsgBoxDlg : public QDialog
{
    Q_OBJECT

public:
    MsgBoxDlg(QWidget *parent = nullptr);

private slots:
    void ShowQuestionMsg();
    void ShowInformationMsg();
    void ShowWarningMag();
    void ShowCriticalMsg();
    void ShowAboutMsg();
    void ShowAboutQtMsg();

private:
    QLabel* label;
    QPushButton* questionBtn;
    QPushButton* informationBtn;
    QPushButton* warnnigBtn;
    QPushButton* criticalBtn;
    QPushButton* aboutBtn;
    QPushButton* aboutQtBtn;
    QGridLayout* mainLayout;
};

#endif // MSGBOXDLG_H
