TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    vector.h \
    dsstring.h \
    codeanalyzer.h

SOURCES += main.cpp \
    metrics.cpp \
    codeinmain.cpp \
    dsstring.cpp \
    comments.cpp \
    variables.cpp \
    nesting.cpp \
    loc.cpp \
    codeanalyzer.cpp

