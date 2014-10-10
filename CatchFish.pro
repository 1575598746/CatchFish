#-------------------------------------------------
#
# Project created by QtCreator 2013-03-15T11:12:38
#
#-------------------------------------------------

QT       += core gui

TARGET = CatchFish
TEMPLATE = app


SOURCES +=src/main_dialog.cpp \
    src/main.cpp \
    src/optiondialog.cpp \
    src/newgamedialog.cpp \
    src/topdialog.cpp \
    src/qmessage_dialog.cpp \
    src/del_ins_messagedialog.cpp

HEADERS  +=src/main_dialog.h \
    src/optiondialog.h \
    src/newgamedialog.h \
    src/topdialog.h \
    src/qmessage_dialog.h \
    src/del_ins_messagedialog.h

FORMS    += main_dialog.ui \
    optiondialog.ui \
    newgamedialog.ui \
    topdialog.ui \
    qmessage_dialog.ui \
    del_ins_messagedialog.ui

RESOURCES += \
    source.qrc
