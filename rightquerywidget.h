#ifndef RIGHTQUERYWIDGET_H
#define RIGHTQUERYWIDGET_H

#include <QWidget>
class QLabel;
class QComboBox;
class QLineEdit;
class RightQueryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightQueryWidget(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent *event);
    QLabel* labelPath;
    QComboBox* comboboxProduceLineName;
    QLineEdit* lineEditProduceNum;
public:

signals:
    void signal_add_sub_window(const QString lineNum,const QString lineName);
public slots:
    void slot_rev_path(const QString strPath);
    void slot_query();
    void slot_reset();
};

#endif // RIGHTQUERYWIDGET_H
