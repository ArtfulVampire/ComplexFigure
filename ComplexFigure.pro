QT += core gui widgets


TARGET = ComplexFigure
TEMPLATE = app
CONFIG += console
QMAKE_CXXFLAGS += -std=c++1y #for C++14 standard


SOURCES += main.cpp \
    picture.cpp

HEADERS += \
    picture.h
