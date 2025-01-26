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

    enum EPageViewType{
        PageUIPluginView = 0,
        PageChartView,
        PageFluentChartView,
        PageUndefinedView
    }
    //0：plugin 1 chatview  2 fluentChart
    property int ePageViewType: 0
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
                    ePageViewType = 0;
                }
            }
            Button{
                id:chartViewBtn
                text: qsTr("chartiew")
                anchors.verticalCenter: parent.verticalCenter
                width:100
                height:40
                onClicked: {
                    ePageViewType = 1;
                }
            }
            Button{
                id:fluentChartViewBtn
                text: qsTr("fluentChartView")
                anchors.verticalCenter: parent.verticalCenter
                width:100
                height:40
                onClicked: {
                    ePageViewType = 2;
                }
            }
        }
    }



    TestQmlPluginControl{
        id:testUIPluginView
        anchors.top: btnsItem.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        visible:ePageViewType === 0
    }


    PlotPanelExample{
        id:plotView
        anchors.top: btnsItem.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        visible:ePageViewType === 1
    }

    FluentChartExample{
        id:fluentChartView
        anchors.top: btnsItem.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        visible:ePageViewType === 2
    }



}
