#include "qstring.h"
#include "ui_qstring.h"

qstring::qstring(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qstring)
{
    ui->setupUi(this);
}

qstring::~qstring()
{
    delete ui;
}
