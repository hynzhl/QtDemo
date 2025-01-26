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
    FluentChartView(QQuickItem *parent = nullptr);
    Q_INVOKABLE void append(qreal x, qreal y);

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData);


private:
    QSGNode* m_pRootNode;
    QList<QPointF> m_lstSamplesData;
};


#endif // FLUENTCHARTVIEW_H
