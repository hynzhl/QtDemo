#include "SimulatingGUIEventsTest.h"
#include <QTest>
#include <QLineEdit>
SimulatingGUIEventsTest::SimulatingGUIEventsTest(QObject *parent)
{

}

void SimulatingGUIEventsTest::testKeyClicks()
{
    QFETCH(QString, inputText);
    QLineEdit  edit;
    QTest::keyClicks(&edit, inputText);
    QCOMPARE(edit.text(), inputText);
}

void SimulatingGUIEventsTest::testKeyClicks_data()
{
    QTest::addColumn<QString>("inputText");

    QTest::newRow("case1")<<"zhanglei";
    QTest::newRow("case2")<<"zhangyuan";
}
