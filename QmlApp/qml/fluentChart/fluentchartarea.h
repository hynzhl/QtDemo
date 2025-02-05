#ifndef FLUENTCHARTAREA_H
#define FLUENTCHARTAREA_H

#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>
#include <QRectF>

/*一个方形图线区域*/
class FluentChartArea : public QSGGeometryNode
{
public:
    FluentChartArea();

    void updateGeometry(const QRectF& rcFrame);
private:
    QSGGeometry m_geometry;
    QSGFlatColorMaterial m_pColorMaterial;

};


#endif // FLUENTCHARTAREA_H
