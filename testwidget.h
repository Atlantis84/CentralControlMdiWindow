#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
class CircleWidget;
class TestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TestWidget(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *event);
    CircleWidget* circleWgt1;
    CircleWidget* circleWgt2;
    CircleWidget* circleWgt3;
    CircleWidget* circleWgt4;
public:

signals:

public slots:
};

#endif // TESTWIDGET_H
