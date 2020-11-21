/*
 * File Name: untitled
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年11月21日
 */

#ifndef FINDING_H
#define FINDING_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class Finding;
}

class Finding : public QDialog
{
    Q_OBJECT

public:
    explicit Finding(QWidget *parent = nullptr);
    ~Finding();

private:
    Ui::Finding *ui;

signals:
    void findNext(const QString& findText, Qt::CaseSensitivity cs);
    void findPrevious(const QString& findText,
                      Qt::CaseSensitivity cs);

private slots:
    void findChild();
    void enableFindButton(const QString& text);

private:
    QLabel* label;
    QLineEdit* lineEidt;
    QCheckBox* caseCheckBox;
    QCheckBox* backwardCheckBox;
    QPushButton* findButton;
    QPushButton* closeButon;
};

#endif // FINDING_H
