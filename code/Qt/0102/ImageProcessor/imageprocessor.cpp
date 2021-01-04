#include "imageprocessor.h"
#include "showwidget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include <QPixmap>
#include <QtDebug>
#include <QColor>
#include <QColorDialog>
#include <QTextList>

ImageProcessor::ImageProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy Word"));
    showWidget = new ShowWidget(this);
    setCentralWidget(showWidget);
    // 设置字体
    fontLabel1 = new QLabel(tr("字体"));
    fontComboBox = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontLabel2 = new QLabel(tr("字号"));
    sizeComboBox = new QComboBox;
    QFontDatabase db;
    foreach (int size, db.standardSizes()) {
        sizeComboBox->addItem(QString::number(size));
    }
    boldBtn = new QToolButton;
    boldBtn->setIcon(QIcon("bold.png"));
    boldBtn->setCheckable(true);
    italicBtn= new QToolButton;
    italicBtn->setIcon(QIcon("italic.png"));
    italicBtn->setCheckable(true);
    underlineBtn= new QToolButton;
    underlineBtn->setIcon(QIcon("underline.png"));
    underlineBtn->setCheckable(true);
    colorBtn= new QToolButton;
    colorBtn->setIcon(QIcon("color.png"));
    colorBtn->setCheckable(true);
    // 排序
    listLabel = new QLabel(tr("排序"));
    listComboBox = new QComboBox;
    listComboBox->addItem("Standard");
    listComboBox->addItem("QTextListFormat::ListDisc");
    listComboBox->addItem("QTextListFormat::ListCircle");
    listComboBox->addItem("QTextListFormat::ListSquare");
    listComboBox->addItem("QTextListFormat::ListDecimal");
    listComboBox->addItem("QTextListFormat::ListLowerAlpha");
    listComboBox->addItem("QTextListFormat::ListUpperAlpha");
    listComboBox->addItem("QTextListFormat::ListLowerRoman");
    listComboBox->addItem("QTextListFormat::ListUpperRoman");
    // 创建动作、菜单、工具的函数
    CreateActions();
    CreateMenu();
    CreateToolBars();

    if (img.load("F:\\c++\\doc\\code123\\code\\Qt\\0102\\ImageProcessor\\Image\\image.png")) {
        qDebug()<<"123";
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
    qDebug()<<"333";
    connect(fontComboBox, SIGNAL(activated(QString)), this, SLOT(ShowFontComboBox(QString)));
    connect(sizeComboBox, SIGNAL(activated(QString)), this, SLOT(ShowSizeSpinBox(QString)));
    connect(boldBtn, SIGNAL(clicked()), this, SLOT(ShowBoldBtn()));
    connect(italicBtn, SIGNAL(clicked()), this, SLOT(ShowItalicBtn()));
    connect(underlineBtn, SIGNAL(clicked()), this, SLOT(ShowUnderlineBtn()));
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(ShowColorBtn()));
    connect(listComboBox, SIGNAL(activated(int)), this, SLOT(ShowList()));
    connect(showWidget->text->document(), SIGNAL(undoAvailable(bool)), redoAction, SLOT(setEnabled(bool)));
    connect(showWidget->text->document(), SIGNAL(redoAvailable(bool)), redoAction, SLOT(setEnabled(bool)));
    connect(showWidget->text, SIGNAL(cursorPositionChanged()), this, SLOT(ShowCursorPositionChanged()));
}

ImageProcessor::~ImageProcessor()
{

}

