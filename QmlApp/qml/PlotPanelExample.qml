import QtQuick 2.15
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
        //catlog  类别
        property int val1:0;
        property int val2:0;
        property int val3:0;
        property int val4:0;
        property int val5:0;
        function reset(){
            curTimePoint = 0;
            chartDataArray.splice(0, chartDataArray.length);
        }

        function updateCatlogVal(){
            val1 = valueAxisX.min + 0 * timeInterval;
            val2 = valueAxisX.min + 1*timeInterval;
            val3 = valueAxisX.min + 2*timeInterval;
            val4 = valueAxisX.min + 3*timeInterval;
            val5 = valueAxisX.min + 4*timeInterval;
        }

        function updateChartView(){
            if(!priObj.isRunning){
                return;
            }

            priObj.curTimePoint += priObj.updateInterval/1000.0;//转换成秒

           valueAxisX.min = valueAxisX.max - priObj.timeRange
           valueAxisX.max = priObj.curTimePoint <= priObj.timeRange
                            ? priObj.timeRange : priObj.curTimePoint
            //
            //文本坐标值
            //catlogAxisX.categoriesLabels.clear();
            // for(var i=0;i<timeRange/timeInterval; i++){
            //     catlogAxisX.append(String("%1min").arg(valueAxisX.min + i*timeInterval)
            //                        , valueAxisX.min + i*timeInterval);
            // }
            //updateCatlogVal();

            var pt = Qt.point(priObj.curTimePoint, getRandomNum());
            //console.log("x:",pt.x, "; y:", pt.y)
            line1.append(pt.x, pt.y);
            //line2.append(pt.x, pt.y);
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


    ChartView {
        id:chartView
        anchors.top: itemTop.bottom
        anchors.bottom: parent.bottom
        title: qsTr("①侧温度趋势")
        titleFont.pixelSize: 30
        titleFont.bold: true
        titleColor: "#ff0000"//Theme.darker(1.2)
        width: parent.width
        //height:parent.height
        antialiasing: true
        backgroundColor: Qt.rgba(255,0,0,0.1)
        backgroundRoundness: 24
        dropShadowEnabled:true
        //legend属性
        legend.visible: true
        legend.alignment: Qt.AlignLeft
        legend.backgroundVisible: true
        legend.borderColor: "red"
        legend.labelColor: "blue"
        legend.font.pixelSize: 28
        legend.markerShape: Legend.MarkerShapeCircle
        legend.showToolTips: true
        plotAreaColor: "yellow"
        margins.left: 100
        margins.right: 100
        Component.onCompleted: {
            console.log("chartView:", chartView);
            console.log("chartView series cnt:", chartView.count);
            console.log("chartView lengend:", chartView.legend);
            console.log("chartView rect:", chartView.plotArea
                        , "margin:",chartView.margins.left, chartView.margins.right
                        , chartView.margins.top, chartView.margins.bottom);
        }



        //X轴-动态展示30秒数据
        ValueAxis {
            id: valueAxisX
            tickCount: priObj.timeRange/priObj.timeInterval  //坐标轴上的的刻度个数。所以间隔 = 60 / 30 = 2
            labelFormat:"%.0f"  //0 - 控制小数点后有几位小数
            min:0
            max:priObj.timeRange
            gridVisible: false
            tickType:ValueAxis.TicksFixed
            Component.onCompleted: {
                console.log(valueAxisX)
            }

            //tickType:ValueAxis.TicksDynamic
            //tickInterval:priObj.timeInterval
            //tickAnchor: max/2
        }
        // CategoryAxis{
        //     id: catlogAxisX
        //     CategoryRange {
        //         label: String("%1 min").arg(endValue)
        //         endValue: priObj.val1
        //     }
        //     CategoryRange {
        //         label:String("%1 min").arg(endValue)
        //         endValue:  priObj.val2
        //     }
        //     CategoryRange {
        //         label: String("%1 min").arg(endValue)
        //         endValue: priObj.val3
        //     }
        //     CategoryRange {
        //         label: String("%1 min").arg(endValue)
        //         endValue:  priObj.val4
        //     }
        //     CategoryRange {
        //         label: String("%1 min").arg(endValue)
        //         endValue:  priObj.val5
        //     }
        // }

        //Y轴
        ValueAxis {
            id: valueAxisY
            min: priObj.yMin
            max: priObj.yMax
            tickCount: 27  //坐标轴上的的刻度个数
            labelFormat: "%.1f"//1 - 控制小数点后有几位小数
        }
        //LineSeries是折线，SplineSeries是曲线。子项都是XYPoint
        SplineSeries {
            id:line1
            name: "1"  //线条的名称
            axisX: valueAxisX  //指定X轴
            axisY: valueAxisY  //指定Y轴
            color: Qt.darker("#BB4444",1.2) //线条颜色，默认每条线的颜色不同
            width: 2//线的宽度，但修改线宽后，需要重新设置color，否则修改过width的线条都是黑色
            //pointLabelsVisible:true
            Component.onCompleted: {
                console.log(line1)
            }
        }
        SplineSeries {
            id:line2
            name: "2"
            axisX: valueAxisX
            axisY: valueAxisY
            color: Qt.darker("#B38A4D",1.2)
            width: 2
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

