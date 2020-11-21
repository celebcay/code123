/*
 * File Name: untitled
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年11月21日
 */

#include "finding.h"
#include "ui_finding.h"

Finding::Finding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Finding)
{
    label = new QLabel(tr("Find &what:"));
    lineEidt = new QLineEdit;
    label->setBuddy(lineEidt);

    caseCheckBox = new QCheckBox(tr("Matvh &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));
    findButton = new QPushButton(tr("&Find"));

    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButon = new QPushButton(tr("Close"));

    connect(lineEidt, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableFindButton(const QString&)));
    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findChild()));
    connect(closeButon, SIGNAL(clicked()),
            this, SLOT(close()));

    QHBoxLayout* topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEidt);

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButon);
    rightLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle("Find");
    setFixedHeight(sizeHint().height());
}

void Finding::findChild()
{
    QString text = lineEidt->text();
    Qt::CaseSensitivity cs =
            caseCheckBox->isChecked() ? Qt::CaseSensitive
                                      : Qt::CaseInsensitive;
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void Finding::enableFindButton(const QString& text)
{
    findButton->setEnabled(!text.isEmpty());
}

Finding::~Finding()
{
    delete ui;
}
