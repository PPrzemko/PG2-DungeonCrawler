TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle



QT += core gui
QT += testlib
    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
        abstractui.cpp \
        active.cpp \
        character.cpp \
        controller.cpp \
        directionbutton.cpp \
        door.cpp \
        dungeoncrawler.cpp \
        floor.cpp \
        graphicalui.cpp \
        guardcontroller.cpp \
        level.cpp \
        main.cpp \
        mainwindow.cpp \
        passive.cpp \
        pit.cpp \
        portal.cpp \
        ramp.cpp \
        startscreen.cpp \
        stationarycontroller.cpp \
        switch.cpp \
        terminalui.cpp \
        tile.cpp \
        wall.cpp

HEADERS += \
    abstractui.h \
    active.h \
    character.h \
    controller.h \
    directionbutton.h \
    door.h \
    dungeoncrawler.h \
    floor.h \
    graphicalui.h \
    guardcontroller.h \
    level.h \
    main.h \
    mainwindow.h \
    passive.h \
    pit.h \
    portal.h \
    ramp.h \
    startscreen.h \
    stationarycontroller.h \
    switch.h \
    terminalui.h \
    tile.h \
    wall.h

FORMS += \
    mainwindow.ui \
    startscreen.ui

DISTFILES += \
    texture/arrows/arrow_down.png \
    texture/arrows/arrow_down_left.png \
    texture/arrows/arrow_down_right.png \
    texture/arrows/arrow_left.png \
    texture/arrows/arrow_right.png \
    texture/arrows/arrow_skip.png \
    texture/arrows/arrow_up.png \
    texture/arrows/arrow_up_left.png \
    texture/arrows/arrow_up_right.png \
    texture/bloody_frame.png \
    texture/char/back/char_back_1.png \
    texture/char/back/char_back_2.png \
    texture/char/back/char_back_3.png \
    texture/char/char_complete.png \
    texture/char/front/char_front_1.png \
    texture/char/front/char_front_2.png \
    texture/char/front/char_front_3.png \
    texture/char/left/char_left_1.png \
    texture/char/left/char_left_2.png \
    texture/char/left/char_left_3.png \
    texture/char/right/char_right_1.png \
    texture/char/right/char_right_2.png \
    texture/char/right/char_right_3.png \
    texture/chest.png \
    texture/doors/door1.png \
    texture/doors/door2.png \
    texture/floor/floor1.png \
    texture/floor/floor2.png \
    texture/floor/floor3.png \
    texture/floor/floor4.png \
    texture/floor/floor5.png \
    texture/levelchanger.png \
    texture/new_game_button.png \
    texture/pit.png \
    texture/portal/portal1.png \
    texture/portal/portal2.png \
    texture/portal/portal3.png \
    texture/ramp.png \
    texture/startscreen.png \
    texture/switch.png \
    texture/wall/wall1.png \
    texture/zombie/zombie_left.png \
    texture/zombie/zombie_right.png

RESOURCES += \
    texture.qrc

