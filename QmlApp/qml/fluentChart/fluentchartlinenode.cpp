#include "fluentchartlinenode.h"
#include <QSGGeometry>
#include <QSGMaterial>
#include <QSGFlatColorMaterial>
#include <QDebug>


FluentChartLineNode::FluentChartLineNode()
    : QSGGeometryNode()
    , m_clrLine(Qt::blue)
    , m_iLineWidth(2)
    , m_pGeometry(QSGGeometry::defaultAttributes_Point2D(), 2)
{
    //1.创建图形对象
    //count:属性个数  数据步长
    QSGGeometry::AttributeSet attrSet = QSGGeometry::defaultAttributes_Point2D();//分配顶点属性集合
    //m_pGeometry = QSharedPointer<QSGGeometry>(new QSGGeometry(attrSet, 0));
    //m_pGeometry.attributes()
    qDebug()<<"attri size = "<<sizeof(m_pGeometry.attributes());
    setGeometry(&m_pGeometry);
    m_pGeometry.setDrawingMode(QSGGeometry::DrawLineStrip);
    m_pGeometry.setLineWidth(m_iLineWidth);
    //2.设置材质对象:可以使用颜色纹理、图像纹理
    //m_pMaterial = QSharedPointer<QSGMaterial>(new QSGMaterial());
    //这里先用纯颜色纹理
    //m_pColorMaterial = QSharedPointer<QSGFlatColorMaterial>(new QSGFlatColorMaterial());
    //m_pColorMaterial->setColor(m_clrLine);
    m_pColorMaterial.setColor(m_clrLine);

    setMaterial(&m_pColorMaterial);
    //3.
}

void FluentChartLineNode::setLineColor(const QColor &clr)
{
    m_clrLine = clr;
    m_pColorMaterial.setColor(clr);
    markDirty(DirtyMaterial);
}

void FluentChartLineNode::setLineWidth(int w)
{
    m_iLineWidth = w;
    m_pGeometry.setLineWidth(w);
    markDirty(DirtyGeometry);
}

void FluentChartLineNode::updateGeometry(const QRectF &rc, const QList<QPointF> &samples
                                         , qreal yMax, qreal yMin
                                         , qreal xMax, qreal xMin)
{
    //0.预处理数据
    QList<QPointF> lstDatas;
    for(int index=0; index<samples.size(); index++){
        QPointF ptTarget = samples.at(index);
        if(ptTarget.x()<xMin || ptTarget.x() >xMax)
            continue;

        if(ptTarget.y()<yMin || ptTarget.y()>yMax)
            continue;

        lstDatas.append(ptTarget);

    }
    //绘制线
    //1. 申请分配点数据内存:(x, y）分量 所以乘以2
    QSGGeometry* pGeometry = geometry();
    if(lstDatas.count() > 0 && pGeometry)
        pGeometry->allocate(lstDatas.count());
    else
        return;


    //2.填充点数据
    QSGGeometry::Point2D* pPointsData = pGeometry->vertexDataAsPoint2D();
    //QPointF  lastPt =lstDatas.back();
    qreal dx = rc.width()*1.0/(xMax - xMin)*1.0;
    qreal dy = rc.height()*1.0/(yMax - yMin)*1.0;
    //转换坐标
    for(int index=0; index<lstDatas.size(); index++){
        QPointF ptTarget = lstDatas.at(index);

        //超过区域就用最大/最小值
        qreal ptX = (ptTarget.x() - xMin)*dx;
        qreal ptY = (ptTarget.y() - yMin)*dy;
        ptY = rc.height() - ptY;
        // if(ptTarget.y()<ymin){
        //     ptY = (ymin - ymin)*dy;
        //     ptY = rc.height() - ptY;
        // }
        // else if( ptTarget.y()>ymax){
        //     ptY = (ymax - ymin)*dy;
        //     ptY = rc.height() - ptY;
        // }
        // else
        //{
        //    ptY = (ptTarget.y() - yMin)*dy;
        //    ptY = rc.height() - ptY;
        //}
        pPointsData[index].set(ptX, ptY);
    }

    markDirty(QSGNode::DirtyGeometry);
}

// void FluentChartLineNode::updateGeometry(const QRectF &rc, const QList<QPointF> &samples
//     , qreal ymax, qreal ymin)
// {
//     qDebug()<<"FluentChartLineNode::updateGeometry";//<<samples.count()<<m_pGeometry.get();
// #if 1
//     //绘制线
//     //1. 申请分配点数据内存:(x, y）分量 所以乘以2
//     QSGGeometry* pGeometry = geometry();
//     if(samples.count() > 0 && pGeometry)
//        pGeometry->allocate(samples.count());
//     else
//         return;


//     //2.填充点数据
//     QSGGeometry::Point2D* pPointsData = pGeometry->vertexDataAsPoint2D();
//     //qDebug()<<"allocLen = "<<allocLen;
//     // for(int i=0; i<samples.count(); i++){
//     //     pPointsData[i].set(samples[i].x(), samples[i].y());
//     // }
//     //预设跨度：30秒
//     int timeSpan = 30;
//     QPointF  lastPt =samples.back();
//     //已经超过一个屏幕了
//     // if(lastPt.x() > timeSpan){

//     // }
//     // else
//     {
//         qreal dx = rc.width()*1.0/timeSpan;
//         qreal dy = rc.height()*1.0/(ymax - ymin)*1.0;
//         //转换坐标
//         for(int index=0; index<samples.size(); index++){
//             QPointF ptTarget = samples.at(index);
//             //超过区域就用最大/最小值
//             qreal ptX = (ptTarget.x() - 0)*dx;
//             qreal ptY = 0.0;
//             if(ptTarget.y()<ymin){
//                 ptY = (ymin - ymin)*dy;
//                 ptY = rc.height() - ptY;
//             }
//             else if( ptTarget.y()>ymax){
//                 ptY = (ymax - ymin)*dy;
//                 ptY = rc.height() - ptY;
//             }
//             else
//             {
//                 ptY = (ptTarget.y() - ymin)*dy;
//                 ptY = rc.height() - ptY;
//             }
//             //qDebug()<<"ptX:"<<ptX<<"ptY:"<<ptY;
//             pPointsData[index].set(ptX, ptY);
//         }
//     }

// #else
//       //测试  画个对角线
//         //分配点
//     geometry()->allocate(2);

//     QSGGeometry::Point2D* pPointsData = geometry()->vertexDataAsPoint2D();
//     //
//     QSGGeometry::Point2D ptLeftTop;
//     ptLeftTop.x = 0;
//     ptLeftTop.y = 0;
//     pPointsData[0].set(ptLeftTop.x, ptLeftTop.y);

//     QSGGeometry::Point2D ptRightBottom;
//     ptRightBottom.x = rc.width();
//     ptRightBottom.y = rc.height();
//     pPointsData[1].set(ptRightBottom.x, ptRightBottom.y);
// #endif


//     markDirty(QSGNode::DirtyGeometry);


// }

