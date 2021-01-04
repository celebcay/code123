#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QFontComboBox>
#include <QToolButton>
#include <QTextCharFormat>
#include <QtPrintSupport/QPrinter>
#include "showwidget.h"

class ImageProcessor : public QMainWindow
{
    Q_OBJECT

public:
    ImageProcessor(QWidget *parent = nullptr);
    ~ImageProcessor();
    void CreateActions(); // 创建动作
    void CreateMenu(); // 创建菜单
    void CreateToolBars(); // 创建工具栏
    void LoadFile(QString tempFileName);
    void MergeFormat(QTextCharFormat textCharFormat);

private slots:
    void ShowNewFile();
    void ShowOpenFile();
    void ShowPrintText();
    void ShowPrintImage();
    void ShowZoomIn();
    void ShowZoomOut();
    void ShowRotate90();
    void ShowRotate180();
    void ShowRotate270();
    void ShowMirrorVertical();
    void ShowMirrorHorizontal();

    void ShowFontComboBox(QString tempComboBox);
    void ShowSizeSpinBox(QString spinValue);
    void ShowBoldBtn();
    void ShowItalicBtn();
    void ShowUnderlineBtn();
    void ShowColorBtn();
    void ShowCurrentFormatChanged(const QTextCharFormat &fmt);

    void ShowList(int);
    void ShowAlignment(QAction* act);
    void ShowCursorPositionChanged();

private:
    QMenu* fileMenu; // 各项菜单栏
    QMenu* zoomMenu;
    QMenu* rotateMenu;
    QMenu* mirrorMenu;

    QImage img;
    QString fileName;
    ShowWidget* showWidget;

    QAction* openFileAction; // 文件菜单项
    QAction* newFileAction;
    QAction* printTextAction;
    QAction* printImageAction;
    QAction* exitAction; // 编辑菜单项
    QAction* copyAction;
    QAction* cutAction;
    QAction* pasteAction;
    QAction* aboutAction;
    QAction* zoomInAction;
    QAction* zoomOutAction;
    QAction* rotate90Action; // 旋转菜单项
    QAction* rotate180Action;
    QAction* rotate270Action;

    QAction* mirrorVerticalAction; // 镜像菜单项
    QAction* mirrorHorizontalAction;
    QAction* undoAction;
    QAction* redoAction;

    QToolBar* fileTool; // 工具栏
    QToolBar* zoomTool;
    QToolBar* rotateTool;
    QToolBar* mirrorTool;
    QToolBar* doToolBar;

    QLabel* fontLabel1; // 文本编辑
    QFontComboBox* fontComboBox;
    QLabel* fontLabel2;
    QComboBox* sizeComboBox;
    QToolButton* boldBtn;
    QToolButton* italicBtn;
    QToolButton* underlineBtn;
    QToolButton* colorBtn;
    QToolBar* fontToolBar;

    QLabel* listLabel; // 排序设置项
    QComboBox* listComboBox;
    QActionGroup* actGrp;
    QAction* leftAction;
    QAction* rightAction;
    QAction* centerAction;
    QAction* justifyAction;
    QToolBar* listToolBar;
};

#endif // IMAGEPROCESSOR_H
