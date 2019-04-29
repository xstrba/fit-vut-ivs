include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt
DESTDIR = ../..
TARGET = runTests

INCLUDEPATH += ../ \
    ../../rebuscalc/

VPATH = ../../rebuscalc/ \
        ../

SOURCES +=  tests.cpp\
    math_lib.cpp \
    math_lib_tests.cpp

QMAKE_CLEAN += *.o
QMAKE_POST_LINK = make clean

