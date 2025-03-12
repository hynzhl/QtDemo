#include "ReplayingGUIEventsTest.h"
#include <QLineEdit>
#include <QTest>

ReplayingGUIEventsTest::ReplayingGUIEventsTest(QObject *parent)
    : QObject{parent}
{}

void ReplayingGUIEventsTest::testGui_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there and back again") << list2 << "";
}

void ReplayingGUIEventsTest::testGui()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit lineEdit;

    events.simulate(&lineEdit);

    QCOMPARE(lineEdit.text(), expected);
}
