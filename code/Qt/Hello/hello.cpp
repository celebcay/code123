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
    QLabel* label = new QLabel("<h2><i>Hello</i>"
    "<font color=red>Qt!</font></h2>");
    label->show();
}
