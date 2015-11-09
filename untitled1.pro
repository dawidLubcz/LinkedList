TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cmylist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    cmylist.h

