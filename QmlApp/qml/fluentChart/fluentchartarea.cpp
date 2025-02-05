#include "fluentchartarea.h"

FluentChartArea::FluentChartArea()
    : QSGGeometryNode()
    , m_geometry(QSGGeometry::defaultAttributes_Point2D(), 0)
{

    setGeometry(&m_geometry);
    m_geometry.setLineWidth(2);
    m_geometry.setDrawingMode(QSGGeometry::DrawLineLoop);
    setMaterial(&m_pColorMaterial);
    m_pColorMaterial.setColor(Qt::red);


}

void FluentChartArea::updateGeometry(const QRectF &rcFrame)
{
    //分配点
    geometry()->allocate(4);
    //填充点数据
    QSGGeometry::Point2D* vertexDatas = geometry()->vertexDataAsPoint2D();
    vertexDatas[0].set(0, 0);
    vertexDatas[1].set(rcFrame.width(), 0);
    vertexDatas[2].set(rcFrame.width(), rcFrame.height());
    vertexDatas[3].set(0, rcFrame.height());
    markDirty(DirtyGeometry);
}
