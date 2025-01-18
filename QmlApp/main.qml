import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import "qrc:/qml"

Window {
    id:wnd
    width: 640
    height: 480
    visible: true
    title: qsTr("QML App")



    TestQmlPluginControl{
        anchors.fill: parent

    }

}
