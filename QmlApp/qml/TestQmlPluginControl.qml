import QtQuick 2.15
import FluentUI 1.0


Rectangle{
    border.color: "red"
    border.width: 1;
    Row{
        anchors.fill: parent
        spacing: 10
        TextButton{
            width:100;
            height:40
            text:qsTr("测试")
        }

        TextButton{
            width:100;
            height:40
            text:qsTr("测试2")
        }
    }

}
