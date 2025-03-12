#ifndef TESTQSTRING_H
#define TESTQSTRING_H

#include <QObject>

/*固定数据测试用例*/

class TestQString : public QObject
{
    Q_OBJECT
public:
    TestQString(QObject* parent = nullptr);
private slots:
    //
    void initTestCase();
    //
    void initTestCase_data();
    //
    void cleanupTestCase();
    //
    void init();
    //
    void cleanup();

    void case1_toUpper();
    //
    void case2_toUpper();
};

#endif // TESTQSTRING_H
