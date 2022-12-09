#include "mainwindow.h"
#include <qdesktopwidget.h>
#include <QApplication>
#include "TitleBar.h"
#include <QPainter>
#include "gdatafactory.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | windowFlags() | Qt::Widget);
    setWindowIcon(QIcon(":/icon/24x24.png"));
    this->setStyleSheet("QMainWindow{background-color:#000000}");
    resize(1600,1000);
    QDesktopWidget* desktop = QApplication::desktop();
    int w,h;
    w = desktop->screenGeometry().width();
    h = desktop->screenGeometry().height();
    this->setGeometry(w/2-800,h/2-500,1600,1000);

    GDataFactory::get_central_wgt()->setGeometry(0,40,this->width(),this->height()-40);
    GDataFactory::get_central_wgt()->setParent(this);
    GDataFactory::get_central_wgt()->show();

    TitleBar *pTitleBar = new TitleBar(this);
    pTitleBar->setTitle(u8"�п�ϵͳDemo");
    pTitleBar->setFixedWidth(1600);
    installEventFilter(pTitleBar);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.fillRect(this->rect(),QBrush(QColor(240,242,245)));
    return;
    QPixmap *img = new QPixmap(":/icon/back_net.jpg");
    QRect backR(0,0,this->width(),this->height());
    QRect imgRect;
    imgRect.setTopLeft(QPoint(1,1));
    imgRect.setBottomRight(QPoint(this->width()-2,this->height()-1));
    painter.drawPixmap(backR,*img);
}
