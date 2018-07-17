#-------------------------------------------------
#
# Project created by QtCreator 2018-07-02T01:18:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MEMS-analyser
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

RESOURCES = resources.qrc

DESTDIR = $$PWD

OBJECTS_DIR = $$PWD/temp/.obj
MOC_DIR = $$PWD/temp/.moc
RCC_DIR = $$PWD/temp/.rcc
UI_DIR = $$PWD/temp/.ui

CONFIG += static
