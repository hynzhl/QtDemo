#include "DataDrivenTest.h"
#include <QtTest>
DataDrivenTest::DataDrivenTest(QObject *parent)
{

}

void DataDrivenTest::textCompare()
{
    //第六步：动态取数据
    QFETCH(QString, srcText);
    QFETCH(QString, destText);
    QCOMPARE(srcText, destText);
}

void DataDrivenTest::textCompare_data()
{
    //第四步：声明数据类型以及名称
    QTest::addColumn<QString>("srcText");
    QTest::addColumn<QString>("destText");
    //第五步添加数据
    QTest::newRow("No.1")<<"hello" << "HELLO";
    QTest::newRow("No.2")<< "Hello" << "HELLO";
    QTest::newRow("No.3")<< "HELLO" << "HELLO";

}
