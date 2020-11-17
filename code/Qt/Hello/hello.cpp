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

void Hello::CreateButton(QApplication& app)
{
    QPushButton* button = new QPushButton("Quit!");
    QObject::connect(button, SIGNAL(clicked()),
                     &app, SLOT(quit()));
    button->show();
}
