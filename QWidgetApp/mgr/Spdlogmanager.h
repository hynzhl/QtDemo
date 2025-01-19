#ifndef SPDLOGMANAGER_H
#define SPDLOGMANAGER_H

#include <QObject>
#include <memory>
#include "spdlog/spdlog.h"
class logger;

class SpdLogManager : public QObject
{
    Q_OBJECT
public:
    explicit SpdLogManager(QObject *parent = nullptr);
    void initialize();
protected:
    static void customMsgHandler(QtMsgType, const QMessageLogContext &, const QString &);
signals:


private:
    QtMessageHandler m_pMsgHandler;
    //static QString strLogFileName;
    //static std::shared_ptr<logger> m_pFileLogger;
};

#define XYLOG_LOGGER_INFO(logger, ...) \
        SPDLOG_LOGGER_INFO(SpdLogManager::defaultLogger(), __VA_ARGS__)

#define XYLOG_INFO(...) XYLOG_LOGGER_INFO(spdlog::default_logger_raw(), __VA_ARGS__)


#endif // SPDLOGMANAGER_H
