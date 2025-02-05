#ifndef FLUENTCHARTAREA_H
#define FLUENTCHARTAREA_H

#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>
#include <QSGSimpleRectNode>
#include <QRectF>
#include <QSGOpacityNode>

/*一个方形图线区域*/
class FluentChartArea : public QSGOpacityNode
{
public:
    FluentChartArea();

    void updateGeometry(const QRectF& rcFrame);
private:
    //
    QSGSimpleRectNode m_fill;
    //
    QSGGeometryNode m_gridLine;
    QSGGeometry m_geoGrid;
    QSGFlatColorMaterial m_pGridColorMaterial;
    //
};


#endif // FLUENTCHARTAREA_H
