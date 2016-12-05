LIBS += \
    -lboost_system\

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
    fileinfo.h \
    stack.hpp\
    linkedlist.hpp \
    classname.h \
    functionname.h

SOURCES += main.cpp \
    codeinmain.cpp \
    dsstring.cpp \
    comments.cpp \
    nesting.cpp \
    loc.cpp \
    codeanalyzer.cpp \
    fileinfo.cpp \
    classname.cpp \
    functionname.cpp

