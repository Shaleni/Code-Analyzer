INCLUDEPATH += /boost/bin
LIBS += -L/home/ds/Code-Analyzer/boost_1_62_0/stage/lib



TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += main.cpp \
    dsstring.cpp

HEADERS += \
    vector.h \
    dsstring.h

