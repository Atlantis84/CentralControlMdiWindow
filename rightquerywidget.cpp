#include "rightquerywidget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

RightQueryWidget::RightQueryWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* vAll = new QVBoxLayout();
    QHBoxLayout* hBox1 = new QHBoxLayout();
    labelPath = new QLabel(u8"当前未选中路径");
    hBox1->addWidget(labelPath);
//    hBox1->addStretch(1);
    QHBoxLayout* hBox2 = new QHBoxLayout();
    QLabel* labelProduceLineNum = new QLabel(u8"产线号:");
    lineEditProduceNum = new QLineEdit();
    lineEditProduceNum->setStyleSheet("QLineEdit{border:1px solid rgba(0,0,0,100);"
                                      "color:rgba(0,0,0,150);background-color:rgba(0,0,0,0);}"
                                      "QLineEdit:hover{border:2px solid rgba(0,0,0,100);}");
    lineEditProduceNum->setAlignment(Qt::AlignCenter);
    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx,lineEditProduceNum);
    lineEditProduceNum->setValidator(validator);

    QLabel* labelProduceLineName = new QLabel(u8"产线名:");
    comboboxProduceLineName = new QComboBox();
    comboboxProduceLineName->setStyleSheet("QComboBox{border:1px solid rgba(0,0,0,100);"
                                           "color:rgba(0,0,0,150);background-color:rgba(0,0,0,0);min-width:200px;}"
                                           "QComboBox:hover{border:2px solid rgba(0,0,0,100);}");
    comboboxProduceLineName->insertItem(0,u8"电视T201");
    comboboxProduceLineName->insertItem(1,u8"模块T104");
    comboboxProduceLineName->setCurrentIndex(-1);

    QPushButton* btnQuery = new QPushButton(u8"  查 询  ");
    connect(btnQuery,SIGNAL(clicked()),this,SLOT(slot_query()));
    btnQuery->setStyleSheet("QPushButton{color:rgba(0,0,0,150);background-color:rgba(0,0,0,0);}\
                            ");
    QPushButton* btnReset = new QPushButton(u8"  重 置  ");
    connect(btnReset,SIGNAL(clicked()),this,SLOT(slot_reset()));
    btnReset->setStyleSheet("QPushButton{color:rgba(0,0,0,150);background-color:rgba(0,0,0,0);}");
    hBox2->addWidget(labelProduceLineNum);
    hBox2->addWidget(lineEditProduceNum);
    hBox2->addWidget(labelProduceLineName);
    hBox2->addWidget(comboboxProduceLineName);
    hBox2->addWidget(btnQuery);
    hBox2->addWidget(btnReset);
    hBox2->addStretch(1);

    vAll->addLayout(hBox1);
    vAll->addLayout(hBox2);
    this->setLayout(vAll);
}

void RightQueryWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.fillRect(this->rect(),QBrush(QColor(255,255,255)));
}

void RightQueryWidget::slot_rev_path(const QString strPath)
{
    labelPath->clear();
    labelPath->setText(strPath);
}

void RightQueryWidget::slot_query()
{
    if((this->comboboxProduceLineName->currentIndex() != -1) && (this->lineEditProduceNum->text() !=""))
        emit signal_add_sub_window(this->lineEditProduceNum->text(),this->comboboxProduceLineName->currentText());
    else
        ;
}

void RightQueryWidget::slot_reset()
{
    this->lineEditProduceNum->setText("");
    this->comboboxProduceLineName->setCurrentIndex(-1);
}
