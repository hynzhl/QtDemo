#ifndef QTPLUGININTERFACE_H
#define QTPLUGININTERFACE_H


//1.定义接口虚基类类

#include <QObject>

class QtPluginInterface
{
public:
    QtPluginInterface();
    virtual ~QtPluginInterface() = default;

    virtual void doTask() = 0;
};
//2.Qt宏-声明插件标识符
#define QtPluginInterface_iid "Qt.Demo.QtPluginInterface"
Q_DECLARE_INTERFACE(QtPluginInterface, QtPluginInterface_iid)

#endif // QTPLUGININTERFACE_H