void ImageProcessor::CreateActions()
{
    // 打开
    openFileAction = new QAction(QIcon("open.jpg"), tr("打开"), this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("打开一个文件"));
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(ShowOpenFile()));

    // 新建
    newFileAction = new  QAction(QIcon("new.jpg"), tr("新建"), this);
    newFileAction->setShortcut(tr("Ctrl+N"));
    newFileAction->setStatusTip(tr("新建一个文件"));
    connect(newFileAction, SIGNAL(triggered()), this, SLOT(ShowNewFile()));
    // 退出
    exitAction = new  QAction(tr("退出"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    // 复制
    copyAction = new  QAction(QIcon("copy.jpg"), tr("复制"), this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("复制文件"));
    connect(copyAction, SIGNAL(triggered()), showWidget->text, SLOT(copy()));
    // 剪贴
    cutAction = new  QAction(QIcon("cut.jpg"), tr("剪贴"), this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("剪贴文件"));
    connect(cutAction, SIGNAL(triggered()), showWidget->text, SLOT(cut()));
    // 粘贴
    pasteAction = new  QAction(QIcon("paste.jpg"), tr("粘贴"), this);
    pasteAction->setShortcut(tr("Ctrl+X"));
    pasteAction->setStatusTip(tr("粘贴文件"));
    connect(pasteAction, SIGNAL(triggered()), showWidget->text, SLOT(paste()));
    // 关于
    aboutAction = new QAction(tr("关于"), this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(QApplication::aboutQt()));
    // 打印文本
    printTextAction = new QAction(QIcon("printText.jpg"), tr("打印文本"), this);
    printTextAction->setStatusTip(tr("打印文本"));
    connect(printTextAction, SIGNAL(triggered()), this, SLOT(ShowPrintText()));
    // 打印图片
    printImageAction = new QAction(QIcon("printImage.jpg"), tr("打印图片"), this);
    printImageAction->setStatusTip(tr("打印图片"));
    connect(printImageAction, SIGNAL(triggered()), this, SLOT(ShowPrintImage()));
    // 放大图片
    zoomInAction = new QAction(QIcon("zoomIn.jpg"), tr("放大图片"), this);
    zoomInAction->setStatusTip(tr("放大图片"));
    // 缩小图片
    zoomOutAction = new QAction(QIcon("zoomOut.jpg"), tr("缩小图片"), this);
    zoomOutAction->setStatusTip(tr("缩小图片"));
    // 旋转90
    rotate90Action = new QAction(QIcon("rotate.jpg"), tr("旋转90"), this);
    rotate90Action->setStatusTip(tr("旋转90"));
    // 旋转180
    rotate180Action = new QAction(QIcon("rotate.jpg"), tr("旋转180"), this);
    rotate180Action->setStatusTip(tr("旋转180"));
    // 旋转270
    rotate270Action = new QAction(QIcon("rotate.jpg"), tr("旋转270"), this);
    rotate270Action->setStatusTip(tr("旋转270"));
    // 纵向镜像
    mirrorVerticalAction = new QAction(QIcon("vertical.jpg"), tr("纵向镜像"), this);
    mirrorVerticalAction->setStatusTip(tr("纵向镜像"));
    // 横向镜像
    mirrorHorizontalAction = new QAction(QIcon("horizontal.jpg"), tr("横向镜像"), this);
    mirrorHorizontalAction->setStatusTip(tr("横向镜像"));
    // 撤销
    undoAction = new QAction(QIcon("undo.jpg"), tr("撤销"), this);
    undoAction->setStatusTip(tr("撤销"));
    connect(undoAction, SIGNAL(triggered()), showWidget->text, SLOT(undo()));
    // 恢复
    redoAction = new QAction(QIcon("redo.jpg"), tr("恢复"), this);
    redoAction->setStatusTip(tr("恢复"));
    // 排序，左对齐、右对齐、居中、两端对齐
    actGrp = new QActionGroup(this);
    leftAction = new QAction(QIcon("left.png"), "左对齐", actGrp);
    leftAction->setChecked(true);
    rightAction = new QAction(QIcon("right.png"), "右对齐", actGrp);
    rightAction->setChecked(true);
    centerAction = new QAction(QIcon("center.png"), "居中", actGrp);
    centerAction->setChecked(true);
    justifyAction = new QAction(QIcon("justify.png"), "两端对齐", actGrp);
    justifyAction->setChecked(true);

    connect(redoAction, SIGNAL(triggered()), showWidget->text, SLOT(redo()));
    connect(zoomInAction, SIGNAL(triggered()), this, SLOT(ShowZoomIn()));
    connect(zoomOutAction, SIGNAL(triggered()), this, SLOT(ShowZoomOut()));
    connect(rotate90Action, SIGNAL(triggered()), this, SLOT(ShowRotate90()));
    connect(rotate180Action, SIGNAL(triggered()), this, SLOT(ShowRotate180()));
    connect(rotate270Action, SIGNAL(triggered()), this, SLOT(ShowRotate270()));
    connect(mirrorVerticalAction, SIGNAL(triggered()), this, SLOT(ShowMirrorVertical()));
    connect(mirrorHorizontalAction, SIGNAL(triggered()), this, SLOT(ShowMirrorHorizontal()));
    connect(actGrp, SIGNAL(triggered(QAction*)), this, SLOT(ShowAlignment(QAction*)));
}

void ImageProcessor::CreateMenu()
{
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(printTextAction);
    fileMenu->addAction(printImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    zoomMenu = menuBar()->addMenu(tr("编辑"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);

    rotateMenu = menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    mirrorMenu = menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);
}

void ImageProcessor::CreateToolBars()
{
    fileTool = addToolBar("File");
    fileTool->addAction(openFileAction);
    fileTool->addAction(newFileAction);
    fileTool->addAction(printTextAction);
    fileTool->addAction(printImageAction);

    zoomTool = addToolBar("Edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);

    rotateTool = addToolBar("rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

    doToolBar = addToolBar("doEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);

    mirrorTool = addToolBar("Mirror");
    mirrorTool->addAction(mirrorVerticalAction);
    mirrorTool->addAction(mirrorHorizontalAction);

    fontToolBar = addToolBar("Font");
    fontToolBar->addWidget(fontLabel1);
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(fontLabel2);
    fontToolBar->addWidget(sizeComboBox);
    fontToolBar->addWidget(boldBtn);
    fontToolBar->addWidget(italicBtn);
    fontToolBar->addWidget(underlineBtn);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(colorBtn);

    listToolBar = addToolBar("list");
    listToolBar->addWidget(listLabel);
    listToolBar->addWidget(listComboBox);
    listToolBar->addSeparator();
    listToolBar->addActions(actGrp->actions());
}

void ImageProcessor::LoadFile(QString tempFileName)
{
    printf("file name:%s\n", tempFileName.data());
    QFile file(tempFileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream textStream(&file);
        textStream.setCodec(QTextCodec::codecForName("UTF-8"));
        while (!textStream.atEnd()) {
            showWidget->text->append(textStream.readLine());
            printf("read line\n");
        }
        printf("end\n");
    }
}

void ImageProcessor::MergeFormat(QTextCharFormat textCharFormat)
{
    QTextCursor cursor = showWidget->text->textCursor(); // 获得编辑框中的光标
    if (!cursor.hasSelection()) {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(textCharFormat);
    showWidget->text->mergeCurrentCharFormat(textCharFormat);
}

void ImageProcessor::ShowNewFile()
{
    ImageProcessor* newImgProcessor = new ImageProcessor;
    newImgProcessor->show();
}

void ImageProcessor::ShowOpenFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        if (showWidget->text->document()->isEmpty()) {
            LoadFile(fileName);
        } else {
            ImageProcessor* newImgProcessor = new ImageProcessor;
            newImgProcessor->show();
            newImgProcessor->LoadFile(fileName);
        }
    }
}

void ImageProcessor::ShowPrintText()
{
    QPrinter printer;
    QPrintDialog printerDialog(&printer, this);
    if (printerDialog.exec()) {
        QTextDocument* doc = showWidget->text->document();
        doc->print(&printer);
    }
}

void ImageProcessor::ShowPrintImage()
{
    QPrinter printer;
    QPrintDialog printerDialog(&printer, this);
    if (printerDialog.exec()) {
        QPainter painter(&printer);
        QRect tect = painter.viewport();
        QSize size = img.size();
        size.scale(tect.size(), Qt::KeepAspectRatio);
        painter.setViewport(tect.x(), tect.y(), size.width(), size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0, 0, img);
    }
}

void ImageProcessor::ShowZoomIn()
{
    if (img.isNull()) {
        return;
    }
    QMatrix martix;
    martix.scale(2, 2);
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::ShowZoomOut()
{
    if (img.isNull()) {
        return;
    }
    QMatrix martix;
    martix.scale(0.5, 0.5);
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::ShowRotate90()
{
    if (img.isNull()) {
        return;
    }
    QMatrix martix;
    martix.rotate(90);
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::ShowRotate180()
{
    if (img.isNull()) {
        return;
    }
    QMatrix martix;
    martix.rotate(180);
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::ShowRotate270()
{
    if (img.isNull()) {
        return;
    }
    QMatrix martix;
    martix.rotate(270);
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::ShowMirrorVertical()
{
    if (img.isNull()) {
        return;
    }
    QMatrix martix;
    img = img.mirrored(false, true);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::ShowMirrorHorizontal()
{
    if (img.isNull()) {
        return;
    }
    QMatrix martix;
    img = img.mirrored(true, false);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::ShowFontComboBox(QString tempComboBox)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(tempComboBox);
    MergeFormat(fmt);
}

void ImageProcessor::ShowSizeSpinBox(QString spinValue)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked() ? QFont::Bold : QFont::Normal);
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowUnderlineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red, this);
    if (color.isValid()) {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->text->mergeCurrentCharFormat(fmt);
    }
}

void ImageProcessor::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}

void ImageProcessor::ShowList(int index)
{
    QTextCursor cursor = showWidget->text->textCursor();
    if (index != 0) {
        QTextListFormat::Style style = QTextListFormat::ListDisc;
        switch (index) {
        default:
        case 1:
            style = QTextListFormat::ListDisc;
            break;
        case 2:
            style = QTextListFormat::ListCircle;
            break;
        case 3:
            style = QTextListFormat::ListSquare;
            break;
        case 4:
            style = QTextListFormat::ListDecimal;
            break;
        case 5:
            style = QTextListFormat::ListLowerAlpha;
            break;
        case 6:
            style = QTextListFormat::ListUpperAlpha;
            break;
        case 7:
            style = QTextListFormat::ListLowerRoman;
            break;
        case 8:
            style = QTextListFormat::ListUpperRoman;
            break;
        }
        cursor.beginEditBlock();
        QTextBlockFormat blockFmt = cursor.blockFormat();
        QTextListFormat listFmt;
        if (cursor.currentList()) {
            listFmt = cursor.currentList()->format();
        } else {
            listFmt.setIndent(blockFmt.indent() + 1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);
        cursor.endEditBlock();
    } else {
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}

void ImageProcessor::ShowAlignment(QAction *act)
{
    if (act == leftAction) {
        showWidget->text->setAlignment(Qt::AlignLeft);
    }
    if (act == rightAction) {
        showWidget->text->setAlignment(Qt::AlignRight);
    }
    if (act == centerAction) {
        showWidget->text->setAlignment(Qt::AlignCenter);
    }
    if (act == justifyAction) {
        showWidget->text->setAlignment(Qt::AlignJustify);
    }
}

void ImageProcessor::ShowCursorPositionChanged()
{
    if (showWidget->text->alignment() == Qt::AlignLeft) {
        leftAction->setChecked(true);
    }
    if (showWidget->text->alignment() == Qt::AlignRight) {
        rightAction->setChecked(true);
    }
    if (showWidget->text->alignment() == Qt::AlignCenter) {
        centerAction->setChecked(true);
    }
    if (showWidget->text->alignment() == Qt::AlignJustify) {
        justifyAction->setChecked(true);
    }
}
