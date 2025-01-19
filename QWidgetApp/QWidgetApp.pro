QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += \
    #SPDLOG_USE_STD_FORMAT
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += \
        $${PWD}/../3rdParty/spdlog/x64/include \
        #$${PWD}/../3rdParty/fmt/x64/include \


LIBS  += \
        -L$${PWD}/../3rdParty/spdlog/x64/lib\
        #-L$${PWD}/../3rdParty/fmt/x64/lib\
        -lspdlog    \
        #-lfmt

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mgr/Spdlogmanager.cpp

HEADERS += \
    mainwindow.h \
    mgr/Spdlogmanager.h



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DESTDIR = $${PWD}/../bin
