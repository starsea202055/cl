#-------------------------------------------------
#
# Project created by QtCreator 2018-05-30T23:25:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpg_6
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mw.cpp \
    icon.cpp \
    gameworld.cpp \
    player.cpp \
    rpgobj.cpp

HEADERS  += mainwindow.h \
    mw.h \
    icon.h \
    gameworld.h \
    player.h \
    rpgobj.h

FORMS    += mainwindow.ui \
    mw.ui

RESOURCES += \
    images.qrc
