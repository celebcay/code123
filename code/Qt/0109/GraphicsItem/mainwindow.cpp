#include "mainwindow.h"
#include "flashitem.h"
#include "startitem.h"
#include <QGraphicsItemAnimation>
#include <QTimeLine>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
    scene = new QGraphicsScene;
    scene->setSceneRect(-200, -200, 400, 400);
    initScene();
    QGraphicsView* view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400, 400);
    view->show();
    setCentralWidget(view);
    resize(550, 450);
    setWindowTitle(tr("Graphics Items"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::initScene()
{
    int i;
    for (i = 0; i < 3; i++) {
        slotAddEllipseItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddPolygonItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddTextItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddRectItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddAlphaItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddFlashItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddAnimationItem();
    }
}

void MainWindow::createActions()
{
    newAct = new QAction(tr("新建"), this);
    clearAct = new QAction(tr("清除"), this);
    exitAct = new QAction(tr("退出"), this);
    addEllipseItemAct = new QAction(tr("加入 椭圆"), this);
    addPolygonItemAct = new QAction(tr("加入 多边形"), this);
    addTextItemAct = new QAction(tr("加入 文字"), this);
    addRectItemAct = new QAction(tr("加入 长方形"), this);
    addAlphaItemAct = new QAction(tr("加入 透明图片"), this);
    addFlashItemAct = new QAction(tr("加入 闪烁圆"), this);
    addAnimItemAct = new QAction(tr("加入 星星"), this);

    connect(newAct, SIGNAL(triggered()), this, SLOT(slotNew()));
    connect(clearAct, SIGNAL(triggered()), this, SLOT(slotClear()));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    connect(addEllipseItemAct, SIGNAL(triggered()), this, SLOT(slotAddEllipseItem()));
    connect(addPolygonItemAct, SIGNAL(triggered()), this, SLOT(slotAddPolygonItem()));
    connect(addTextItemAct, SIGNAL(triggered()), this, SLOT(slotAddTextItem()));
    connect(addRectItemAct, SIGNAL(triggered()), this, SLOT(slotAddRectItem()));
    connect(addAlphaItemAct, SIGNAL(triggered()), this, SLOT(slotAddAlphaItem()));
    connect(addFlashItemAct, SIGNAL(triggered()), this, SLOT(slotAddFlashItem()));
    connect(addAnimItemAct, SIGNAL(triggered()), this, SLOT(slotAddAnimationItem()));
}

void MainWindow::createMenus()
{
    QMenu* fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(clearAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    QMenu* itemsMenu = menuBar()->addMenu(tr("元素"));
    itemsMenu->addAction(addEllipseItemAct);
    itemsMenu->addAction(addPolygonItemAct);
    itemsMenu->addAction(addTextItemAct);
    itemsMenu->addAction(addRectItemAct);
    itemsMenu->addAction(addAlphaItemAct);
    itemsMenu->addAction(addFlashItemAct);
    itemsMenu->addAction(addAnimItemAct);
}

void MainWindow::slotNew()
{
    slotClear();
    initScene();
    MainWindow* newWin = new MainWindow;
    newWin->show();
}

void MainWindow::slotClear()
{
    QList<QGraphicsItem*> listItem = scene->items();
    while (!listItem.empty()) {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}

void MainWindow::slotAddEllipseItem()
{
    QGraphicsEllipseItem* item = new QGraphicsEllipseItem(QRectF(0, 0, 80, 60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand()%256, qrand()%256, qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width())) - 200,
                 (qrand()%int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddPolygonItem()
{
    QVector<QPoint> v;
    v<<QPoint(30, -15)<<QPoint(0, -30)<<QPoint(-30, -15)
    <<QPoint(-30, 15)<<QPoint(0, 30)<<QPoint(30, 15);
    QGraphicsPolygonItem *item = new QGraphicsPolygonItem(QPolygonF(v));
    item->setBrush(QColor(qrand()%256, qrand()%256, qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width())) - 200,
                 (qrand()%int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddTextItem()
{
    QFont font("Times", 16);
    QGraphicsTextItem* item = new QGraphicsTextItem(tr("Hello Qt!"));
    item->setFont(font);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setDefaultTextColor(QColor(qrand()%256, qrand()%256, qrand()%256));
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width())) - 200,
                 (qrand()%int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddRectItem()
{
    QGraphicsRectItem* item = new QGraphicsRectItem(QRectF(0, 0, 60, 60));
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
    item->setPen(pen);
    item->setBrush(QColor(qrand()%256, qrand()%256, qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width())) - 200,
                 (qrand()%int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddAlphaItem()
{
    QGraphicsPixmapItem* item = scene->addPixmap(QPixmap("123.png"));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos((qrand()%int(scene->sceneRect().width())) - 200,
                 (qrand()%int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddFlashItem()
{
    FlashItem* item = new FlashItem;
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width())) - 200,
                 (qrand()%int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddAnimationItem()
{
    StartItem* item = new StartItem;
    QGraphicsItemAnimation* anim = new QGraphicsItemAnimation;
    anim->setItem(item);
    QTimeLine* timeLine = new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);
    anim->setTimeLine(timeLine);
    int y = (qrand() % 400) - 200;
    for (int i = 0; i < 400; i++) {
        anim->setPosAt(i/400.0, QPointF(i - 200, y));
    }
    timeLine->start();
    scene->addItem(item);
}