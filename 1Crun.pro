#-------------------------------------------------
#
# Project created by QtCreator 2015-09-01T20:12:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1Crun
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    core/file.cpp \
    core/core.cpp

HEADERS  += mainwindow.h \
    core/file.h \
    core/core.h

FORMS    += mainwindow.ui
