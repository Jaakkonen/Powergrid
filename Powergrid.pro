#-------------------------------------------------
#
# Project created by QtCreator 2017-11-24T20:48:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Powergrid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    appliance.cpp \
    house.cpp \
    cluster.cpp

HEADERS  += mainwindow.h \
    appliance.h \
    house.h \
    cluster.h

FORMS    += mainwindow.ui
