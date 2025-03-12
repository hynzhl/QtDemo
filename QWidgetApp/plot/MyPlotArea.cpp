#include "MyPlotArea.h"
#include <QDebug>
MyPlotArea::MyPlotArea(QWidget *parent)
    : QCustomPlot(parent)
{
    setContentsMargins(100, 100, 100, 100);
    QCPLayoutGrid* pGrid =  plotLayout();
    //pGrid->set
    int i = pGrid->elementCount();
    qDebug()<<"default element count = "<<i;

    QCPLayoutElement* pDefaultElement = pGrid->elementAt(0);
    if(pDefaultElement)
    {
        qDebug()<<"default element rect = "<<pDefaultElement->rect();
        pDefaultElement->setMargins(QMargins(100, 100, 100, 100));
    }


    QCPAxisRect *axisRect = this->axisRect();
    QCPAxis *xAxis = axisRect->axis(QCPAxis::atBottom);

    // 设置轴的外框
    QRect newRect(50, 50, 200, 100); // 调整参数测试效果
    //xAxis->setOuterRect(newRect);

    // 禁用自动调整
    axisRect->setAutoMargins(QCP::msNone);
    //xAxis->setAutoMargins(false);

    //customPlot->replot();
    return;
    QCPAxisRect* V0_150 = new QCPAxisRect(this, true);	// 创建坐标系
    ((QCPLayoutElement*)V0_150)->setOuterRect(QRect(100, 100, 300, 300));
    V0_150->setBackground(QColor(255,0,0, 100));
    //V0_150->axis(QCPAxis::atBottom)->setTicker(dateTicker); // 将时间轴设置在坐标系中
    //V0_150->axis(QCPAxis::atLeft)->setRange(0,150);	// 设置Y轴范围
    V0_150->setupFullAxesBox(true);    // 让四个轴关联，并全部显示出来
    V0_150->setAutoMargins(QCP::msNone);
    V0_150->setRangeDrag(Qt::Horizontal | Qt::Vertical); //水平方向拖动 | 垂直方向移动
    V0_150->setRangeZoom(Qt::Horizontal | Qt::Vertical); //水平方向缩放 | 垂直方向缩放
    //如果是固定坐标系数量，可直接将坐标系添加如布局，\ 此处是动态添加和删除坐标系，所有魏加入布局
    this->plotLayout()->addElement(axisRectCount(),0,V0_150);
}

void MyPlotArea::showEvent(QShowEvent *pEvt)
{
    int i = plotLayout()->elementCount();
    qDebug()<<"default element count = "<<i;

    QCPLayoutElement* pDefaultElement = plotLayout()->elementAt(0);
    if(pDefaultElement)
    {
        qDebug()<<"default element rect = "<<pDefaultElement->rect();
        pDefaultElement->setMargins(QMargins(100, 100, 100, 100));
    }
}
