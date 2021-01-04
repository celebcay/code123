#ifndef EXTENSIONDLG_H
#define EXTENSIONDLG_H

#include <QDialog>

class ExtensionDlg : public QDialog
{
    Q_OBJECT

public:
    ExtensionDlg(QWidget *parent = nullptr);
    ~ExtensionDlg();
private slots:
    void ShowDetailInfo();

private:
    void CreateBaseInfo();
    void CreateDetailInfo();
    QWidget* baseWidget;
    QWidget* detailWidget;
};

#endif // EXTENSIONDLG_H
