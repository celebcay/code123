#ifndef PALETTE_H
#define PALETTE_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>

class Palette : public QDialog
{
    Q_OBJECT

public:
    Palette(QWidget *parent = nullptr);
    ~Palette();
    void CreateCtrlFrame();
    void CreateConterFrame();
    void FillColorList(QComboBox*);

private slots:
    void ShowWindow();
    void ShowWindowText();
    void ShowButon();
    void ShowButtonText();
    void ShowBase();
private:
    QFrame* ctrlFrame;
    QLabel* windowLabel;
    QComboBox* windowComboBox;
    QLabel* windowTextLabel;
    QComboBox* windowTextComboBox;
    QLabel* buttonLabel;
    QComboBox* buttonComboBox;
    QLabel* buttonTextLabel;
    QComboBox* buttonTextComboBox;
    QLabel* baseLabel;
    QComboBox* baseComboBox;

    QFrame* contentFrame;
    QLabel* label1;
    QComboBox* comboBox1;
    QLabel* label2;
    QComboBox* comboBox2;

    QLineEdit* lineEdit2;
    QTextEdit* textEdit;

    QPushButton* okBtn;
    QPushButton* cancelBtn;
};

#endif // PALETTE_H
