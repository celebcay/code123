#include "progressdlg.h"
#include <QProgressDialog>
#include <QFont>

ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    QFont font("Calebcay", 12);
    setFont(font);
    setWindowTitle(tr("Progress"));

    fileNum = new QLabel;
    fileNum->setText(tr("文件数目："));
    fileNumLineEdit = new QLineEdit;
    fileNumLineEdit->setText(tr("100000"));

    progressType = new QLabel;
    progressType->setText(tr("显示类型："));
    comboBox = new QComboBox;
    comboBox->addItem(tr("progressBar"));
    comboBox->addItem(tr("progressDialog"));

    progressBar = new QProgressBar;
    startBtn = new QPushButton();
    startBtn->setText(tr("开始"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileNum, 0, 0);
    mainLayout->addWidget(fileNumLineEdit, 0, 1);
    mainLayout->addWidget(progressType, 1, 0);
    mainLayout->addWidget(comboBox, 1, 1);
    mainLayout->addWidget(progressBar, 2, 0, 1, 2);
    mainLayout->addWidget(startBtn, 3, 1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    connect(startBtn, SIGNAL(clicked()), this, SLOT(StartProgress()));

}

ProgressDlg::~ProgressDlg()
{

}

void ProgressDlg::StartProgress()
{
    bool ok;
    int num = fileNumLineEdit->text().toInt(&ok);
    if (comboBox->currentIndex() == 0) {
        progressBar->setRange(0, num);
        for (int i = 1; i < num + 1; i++) {
            progressBar->setValue(i);
        }
    } else if (comboBox->currentIndex() == 1) {
        QProgressDialog* progressDialog = new QProgressDialog(this);
        QFont font("calebcay", 12);
        progressDialog->setFont(font);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(5);
        progressDialog->setWindowTitle(tr("Please Wait"));
        progressDialog->setLabelText(tr("Copying..."));
        progressDialog->setCancelButtonText(tr("Cancel"));
        progressDialog->setRange(0, num);
        for (int i = 1; i < num + 1; i++) {
            progressDialog->setValue(i);
            if (progressDialog->wasCanceled()) {
                return;
            }
        }
    }
}
