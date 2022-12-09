#include "testwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
#include "circlewidget.h"
#include <QLabel>
TestWidget::TestWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* hAll = new QHBoxLayout();
    QVBoxLayout* vBox1= new QVBoxLayout();
    QPushButton* btnTest = new QPushButton();
    btnTest->setStyleSheet("QPushButton{"
                           "background-color:rgba(0,0,0,0);"
                           "border-color:rgba(0,0,0,0);"
                           "min-width:200px;"
                           "max-width:200px;"
                           "min-height:200px;"
                           "max-height:200px;}"
                           "QPushButton:hover{border-color:rgba(0,0,0,0);}");
    const QIcon startIcon = QIcon::fromTheme("",QIcon(":/icon/onebutton.png"));
    btnTest->setIcon(startIcon);
    btnTest->setIconSize(QSize(200,200));
    vBox1->addWidget(btnTest);

    circleWgt1 = new CircleWidget();
    circleWgt1->setStyleSheet("QWidget{min-width:20px;max-width:20px;min-height:20px;max-height:20px;}");
    circleWgt1->set_color(2);
    circleWgt2 = new CircleWidget();
    circleWgt2->setStyleSheet("QWidget{min-width:20px;max-width:20px;min-height:20px;max-height:20px;}");
    circleWgt2->set_color(2);
    circleWgt3 = new CircleWidget();
    circleWgt3->setStyleSheet("QWidget{min-width:20px;max-width:20px;min-height:20px;max-height:20px;}");
    circleWgt3->set_color(2);
    circleWgt4 = new CircleWidget();
    circleWgt4->setStyleSheet("QWidget{min-width:20px;max-width:20px;min-height:20px;max-height:20px;}");
    circleWgt4->set_color(2);
    QVBoxLayout* vBox2 = new QVBoxLayout();
    QHBoxLayout* vBox2_hBox1 = new QHBoxLayout();
    QLabel* labelStart = new QLabel(u8"Start");
    labelStart->adjustSize();
    vBox2_hBox1->addWidget(circleWgt1);
    vBox2_hBox1->addWidget(labelStart);
    QHBoxLayout* vBox2_hBox2 = new QHBoxLayout();
    QLabel* labelMachineModel = new QLabel(u8"扫码获取机型");
    labelMachineModel->adjustSize();
    vBox2_hBox2->addWidget(circleWgt2);
    vBox2_hBox2->addWidget(labelMachineModel);
    QHBoxLayout* vBox2_hBox3 = new QHBoxLayout();
    QLabel* labelPlan = new QLabel(u8"测试方案自动更新");
    labelPlan->adjustSize();
    vBox2_hBox3->addWidget(circleWgt3);
    vBox2_hBox3->addWidget(labelPlan);
    QHBoxLayout* vBox2_hBox4 = new QHBoxLayout();
    QLabel* labelEnd = new QLabel(u8"End");
    labelEnd->adjustSize();
    vBox2_hBox4->addWidget(circleWgt4);
    vBox2_hBox4->addWidget(labelEnd);
    vBox2->addStretch(5);
    vBox2->addLayout(vBox2_hBox1);
    vBox2->addStretch(1);
    vBox2->addLayout(vBox2_hBox2);
    vBox2->addStretch(1);
    vBox2->addLayout(vBox2_hBox3);
    vBox2->addStretch(1);
    vBox2->addLayout(vBox2_hBox4);
    vBox2->addStretch(5);

    hAll->addStretch(5);
    hAll->addLayout(vBox1);
    hAll->addStretch(2);
    hAll->addLayout(vBox2);
    hAll->addStretch(5);
    this->setLayout(hAll);
}

void TestWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    CircleWidget* cw[] = {circleWgt1,circleWgt2,circleWgt3,circleWgt4};
    for (int i=0;i<3;i++)
    {
        painter.drawLine(cw[i]->geometry().x()+cw[i]->width()/2,cw[i]->geometry().y()+cw[i]->height()/2,
                         cw[i+1]->geometry().x()+cw[i+1]->width()/2,cw[i+1]->geometry().y()+cw[i+1]->height()/2);
    }
//    QPixmap *img = new QPixmap(":/icon/back_net1.jpg");
//    QPixmap *img1 = new QPixmap(":/icon/CIA.png");
//    painter.drawPixmap(this->rect(),*img);
//    painter.drawPixmap(200,200,200,200,*img1);
}
