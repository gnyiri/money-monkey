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
    src/util/application_manager.cxx \
    src/model/accounttypemodel.cxx \
    src/model/accountmodel.cxx \
    src/ui/mainwindow.cxx \
    src/ui/centralwidget.cxx \
    src/ui/accounttypewidget.cxx \
    src/ui/accountwidget.cxx \
    src/main.cxx \
    src/ui/accountdialog.cxx \
    src/ui/accountdelegate.cxx \
    src/model/expensetypemodel.cxx \
    src/ui/expensetypewidget.cxx \
    src/ui/expensetypedialog.cxx

HEADERS  +=\
    src/util/application_manager.hxx \
    src/model/accounttypemodel.hxx \
    src/model/accountmodel.hxx \
    src/ui/accountwidget.hxx \
    src/ui/accounttypewidget.hxx \
    src/ui/mainwindow.hxx \
    src/ui/centralwidget.hxx \
    src/ui/accountdialog.hxx \
    src/ui/accountdelegate.hxx \
    src/model/expensetypemodel.hxx \
    src/ui/expensetypewidget.hxx \
    src/ui/expensetypedialog.hxx

RESOURCES += \
    res/application.qrc
