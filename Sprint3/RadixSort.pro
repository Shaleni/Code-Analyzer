QT += core
QT -= gui

TARGET = RadixSort
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += DSString.h \
    vector.h \
    queue.h \
    linkedlist.h

SOURCES += main.cpp \
    dsstring.cpp

