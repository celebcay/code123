#include "extensiondlg.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QHBoxLayout>

ExtensionDlg::ExtensionDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Extension Dialog"));
    CreateBaseInfo();
    CreateDetailInfo();

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(baseWidget);
    layout->addWidget(detailWidget);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->setSpacing(10);
}

ExtensionDlg::~ExtensionDlg()
{

}

void ExtensionDlg::ShowDetailInfo()
{
    if (detailWidget->isHidden()) {
        detailWidget->show();
    } else {
        detailWidget->hide();
    }
}

void ExtensionDlg::CreateBaseInfo()
{
    baseWidget = new QWidget;
    QLabel* nameLabel = new QLabel(tr("姓名："));
    QLineEdit* nameLineEdit = new QLineEdit;
    QLabel* sexLabel = new QLabel(tr("性别："));
    QComboBox* sexComboBox = new QComboBox;
    sexComboBox->insertItem(0, tr("女"));
    sexComboBox->insertItem(1, tr("男"));

    QGridLayout* leftLayout = new QGridLayout;
    leftLayout->addWidget(nameLabel, 0, 0);
    leftLayout->addWidget(nameLineEdit, 0, 1);
    leftLayout->addWidget(sexLabel, 1, 0);
    leftLayout->addWidget(sexComboBox, 1, 1);

    QPushButton* okBtn = new QPushButton(tr("确定"));
    QPushButton* detailBtn = new QPushButton(tr("详细"));
    QDialogButtonBox* boxBtn = new QDialogButtonBox(Qt::Vertical);
    boxBtn->addButton(okBtn, QDialogButtonBox::ActionRole);
    boxBtn->addButton(detailBtn, QDialogButtonBox::ActionRole);

    QHBoxLayout* mainLayout = new QHBoxLayout(baseWidget);
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(boxBtn);
    connect(detailBtn, SIGNAL(clicked()), this, SLOT(ShowDetailInfo()));
}

void ExtensionDlg::CreateDetailInfo()
{
    detailWidget = new QWidget;
    QLabel* ageLabel = new QLabel(tr("年龄："));
    QLineEdit* ageLineEdit = new QLineEdit;
    ageLineEdit->setText(tr("30"));
    QLabel* departmentLabel = new QLabel(tr("部门："));
    QComboBox* departmentComboBox = new QComboBox;
    departmentComboBox->addItem(tr("部门1"));
    departmentComboBox->addItem(tr("部门2"));
    departmentComboBox->addItem(tr("部门3"));
    departmentComboBox->addItem(tr("部门4"));
    departmentComboBox->addItem(tr("部门5"));

    QLabel* email = new QLabel(tr("email: "));
    QLineEdit* emailLineEdit = new QLineEdit;
    QGridLayout* mainLayout = new QGridLayout(detailWidget);
    mainLayout->addWidget(ageLabel, 0, 0);
    mainLayout->addWidget(ageLineEdit, 0, 1);
    mainLayout->addWidget(departmentLabel, 1, 0);
    mainLayout->addWidget(departmentComboBox, 1, 1);
    mainLayout->addWidget(email, 2, 0);
    mainLayout->addWidget(emailLineEdit, 2, 1);
    detailWidget->hide();
}
