#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T10:19:39
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = money-monkey
TEMPLATE = app

INCLUDEPATH = "include"

SOURCES +=\
    src/main.cxx\
    src/ui/mainwindow.cxx \
    src/ui/centralwidget.cxx \
    src/util/application_manager.cxx \
    src/model/accounttypemodel.cxx

HEADERS  +=\
    include/mainwindow.hxx \
    include/centralwidget.hxx \
    include/application_manager.hxx \
    include/accounttypemodel.hxx

RESOURCES += \
    res/application.qrc
