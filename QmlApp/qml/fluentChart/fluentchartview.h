#ifndef FLUENTCHARTVIEW_H
#define FLUENTCHARTVIEW_H

#include <QQuickItem>
#include <QList>
#include <QPointF>

class QSGNode;

class FluentChartView : public QQuickItem
{
    Q_OBJECT


public:
    enum ChartViewType{
        ViewType_Roll,
        ViewType_Page,
//        chartType_Mid
    };

    Q_ENUM(ChartViewType)
    FluentChartView(QQuickItem *parent = nullptr);
    Q_INVOKABLE void append(qreal x, qreal y);
    //待实现
    //1.设置线宽
    //2.更新垂直坐标最小值、最大值
    //3.更新水平坐标最小值、最大值
    Q_INVOKABLE void updateAxesRange(int, int, int, int);

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData);

    bool needRemove();
    QList<QPointF> samplesData();
private:
    QSGNode* m_pRootNode;
    QList<QPointF> m_lstOnePgaeData;//始终只展示一屏的数据
    QList<QPointF> m_lstAllSamplesData;//所有的采集点
    int m_iYMax;
    int m_iYMin;
    int m_iXMax;
    int m_iXMin;
    ChartViewType m_eViewType;
};



#endif // FLUENTCHARTVIEW_H
