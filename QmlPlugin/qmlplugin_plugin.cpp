#include "qmlplugin_plugin.h"

#include <qqml.h>

void QmlPluginPlugin::registerTypes(const char *uri)
{
    // @uri FluentUI
    //qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
    qmlRegisterType(QUrl("qrc:/TextButton.qml"), uri, 1, 0, "TextButton");
}
