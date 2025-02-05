#ifndef FLUENTCHARTNODE_H
#define FLUENTCHARTNODE_H


#include <QSGNode>
class FluentChartLineNode;
class FluentChartArea;


class FluentChartNode : public QSGNode
{
public:
    FluentChartNode();

    FluentChartLineNode* m_pLineNode;
    //plot area
    FluentChartArea* m_pPlotArea;

};

#endif // FLUENTCHARTNODE_H
