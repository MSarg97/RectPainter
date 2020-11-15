#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QPaintEvent>
#include <QMessageBox>
#include <QVector>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void closeEvent(QCloseEvent *);
    virtual void paintEvent(QPaintEvent *);
    bool askOnClose();
    ~Widget();

private:
    Ui::Widget *ui;
    double x;
    double y;        
    QVector<QPoint> rectBlue;
    QVector<QPoint> rectRed;
};
#endif // WIDGET_H
