QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = apptcpip
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    appwindow.cpp \
    tcpclient.cpp

HEADERS += \
    mainwindow.h \
    appwindow.h \
    tcpclient.h

RESOURCES += \
    resources.qrc
