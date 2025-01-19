#include "Spdlogmanager.h"
#include <cstdio>
#include <chrono>
#include <QDebug>

//#include "spdlog/pattern_formatter-inl.h"

//#include "spdlog/cfg/env.h"   // support for loading levels from the environment variable
//#include "spdlog/fmt/ostr.h"  // support for user defined types
//2.文件sink
#include "spdlog/sinks/basic_file_sink.h"
//3 循环文本日志
#include "spdlog/sinks/rotating_file_sink.h"

#include "spdlog/logger.h"
#include <QApplication>
#include <QDate>

std::shared_ptr<spdlog::logger> m_pFileLogger;

SpdLogManager::SpdLogManager(QObject *parent)
    : QObject{parent}
{
    // m_pMsgHandler = std::bind(&SpdLogManager::customMsgHandler, this
    //                           , std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    qInstallMessageHandler(&SpdLogManager::customMsgHandler);

    spdlog::set_level(spdlog::level::debug);//低于该等级的日志不输出
    //设置日志文本格式
    //QString msgFmt = "[%Y-%m-%d %H:%M:%S.%e] [%l] [%t] %v";
    QString msgFmt = "[%Y-%m-%d %H:%M:%S.%e] [%n] [%l] [%s:%#] %v";
    msgFmt = "[%Y-%m-%d %H:%M:%S.%e] [%t] [%l] %v %s %#";
    spdlog::set_pattern(msgFmt.toStdString());


    //
    QString strLogFileName = QApplication::applicationName();
    strLogFileName+="_"+QDate::currentDate().toString("yyyyMMdd");
    strLogFileName += ".log";
    strLogFileName.insert(0, "log/");


    //切换自定义logger:
    //1.创建单线程、单文本日志文件
    m_pFileLogger = spdlog::basic_logger_st("fileLogger", strLogFileName.toStdString());
    m_pFileLogger.get()->flush_on(spdlog::level::trace);
    m_pFileLogger.get()->set_level(spdlog::level::debug);
    m_pFileLogger.get()->set_pattern(msgFmt.toStdString());
    m_pFileLogger.get()->info(strLogFileName.toStdString());
    //2.创建单线程、循环文本日志文件
    //auto max_size = 1048576 * 5;
    //auto max_files = 3;
    //m_pFileLogger = spdlog::rotating_logger_st("rotateFileLogger", strLogFileName.toStdString()
    //                                           , max_size, max_files);
    //m_pFileLogger.get()->flush_on(spdlog::level::trace);
    //m_pFileLogger.get()->set_level(spdlog::level::debug);
    //m_pFileLogger.get()->set_pattern(msgFmt.toStdString());
    //m_pFileLogger.get()->info(strLogFileName.toStdString());

}

void SpdLogManager::initialize()
{
    qDebug()<<"debug log"<<1;
    qInfo()<<"info log"<<1;
    qCritical()<<"critical log"<<1;
    SPDLOG_INFO("====zhltest===");
}

void SpdLogManager::customMsgHandler(QtMsgType msgType, const QMessageLogContext & context, const QString & msg)
{
    switch (msgType) {
    case QtDebugMsg:
        spdlog::debug(msg.toStdString().c_str());
        //切换自定义logger
        ///auto fileLogger = spdlog::basic_logger_st("fileLogger", strLogFileName.toStdString());
        //fileLogger.set_level(spdlog::level::debug);//低于该等级的日志不输出
        //SPDLOG_LOGGER_DEBUG(m_pFileLogger.get(), strLogFileName.toStdString());
                m_pFileLogger.get()->debug(msg.toStdString());
        break;
    case QtWarningMsg:
        spdlog::warn(msg.toStdString().c_str());
        //切换自定义logger
        //auto fileLogger = spdlog::basic_logger_st("fileLogger", strLogFileName.toStdString());
        //fileLogger.set_level(spdlog::level::debug);//低于该等级的日志不输出
        //SPDLOG_LOGGER_WARN(m_pFileLogger.get(), strLogFileName.toStdString());
                m_pFileLogger.get()->warn(msg.toStdString());
        break;
    case QtInfoMsg:
        spdlog::info(msg.toStdString().c_str());
        //切换自定义logger
        //auto fileLogger = spdlog::basic_logger_st("fileLogger", strLogFileName.toStdString());
        //fileLogger.set_level(spdlog::level::debug);//低于该等级的日志不输出
        m_pFileLogger.get()->info(msg.toStdString());
        break;
    case QtCriticalMsg:
        spdlog::critical(msg.toStdString().c_str());
        //切换自定义logger
        //auto fileLogger = spdlog::basic_logger_st("fileLogger", strLogFileName.toStdString());
        //fileLogger.set_level(spdlog::level::debug);//低于该等级的日志不输出
        //SPDLOG_LOGGER_CRITICAL(m_pFileLogger.get(), strLogFileName.toStdString());
        break;
    default:
        break;
    }
}
