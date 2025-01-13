#include "mainwindow.h"

#include <QJsonDocument>
#include <QJsonObject>
#include "../QtPluginExample/pluginExampleImp.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    resize(800, 600);
    m_pCentralWidget = new QWidget(this);
    setCentralWidget(m_pCentralWidget);

    QPushButton* m_pBtnLoadPlugin = new QPushButton("加载插件", m_pCentralWidget);
    QPushButton* m_pBtnUnLoadPlugin = new QPushButton("卸载插件", m_pCentralWidget);

    QVBoxLayout* pFrameLayout = new QVBoxLayout(m_pCentralWidget);
    QHBoxLayout* pBtnGrpLayout = new QHBoxLayout();
    pBtnGrpLayout->addWidget(m_pBtnLoadPlugin);
    pBtnGrpLayout->addWidget(m_pBtnUnLoadPlugin);
    pBtnGrpLayout->addStretch();

    pFrameLayout->addLayout(pBtnGrpLayout);
    pFrameLayout->addStretch();
    connect(m_pBtnLoadPlugin, &QPushButton::clicked, this, &MainWindow::onLoadPluginBtnclicked);
    connect(m_pBtnUnLoadPlugin, &QPushButton::clicked, this, &MainWindow::onUnloadPluginBtnclicked);
}

MainWindow::~MainWindow()
{

}

void MainWindow::initialize()
{


}

void MainWindow::onLoadPluginBtnclicked()
{
    //加载插件
    m_pluginLoader.setFileName("QtPluginExample.dll");
    // 获取并打印插件的元数据
    QJsonObject metaData = m_pluginLoader.metaData();
    qDebug() << "Plugin metadata:" << QJsonDocument(metaData).toJson(QJsonDocument::Compact);
    if(m_pluginLoader.load())
    {
        PluginExampleImp* pluginInst = static_cast<PluginExampleImp*>(m_pluginLoader.instance());
        if(pluginInst){
            qDebug()<<"load dll success!"<<m_pluginLoader.errorString();
            pluginInst->doTask();
        }
        else
        {
          qDebug()<<"pluginInst isn null"<<pluginInst;
        }
    }
    else
    {
        qDebug()<<"load dll failure!"<<m_pluginLoader.errorString();
    }
}


void MainWindow::onUnloadPluginBtnclicked()
{
    // 获取并打印插件的元数据
    if(m_pluginLoader.unload())
    {
        PluginExampleImp* pluginInst = static_cast<PluginExampleImp*>(m_pluginLoader.instance());
        qDebug()<<"after unload:pluginInst instance"<<pluginInst;
        QJsonObject metaData = m_pluginLoader.metaData();
        qDebug() << "Plugin metadata:" << QJsonDocument(metaData).toJson(QJsonDocument::Compact);
    }
    else
    {
        qDebug()<<"unload dll failure!"<<m_pluginLoader.errorString();
    }
}

