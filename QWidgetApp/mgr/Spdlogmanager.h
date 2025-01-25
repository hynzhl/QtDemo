#ifndef SPDLOGMANAGER_H
#define SPDLOGMANAGER_H

#include <QObject>
#include <memory>

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



#endif // SPDLOGMANAGER_H
