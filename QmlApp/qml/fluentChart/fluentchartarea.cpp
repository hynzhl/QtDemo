#include "fluentchartarea.h"

FluentChartArea::FluentChartArea()
    : QSGOpacityNode()
    , m_geoGrid(QSGGeometry::defaultAttributes_Point2D(), 0)
{
    //
    m_geoGrid.setDrawingMode(QSGGeometry::DrawLines);
    m_geoGrid.setLineWidth(2);
    m_gridLine.setGeometry(&m_geoGrid);
    m_pGridColorMaterial.setColor(Qt::blue);
    m_gridLine.setMaterial(&m_pGridColorMaterial);
    //
    m_fill.setColor(Qt::yellow);
    //节点的添加顺序也很重要
    appendChildNode(&m_fill);
    appendChildNode(&m_gridLine);
    setOpacity(0.2);

}

void FluentChartArea::updateGeometry(const QRectF &rcFrame)
{
    //设置背景色
    m_fill.setRect(rcFrame);
    //4行4列  16
    int rowCnt = 4;
    int columnCnt = 4;
    //分配点
    m_gridLine.geometry()->allocate(rowCnt * columnCnt);
    //填充点数据
    QSGGeometry::Point2D* vertexDatas = m_gridLine.geometry()->vertexDataAsPoint2D();
    int iVertexIndex=0;
    //绘制纵线
    for(int iColNo=0; iColNo<columnCnt; iColNo++)
    {
        vertexDatas[iVertexIndex].set(rcFrame.width()/columnCnt * iColNo, 0);
        vertexDatas[iVertexIndex+1].set(rcFrame.width()/columnCnt * iColNo, rcFrame.height());
        iVertexIndex += 2;
    }
    //绘制水平线
    for(int iRowNo=0; iRowNo<rowCnt; iRowNo++)
    {
        vertexDatas[iVertexIndex].set(0, rcFrame.height()/rowCnt * iRowNo);
        vertexDatas[iVertexIndex+1].set(rcFrame.width(), rcFrame.height()/rowCnt * iRowNo);
        iVertexIndex += 2;
    }

    markDirty(DirtyGeometry);
    m_gridLine.markDirty(DirtyGeometry);
}
