#include "fluentchartlinenode.h"
#include <QSGGeometry>
#include <QSGMaterial>
#include <QSGFlatColorMaterial>
#include <QDebug>


FluentChartLineNode::FluentChartLineNode()
    : QSGGeometryNode()
    , m_clrLine(Qt::red)
    , m_iLineWidth(1)
{
    //1.创建图形对象
    //count:属性个数  数据步长
    QSGGeometry::AttributeSet attrSet = QSGGeometry::defaultAttributes_Point2D();//分配顶点属性集合
    m_pGeometry = QSharedPointer<QSGGeometry>(new QSGGeometry(attrSet, 0));
    setGeometry(m_pGeometry.get());
    m_pGeometry->setDrawingMode(QSGGeometry::DrawLineStrip);
    //2.设置材质对象:可以使用颜色纹理、图像纹理
    //m_pMaterial = QSharedPointer<QSGMaterial>(new QSGMaterial());
    //这里先用纯颜色纹理
    m_pColorMaterial = QSharedPointer<QSGFlatColorMaterial>(new QSGFlatColorMaterial());
    m_pColorMaterial->setColor(m_clrLine);
    setMaterial(m_pColorMaterial.get());
    //3.
}

void FluentChartLineNode::setLineColor(const QColor &clr)
{
    m_clrLine = clr;
    m_pColorMaterial->setColor(clr);
    markDirty(DirtyMaterial);
}

void FluentChartLineNode::setLineWidth(int w)
{
    m_iLineWidth = w;
    m_pGeometry->setLineWidth(w);
    markDirty(DirtyGeometry);
}

void FluentChartLineNode::updateGeometry(const QRectF &rc, const QList<QPointF> &samples
    , qreal ymax, qreal ymin)
{
    qDebug()<<"FluentChartLineNode::updateGeometry"<<samples.count()<<m_pGeometry.get();
    //绘制线
    //1. 申请分配点数据内存:(x, y）分量 所以乘以2
    QSGGeometry* pGeometry = geometry();
    if(samples.count() > 0 && !pGeometry)
       pGeometry->allocate(samples.count());


    //2.填充点数据
    // QSGGeometry::Point2D* pPointsData = pGeometry->vertexDataAsPoint2D();
    // //int allocLen = sizeof(pPointsData);
    // //qDebug()<<"allocLen = "<<allocLen;
    // for(int i=0; i<samples.count(); i++){
    //         pPointsData[i].set(samples[i].x(), samples[i].y());
    // }
}

