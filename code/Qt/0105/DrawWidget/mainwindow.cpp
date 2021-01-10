#include "mainwindow.h"
#include <QToolBar>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    drawWidget = new DrawWidget;
    setCentralWidget(drawWidget);
    CreateToolBar();
    setMinimumSize(600, 400);
    ShowStyle();
    drawWidget->SetWidth(widthSpinBox->value());
    drawWidget->SetColor(Qt::black);
}

MainWindow::~MainWindow()
{

}

void MainWindow::CreateToolBar()
{
    QToolBar* toolBar = addToolBar("Tool");
    styleLabel = new QLabel(tr("线性风格"));
    styleComboBox = new QComboBox;
    styleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
    styleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
    styleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
    styleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
    connect(styleComboBox, SIGNAL(activated(int)), this, SLOT(ShowStyle()));

    widthLabel = new QLabel(tr("线宽"));
    widthSpinBox = new QSpinBox;
    connect(widthSpinBox, SIGNAL(valueChanged(int)), drawWidget, SLOT(SetWidth(int)));

    colorBtn = new QToolButton;
    QPixmap pixmap(20, 20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(ShowColor()));

    clearBtn = new QToolButton;
    clearBtn->setText(tr("清除"));
    connect(clearBtn, SIGNAL(clicked()), drawWidget, SLOT(Clear()));

    toolBar->addWidget(styleLabel);
    toolBar->addWidget(styleComboBox);
    toolBar->addWidget(widthLabel);
    toolBar->addWidget(widthSpinBox);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(clearBtn);
}

void MainWindow::ShowStyle()
{
    drawWidget->SetStyle(
        styleComboBox->itemData(styleComboBox->currentIndex(), Qt::UserRole).toInt());
 }

void MainWindow::ShowColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::black), this);
    if (color.isValid()) {
        drawWidget->SetColor(color);
        QPixmap p(20, 20);
        p.fill(color);
        colorBtn->setIcon(QIcon(p));
    }
}
