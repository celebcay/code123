/*
 * File Name: Hello
 * Author：calebcay
 * Mail：Calebcay@163.com
 * Create Time：2020年11月17日
 */

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

void Hello::CreateWidget()
{
    QWidget* window = new QWidget;
    window->setWindowTitle("Enter your age:");

    QSpinBox* spinBox = new QSpinBox;
    QSlider* slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                     slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));

    spinBox->setValue(35);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window->setLayout(layout);

    window->show();
}
