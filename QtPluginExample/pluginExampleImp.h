#ifndef PLUGINEXAMPLEIMP_H
#define PLUGINEXAMPLEIMP_H

//Step3:创建插件实现功能类
#include "QtPluginExample_global.h"
#include "qtplugininterface.h"
#include <QObject>
#include <QtCore>
class QTPLUGINEXAMPLE_EXPORT PluginExampleImp : public QObject, public QtPluginInterface
{
    Q_OBJECT
    //Step4:声明插件的元对象信息
    //Q_PLUGIN_METADATA(IID QtPluginInterface_iid FILE "PluginExampleImp.json") // 注册插件元数据
    Q_PLUGIN_METADATA(IID QtPluginInterface_iid) // 注册插件元数据
    //Step5：告诉Qt这个类是哪一个插件接口类的实现类
    Q_INTERFACES(QtPluginInterface)
public:
    explicit PluginExampleImp(QObject *parent = nullptr);

    void doTask() override;
signals:
};


#endif // PLUGINEXAMPLEIMP_H
