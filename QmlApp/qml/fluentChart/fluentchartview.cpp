#include "fluentchartview.h"
#include "qml/fluentChart/fluentchartnode.h"
#include "qml/fluentChart/fluentchartlinenode.h"

FluentChartView::FluentChartView(QQuickItem *parent)
    : QQuickItem(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
}

void FluentChartView::append(qreal x, qreal y)
{
    m_lstSamplesData.append(QPointF(x, y));
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
        rootNode->appendChildNode(rootNode->m_pLineNode);
    }
    //
    rootNode->m_pLineNode->updateGeometry(boundingRect()
                                          , m_lstSamplesData
                                          , 100, 0);

    return rootNode;
}
