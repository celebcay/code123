#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    nationalLabel = new QLabel(tr("国家："));
    nationalComboBox = new QComboBox;
    nationalComboBox->insertItem(0, tr("中国"));
    nationalComboBox->insertItem(1, tr("美国"));
    nationalComboBox->insertItem(2, tr("英国"));
    provinceLabel = new QLabel(tr("省份："));
    provinceComboBox = new QComboBox;
    provinceComboBox->insertItem(0, tr("江苏省"));
    provinceComboBox->insertItem(1, tr("山东省"));
    provinceComboBox->insertItem(2, tr("浙江省"));
    cityLabel = new QLabel(tr("城市"));
    cityLineEidt = new QLineEdit;
    introductionLabel = new QLabel(tr("个人说明："));
    introductionTextEidt = new QTextEdit;
    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(nationalLabel, 0, 0);
    mainLayout->addWidget(nationalComboBox, 0, 1);
    mainLayout->addWidget(provinceLabel, 1, 0);
    mainLayout->addWidget(provinceComboBox, 1, 1);
    mainLayout->addWidget(cityLabel, 2, 0);
    mainLayout->addWidget(cityLineEidt, 2, 1);
    mainLayout->addWidget(introductionLabel, 3, 0);
    mainLayout->addWidget(introductionTextEidt, 3, 1);
}
