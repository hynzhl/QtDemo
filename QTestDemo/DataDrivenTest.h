#ifndef DATADRIVENTEST_H
#define DATADRIVENTEST_H

#include <QObject>

//Step1:  继承QObject
class DataDrivenTest : public QObject
{
    Q_OBJECT
public:
    DataDrivenTest(QObject* parent = nullptr);

    //第二步：所有的测试函数声明为私有槽函数
private slots:
    void textCompare();
    //第三步：所有的测试函数对应的数据源，以data作为后缀
    void textCompare_data();
};

#endif // DATADRIVENTEST_H
