#include "pluginExampleImp.h"
#include <QDebug>
PluginExampleImp::PluginExampleImp(QObject *parent)
    : QObject{parent}
{}

void PluginExampleImp::doTask()
{
    qDebug()<<"PluginExampleImp::doTask";
}
