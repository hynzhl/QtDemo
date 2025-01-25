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
        border.width: 1;
        border.color: "blue"
    }
    Item{
        id:btnsItem
        anchors.top:parent.top
        anchors.left:parent.left;
        anchors.right: parent.right;
        height:60
        Row{
            id:row
            spacing: 20
            anchors.fill: parent
            anchors.horizontalCenter:parent.horizontalCenter
            Button{
                id:crashBtn
                text: qsTr("测试UI组件")
                anchors.verticalCenter: parent.verticalCenter
                width:100
                height:40
                onClicked: {
                    testUIPluginView.visible = !testUIPluginView.visible;
                }
            }
            Button{
                id:chartViewBtn
                text: qsTr("chartiew")
                anchors.verticalCenter: parent.verticalCenter
                width:100
                height:40
                onClicked: {
                    plotView.visible = !plotView.visible;
                }
            }
        }
    }



    TestQmlPluginControl{
        id:testUIPluginView
        anchors.top: btnsItem.bottom
        anchors.bottom: parent.bottom
        width: parent.width

    }


    PlotPanelExample{
        id:plotView
        anchors.top: btnsItem.bottom
        anchors.bottom: parent.bottom
        width: parent.width
    }







}
