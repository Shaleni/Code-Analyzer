TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += main.cpp \
    dsstring.cpp

HEADERS += \
    vector.h \
    dsstring.h \
    codeinmain.h \
    comments.h \
    metrics.h \
    loc.h \
    nesting.h \
    variables.h

SOURCES += main.cpp \
    codeinmain.cpp \
    comments.cpp \
    variables.cpp \
    nesting.cpp \
    loc.cpp


