#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);    
    setWindowTitle("Rectanlge");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)    
        rectBlue.push_back(event->pos());
    else if(event->buttons() == Qt::RightButton)
        rectRed.push_back(event->pos());

    repaint();
}

bool Widget::askOnClose()
{
    int message = QMessageBox::question(this, tr("Close?"), tr("Do you want to close the window?"),QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
    return (message == QMessageBox::Yes);
}

void Widget::closeEvent(QCloseEvent *closeEvent)
{
    if(askOnClose())
        closeEvent->accept();
    else
        closeEvent->ignore();
}

void Widget::paintEvent(QPaintEvent *paintEvent)
{    
    QPainter *painter = new QPainter(this);
    QPen *pen = new QPen(Qt::black);
    QBrush *brush1 = new QBrush(Qt::blue);
    QBrush *brush2 = new QBrush(Qt::red);


    pen->setWidth(3);
    for(int i = 0; i < rectBlue.size(); i++)
    {    
        painter->setPen(*pen);
        painter->setBrush(*brush1);
        painter->drawRect(rectBlue[i].x(), rectBlue[i].y(), 80, 60);
    }

    for (int i = 0; i < rectRed.size(); i++)
    {
        painter->setPen(*pen);
        painter->setBrush(*brush2);
        painter->drawRect(rectRed[i].x(), rectRed[i].y(), 80, 60);
    }
}
