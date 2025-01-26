#ifndef FLUENTCHARTNODE_H
#define FLUENTCHARTNODE_H


#include <QSGNode>
class FluentChartLineNode;

class FluentChartNode : public QSGNode
{
public:
    FluentChartNode();

    FluentChartLineNode* m_pLineNode;
};

#endif // FLUENTCHARTNODE_H
