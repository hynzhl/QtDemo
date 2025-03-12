#include "Dialog.h"
#include "TestQString.h"
#include "DataDrivenTest.h"
#include "SimulatingGUIEventsTest.h"
#include "ReplayingGUIEventsTest.h"
#include <QApplication>
#include <QTest>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //app.setAttribute(Qt::AA_Use96Dpi, true);
    //QTEST_DISABLE_KEYPAD_NAVIGATION;
    //QTEST_SET_MAIN_SOURCE_PATH;
    TestQString tc;
    int iRet = QTest::qExec(&tc, argc, argv);
    //
    DataDrivenTest ddt;
    iRet = QTest::qExec(&ddt, argc, argv);
    //
    SimulatingGUIEventsTest sget;
    iRet = QTest::qExec(&sget, argc, argv);
    //
    ReplayingGUIEventsTest rget;
    iRet = QTest::qExec(&rget, argc, argv);
    return iRet;
}
