#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPluginLoader>
#include <QWidget>
QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initialize();
private slots:
    //加载插件
    void onLoadPluginBtnclicked();
    //卸载插件
    void onUnloadPluginBtnclicked();

private:
    QWidget* m_pCentralWidget;
    QPluginLoader m_pluginLoader;
};
#endif // MAINWINDOW_H
