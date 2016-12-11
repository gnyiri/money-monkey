#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T10:19:39
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = money-monkey
TEMPLATE = app

INCLUDEPATH +=\
    src\
    src/ui\
    src/util\
    src/model

SOURCES +=\
    src/main.cxx\
    src/ui/mainwindow.cxx \
    src/ui/centralwidget.cxx \
    src/util/application_manager.cxx \
    src/model/accounttypemodel.cxx \
    src/ui/accounttypewidget.cxx \
    src/model/accountmodel.cxx

HEADERS  +=\
    src/ui/mainwindow.hxx \
    src/ui/centralwidget.hxx \
    src/util/application_manager.hxx \
    src/model/accounttypemodel.hxx \
    src/ui/accounttypwidget.hxx \
    src/model/accountmodel.hxx \
    src/ui/accounttypedialog.hxx

RESOURCES += \
    res/application.qrc
