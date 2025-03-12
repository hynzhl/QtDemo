#include "TestQString.h"
#include <QDebug>
#include <QTest>
// QTEST_MAIN(TestQString)
// #include "testqstring.moc"

TestQString::TestQString(QObject *parent)
{

}

void TestQString::initTestCase_data()
{
    qDebug()<<"zhl-1"<<__FUNCTION__;
}

void TestQString::initTestCase()
{
    qDebug()<<"zhl-2"<<__FUNCTION__;
}


void TestQString::init()
{
    qDebug()<<"zhl-3"<<__FUNCTION__;
}

void TestQString::cleanup()
{
    qDebug()<<"zhl-4"<<__FUNCTION__;
}

void TestQString::case1_toUpper()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
    qDebug()<<"zhl"<<__FUNCTION__;
}

void TestQString::case2_toUpper()
{
    QString str = "Hello";
    QCOMPARE(str, "HelloW");
    qDebug()<<"zhl"<<__FUNCTION__;
}


void TestQString::cleanupTestCase()
{
    qDebug()<<"zhl-5"<<__FUNCTION__;
}



