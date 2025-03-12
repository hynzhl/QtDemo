#ifndef MYPLOTAREA_H
#define MYPLOTAREA_H

#include "plot/QCustomPlot/qcustomplot.h"
class MyPlotArea : public QCustomPlot
{
    Q_OBJECT
public:
    MyPlotArea(QWidget* parent);

protected:
    void showEvent(QShowEvent* pEvt) override;

};

#endif // MYPLOTAREA_H
