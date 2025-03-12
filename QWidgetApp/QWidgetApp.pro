QT       += core gui  network printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 force_debug_info

DEFINES += \
    #SPDLOG_USE_STD_FORMAT
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# QMAKE_CXXFLAGS_RELEASE = -Od -ZI -MD
# QMAKE_LFLAGS_RELEASE = /DEBUG
#QMAKE_CXXFLAGS_RELEASE_WITH_DEBUGINFO += -Od

INCLUDEPATH += \
        $${PWD}/../3rdParty/spdlog/x64/include \
        $${PWD}/../3rdParty/qBreakpad/include \
        #$${PWD}/../3rdParty/fmt/x64/include \


LIBS  += \
        -L$${PWD}/../3rdParty/spdlog/x64/lib\
        -L$${PWD}/../3rdParty/qBreakpad/lib/release_x64 \
        #-L$${PWD}/../3rdParty/fmt/x64/lib\
        -lspdlog    \
        -llibqBreakpad
        #-lfmt

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mgr/Spdlogmanager.cpp \
    plot/MyPlotArea.cpp \
    plot/QCustomPlot/qcustomplot.cpp \
    plot/TestPlotPanel.cpp

HEADERS += \
    mainwindow.h \
    mgr/Spdlogmanager.h \
    plot/MyPlotArea.h \
    plot/QCustomPlot/qcustomplot.h \
    plot/TestPlotPanel.h



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# QMAKE_CFLAGS += /utf-8
# QMAKE_CXXFLAGS += /utf-8
QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO


DESTDIR = $${PWD}/../bin
