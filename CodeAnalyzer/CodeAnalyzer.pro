TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    vector.h \
    dsstring.h \
    codeanalyzer.h \
    codeinmain.h \
    comments.h \
    metrics.h \
    loc.h \
    nesting.h \
    variables.h \
    fileinfo.h

SOURCES += main.cpp \
    codeinmain.cpp \
    dsstring.cpp \
    comments.cpp \
    variables.cpp \
    nesting.cpp \
    loc.cpp \
    codeanalyzer.cpp \
    fileinfo.cpp

