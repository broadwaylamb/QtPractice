#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T21:52:09
#
#-------------------------------------------------

QT       += widgets

TARGET = QLineNumberRuler
TEMPLATE = lib
CONFIG += staticlib

SOURCES += qlinenumberruler.cpp \
           qrulermarker.cpp \
           qcodeedit.cpp


HEADERS += qlinenumberruler.h \
           qrulermarker.h \
           qcodeedit.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
