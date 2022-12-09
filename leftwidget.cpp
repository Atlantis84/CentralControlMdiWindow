#include "leftwidget.h"
#include <QPainter>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QList>
#include <QDebug>
LeftWidget::LeftWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* vAll = new QVBoxLayout();
    QVBoxLayout* vBottom = new QVBoxLayout();

    QTreeWidget *treeWidget = new QTreeWidget();
    connect(treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(slot_getPath(QTreeWidgetItem*,int)));
    treeWidget->setColumnCount(1);
    treeWidget->setFont(QFont(u8"LiSu",15,QFont::Bold,false));
    QList<QTreeWidgetItem*> items;
    for (int i=0;i<2;i++)
    {
        if(i==0)
        {
            items.append(new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString(u8"换产管理"))));
            items.at(i)->addChild(new QTreeWidgetItem(items.at(i),QStringList(QString(u8"一键换产"))));
        }
        else
        {
            items.append(new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString(u8"其他操作"))));
            for (int j=0;j<3;j++)
                items.at(i)->addChild(new QTreeWidgetItem(items.at(i),QStringList(QString(u8"操作:%1").arg(j))));
        }
    }
    treeWidget->insertTopLevelItems(0,items);
    treeWidget->setHeaderHidden(true);




    vBottom->addWidget(treeWidget);

    vAll->addSpacing(80);
    vAll->addLayout(vBottom);
    this->setLayout(vAll);
}

void LeftWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.fillRect(this->rect(),QBrush(QColor(22,194,194)));
    int headHeight = this->height()/13;
    QRect rtHead(0,0,this->width(),headHeight);
    painter.fillRect(rtHead,QBrush(QColor(0,166,170)));
    QRect rtHeadLeft(5,10,this->width()/2-10,headHeight-20);
    QRect rtHeadRight(this->width()/2,0,this->width()/2,headHeight);
    painter.fillRect(rtHeadLeft,QBrush(QColor(255,255,255)));

    painter.setFont(QFont(u8"LiSu",20,QFont::Bold,false));

    painter.save();
    painter.setPen(QColor(27,162,160));
    painter.drawText(rtHeadLeft,Qt::AlignHCenter | Qt::AlignVCenter,u8"Hisense");
    painter.restore();

    painter.setPen(Qt::white);
    painter.drawText(rtHeadRight,Qt::AlignHCenter | Qt::AlignVCenter,u8"中控系统");

}

void LeftWidget::slot_getPath(QTreeWidgetItem *wItem, int count)
{
    QStringList filePath;
    QTreeWidgetItem *itemFile = wItem;
    while (itemFile != nullptr)
    {
        filePath<<itemFile->text(0);
        itemFile = itemFile->parent();
    }

    QString strPath;
    for (int i=filePath.size()-1;i>=0;i--)
    {
        strPath +=filePath.at(i);
        if(i!=0)
            strPath+="/";
    }
//    qDebug()<<strPath;
    emit signal_send_path(strPath);
}
