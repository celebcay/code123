#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QCheckBox>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = nullptr);
private:
    QLabel* emailLabel;
    QLineEdit* emailLineEidt;
    QLabel* addrLabel;
    QLineEdit* addrLineEidt;
    QLabel* codeLabel;
    QLineEdit* codeLineEidt;
    QLabel* movieTelLabel;
    QLineEdit* movieTelLineEidt;
    QCheckBox* movieTelCheckBox;
    QLabel* proTelLabel;
    QLineEdit* proTelLineEidt;
    QGridLayout* mainLayout;

signals:

public slots:
};

#endif // CONTACT_H
