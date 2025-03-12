#ifndef REPLAYINGGUIEVENTSTEST_H
#define REPLAYINGGUIEVENTSTEST_H

#include <QObject>

class ReplayingGUIEventsTest : public QObject
{
    Q_OBJECT
public:
    explicit ReplayingGUIEventsTest(QObject *parent = nullptr);

private slots:
    void testGui_data();
    void testGui();
};

#endif // REPLAYINGGUIEVENTSTEST_H
