TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abstractui.cpp \
        active.cpp \
        character.cpp \
        dungeoncrawler.cpp \
        floor.cpp \
        level.cpp \
        main.cpp \
        passive.cpp \
        portal.cpp \
        terminalui.cpp \
        tile.cpp \
        wall.cpp

HEADERS += \
    abstractui.h \
    active.h \
    character.h \
    dungeoncrawler.h \
    floor.h \
    level.h \
    passive.h \
    portal.h \
    terminalui.h \
    tile.h \
    wall.h
