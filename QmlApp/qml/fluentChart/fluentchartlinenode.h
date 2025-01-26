#ifndef FLUENTCHARTLINENODE_H
#define FLUENTCHARTLINENODE_H

#include <QSGGeometryNode>
#include <QSharedPointer>
#include <QColor>
#include <QList>
#include <QPointF>

class QSGGeometry;
class QSGFlatColorMaterial;

class FluentChartLineNode : public QSGGeometryNode
{
public:
    FluentChartLineNode();
    void setLineColor(const QColor& clr);
    void setLineWidth(int w);
    //
    void updateGeometry(const QRectF& rc, const QList<QPointF> &samples,  qreal ymax,  qreal ymin);
private:
    QSharedPointer<QSGGeometry> m_pGeometry;
    QSharedPointer<QSGFlatColorMaterial> m_pColorMaterial;

    QColor m_clrLine;
    int m_iLineWidth;
};

#endif // FLUENTCHARTLINENODE_H
