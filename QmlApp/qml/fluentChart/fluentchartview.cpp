#include "fluentchartview.h"
#include "qml/fluentChart/fluentchartnode.h"
#include "qml/fluentChart/fluentchartlinenode.h"
#include "qml/fluentChart/fluentchartarea.h"

FluentChartView::FluentChartView(QQuickItem *parent)
    : QQuickItem(parent)
    , m_eViewType(ViewType_Roll)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setSmooth(true);
}

void FluentChartView::append(qreal x, qreal y)
{
    if(ViewType_Roll == m_eViewType){
        needRemove();
        m_lstOnePgaeData.append(QPointF(x, y));

    }
    m_lstAllSamplesData.append(QPointF(x, y));
    update();
}

void FluentChartView::updateAxesRange(int xMax, int xMin, int yMax, int yMin)
{
    m_iYMax = yMax;
    m_iYMin = yMin;
    m_iXMax = xMax;
    m_iXMin = xMin;
    update();
}


QSGNode *FluentChartView::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *updatePaintNodeData)
{
    FluentChartNode *rootNode= static_cast<FluentChartNode *>(oldNode);
    QRectF rect = boundingRect();
    if (rect.isEmpty() && rootNode) {
        delete rootNode;
        return nullptr;
    }
    if(!rootNode){
        rootNode = new FluentChartNode();
        //
        rootNode->m_pLineNode = new FluentChartLineNode();
        rootNode->m_pPlotArea = new FluentChartArea();
        rootNode->appendChildNode(rootNode->m_pLineNode);
        rootNode->appendChildNode(rootNode->m_pPlotArea);
    }
    //
    rootNode->m_pLineNode->updateGeometry(boundingRect()
                                          , samplesData()
                                          , m_iYMax, m_iYMin
                                          , m_iXMax, m_iXMin);
    //优化1：变化才需要更新
    rootNode->m_pPlotArea->updateGeometry(boundingRect());

    return rootNode;
}

bool FluentChartView::needRemove()
{
    if(ViewType_Roll == m_eViewType){
        ///m_lstOnePgaeData.size()>0 &&
    }


    return false;
}

QList<QPointF> FluentChartView::samplesData()
{
    if(ViewType_Roll == m_eViewType){
        return m_lstOnePgaeData;
    }
    else
        return m_lstAllSamplesData;
}
