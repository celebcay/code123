#include "fileview.h"

FileView::FileView(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setWindowTitle(tr("FileView"));
    fileLineEdit = new QLineEdit(tr("/"));
    fileListWidget = new QListWidget;
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(fileLineEdit);
    mainLayout->addWidget(fileListWidget);
    connect(fileLineEdit, SIGNAL(returnPressed()), this, SLOT(slotShow(QDir)));
    connect(fileListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(slotDirShow(QListWidgetItem*)));
    QString root = "/";
    QDir rootDir(root);
    QStringList str;
    str<<"*";
    QFileInfoList list = rootDir.entryInfoList(str);
    showFileInfoList(list);
}

FileView::~FileView()
{

}

void FileView::showFileInfoList(QFileInfoList list)
{
    fileListWidget->clear();
    for (int i = 0; i < list.count(); ++i) {
        QFileInfo tmpFileInfo = list.at(i);
        if (tmpFileInfo.isDir()) {
            QIcon icon("dir.png");
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem* tmp = new QListWidgetItem(icon, fileName);
            fileListWidget->addItem(tmp);
        } else if (tmpFileInfo.isFile()) {
            QIcon icon("file.png");
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem* tmp = new QListWidgetItem(icon, fileName);
            fileListWidget->addItem(tmp);
        }
    }
}

void FileView::slotShow(QDir dir)
{
    QStringList str;
    str<<"*";
    QFileInfoList list = dir.entryInfoList(str, QDir::AllEntries, QDir::DirsFirst);
    showFileInfoList(list);
}

void FileView::slotDirShow(QListWidgetItem *item)
{
    QString str = item->text();
    QDir dir;
    dir.setPath(fileLineEdit->text());
    dir.cd(str);
    fileLineEdit->setText(dir.absolutePath());
    slotShow(dir);
}
