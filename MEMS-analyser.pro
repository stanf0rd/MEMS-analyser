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

SOURCES = $$files(*.cpp, true)
HEADERS = $$files(*.h, true)
FORMS = $$files(*.ui, true)

INCLUDEPATH += \
    GUI \
    elements \
    condermap \
    config \
    libs \

DESTDIR = $$PWD

unix:QMAKE_CXXFLAGS += -std=c++17
win32:QMAKE_CXXFLAGS += /std:c++17

unix:QMAKE_CXXFLAGS += \
    -g \
    -Wall \
    -Wextra \

OBJECTS_DIR = $$PWD/.temp/.obj
MOC_DIR = $$PWD/.temp/.moc
RCC_DIR = $$PWD/.temp/.rcc
UI_DIR = $$PWD/.temp/.ui

CONFIG += static
CONFIG += silent
