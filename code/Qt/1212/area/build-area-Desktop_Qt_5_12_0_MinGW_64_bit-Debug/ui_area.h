/********************************************************************************
** Form generated from reading UI file 'area.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREA_H
#define UI_AREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_area
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *radiusLabel;
    QLineEdit *radiusLineEidt;
    QHBoxLayout *horizontalLayout_2;
    QLabel *areaLabel;
    QLabel *areaLabel2;
    QPushButton *countButton;

    void setupUi(QDialog *area)
    {
        if (area->objectName().isEmpty())
            area->setObjectName(QString::fromUtf8("area"));
        area->resize(400, 175);
        widget = new QWidget(area);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 40, 179, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radiusLabel = new QLabel(widget);
        radiusLabel->setObjectName(QString::fromUtf8("radiusLabel"));

        horizontalLayout->addWidget(radiusLabel);

        radiusLineEidt = new QLineEdit(widget);
        radiusLineEidt->setObjectName(QString::fromUtf8("radiusLineEidt"));

        horizontalLayout->addWidget(radiusLineEidt);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        areaLabel = new QLabel(widget);
        areaLabel->setObjectName(QString::fromUtf8("areaLabel"));

        horizontalLayout_2->addWidget(areaLabel);

        areaLabel2 = new QLabel(widget);
        areaLabel2->setObjectName(QString::fromUtf8("areaLabel2"));
        areaLabel2->setFrameShape(QFrame::Panel);
        areaLabel2->setFrameShadow(QFrame::Sunken);
        areaLabel2->setLineWidth(4);
        areaLabel2->setMidLineWidth(0);

        horizontalLayout_2->addWidget(areaLabel2);


        verticalLayout->addLayout(horizontalLayout_2);

        countButton = new QPushButton(widget);
        countButton->setObjectName(QString::fromUtf8("countButton"));

        verticalLayout->addWidget(countButton);


        retranslateUi(area);

        QMetaObject::connectSlotsByName(area);
    } // setupUi

    void retranslateUi(QDialog *area)
    {
        area->setWindowTitle(QApplication::translate("area", "area", nullptr));
        radiusLabel->setText(QApplication::translate("area", "\345\215\212\345\276\204\357\274\232", nullptr));
        radiusLineEidt->setText(QApplication::translate("area", "2", nullptr));
        areaLabel->setText(QApplication::translate("area", "\351\235\242\347\247\257\357\274\232", nullptr));
        areaLabel2->setText(QString());
        countButton->setText(QApplication::translate("area", "\350\256\241\347\256\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class area: public Ui_area {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREA_H
