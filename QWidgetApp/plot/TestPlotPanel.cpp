#include "TestPlotPanel.h"
#include "plot/MyPlotArea.h"
#include <QHBoxLayout>

TestPlotPanel::TestPlotPanel(QWidget *parent)
    : QDialog(parent)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    MyPlotArea* plot1 = new MyPlotArea(this);
    layout->addWidget(plot1);
    setFixedSize(800, 600);
}
