#include "hello.h"
#include "ui_hello.h"

Hello::Hello(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hello)
{
    ui->setupUi(this);
}

Hello::~Hello()
{
    delete ui;
}

void Hello::CreateLable()
{
    QLabel* label = new QLabel("Hello Qt!");
    label->show();
}
