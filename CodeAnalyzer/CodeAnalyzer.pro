INCLUDEPATH += /boost/bin
LIBS += -L/home/ds/Code-Analyzer/boost_1_62_0/stage/lib



TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

<<<<<<< HEAD


SOURCES += main.cpp \
    dsstring.cpp

HEADERS += \
    vector.h \
    dsstring.h
=======
SOURCES += main.cpp \
    metrics.cpp \
    codeinmain.cpp \
    comments.cpp \
    variables.cpp \
    nesting.cpp \
    loc.cpp
>>>>>>> quality

