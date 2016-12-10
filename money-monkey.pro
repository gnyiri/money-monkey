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
    src/model/accounttypemodel.cxx \
    src/ui/accounttypewidget.cxx \
    src/model/accountmodel.cxx

HEADERS  +=\
    include/mainwindow.hxx \
    include/centralwidget.hxx \
    include/application_manager.hxx \
    include/accounttypemodel.hxx \
    include/accounttypwidget.hxx \
    src/model/accountmodel.hxx

RESOURCES += \
    res/application.qrc
