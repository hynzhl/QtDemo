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
    Rectangle{
        anchors.fill: parent
        border.width: 2;
        border.color: "blue"
    }

    Column{
        spacing: 10
        anchors.fill: parent
        Row{
            id:row
            spacing: 20
            anchors.horizontalCenter:parent.horizontalCenter
            Button{
                id:crashBtn
                text: qsTr("crash测试")
                anchors.verticalCenter: parent.verticalCenter
                width:100
                height:40
            }
        }

        TestQmlPluginControl{
            width: wnd.width
            height:wnd.height -  60
            anchors.horizontalCenter:parent.horizontalCenter

        }
    }





}
