#ifndef SIMULATINGGUIEVENTSTEST_H
#define SIMULATINGGUIEVENTSTEST_H
#include <QObject>

class SimulatingGUIEventsTest : public QObject
{
    Q_OBJECT
public:
    SimulatingGUIEventsTest(QObject* parent = nullptr);

private slots:
    void testKeyClicks();
    void testKeyClicks_data();
};

#endif // SIMULATINGGUIEVENTSTEST_H
