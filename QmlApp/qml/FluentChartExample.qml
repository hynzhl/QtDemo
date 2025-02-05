import QtQuick 2.15
import FluentChart 1.0
import QtCharts 2.15
import QtQuick.Controls 2.0

Rectangle{
    id:root
    border.width: 1;
    border.color: "red"

    Item{
        id:priObj
        property var chartDataArray: new Array
        property real curTimePoint:0    //当前时刻
        property real startTime: 0      //坐标起点
        property int timeRange: 10//展示30秒内的数据
        property int timeInterval: 2
        property int yMax: 100
        property int yMin: 10
        property int updateInterval: 50
        property bool isRunning: false

        function reset(){
            curTimePoint = 0;
            chartDataArray.splice(0, chartDataArray.length);
        }


        function updateChartView(){
            if(!priObj.isRunning){
                return;
            }

            priObj.curTimePoint += priObj.updateInterval/1000.0;//转换成秒

            var pt = Qt.point(priObj.curTimePoint, getRandomNum());
            console.log("x:",pt.x, "; y:", pt.y)
            chartView.append(pt.x, pt.y);
        }

        //生成随机数(>=Min,<=Max)
        function getRandomNum()
        {
            var Range = yMax - yMin;
            var Rand = Math.random();
            return(yMin + Math.round(Rand * Range));
        }
    }

    Item{
        id:itemTop
        anchors.top:parent.top
        width: parent.width
        height:60
        Row{
            anchors.centerIn: parent
            spacing: 20
            Button{
                id:startBtn
                width: 80
                height: 40
                text:priObj.isRunning ? "暂停" : "开始";
                onClicked: {
                    if(!testDataTimer.running)
                        testDataTimer.restart();
                    priObj.isRunning = !priObj.isRunning;
                }
            }

            Button{
                id:plusBtnss
                width: 80
                height: 40
                text:"+"
                onClicked: {
                    priObj.yMin += 10
                }
            }

            Button{
                id:minusBtnss
                width: 80
                height: 40
                text:"-"
                onClicked: {
                    priObj.yMin -= 10
                }
            }

        }

    }


    FluentChartView {
        id:chartView
        anchors.top: itemTop.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        //height:parent.height
        antialiasing: true
        //legend属性
        Component.onCompleted: {
            console.log("chartView:", chartView);
            chartView.updateAxesRange(30, 0, priObj.yMax, priObj.yMin);
        }

    }

    Timer{
        id:testDataTimer
        repeat: true
        interval: priObj.updateInterval
        triggeredOnStart: true
        onTriggered: {
            priObj.updateChartView();
        }

        onRunningChanged: {
            //清空
            priObj.reset()


        }
    }
}


