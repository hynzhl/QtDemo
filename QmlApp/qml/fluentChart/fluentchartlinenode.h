#ifndef FLUENTCHARTLINENODE_H
#define FLUENTCHARTLINENODE_H

#include <QSGGeometryNode>
#include <QSharedPointer>
#include <QColor>
#include <QList>
#include <QPointF>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>

class QSGGeometry;
class QSGFlatColorMaterial;

class FluentChartLineNode : public QSGGeometryNode
{
public:
    FluentChartLineNode();
    void setLineColor(const QColor& clr);
    void setLineWidth(int w);
    //
    void updateGeometry(const QRectF& rc, const QList<QPointF> &samples
                        ,  qreal ymax,  qreal ymin
                        , qreal xMax, qreal xMin);
private:
    QSGGeometry m_pGeometry;
    //QSharedPointer<QSGGeometry> m_pGeometry;  不能用智能指针
    //QSharedPointer<QSGFlatColorMaterial> m_pColorMaterial;
    QSGFlatColorMaterial m_pColorMaterial;

    QColor m_clrLine;
    int m_iLineWidth;
};

#endif // FLUENTCHARTLINENODE_H
