#include "mainwindow.h"

#include <QApplication>
#include "QBreakpadHandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString dumpPath = QApplication::applicationDirPath() + "/dump";
    QBreakpadInstance.setDumpPath(dumpPath);
    MainWindow w;
    w.initialize();
    w.show();
    return a.exec();
}
