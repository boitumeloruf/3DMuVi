# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = dumFusion
DESTDIR = ../../../Win32/Debug
QT += core widgets gui
CONFIG += debug
DEFINES += QT_DLL QT_WIDGETS_LIB DUMFUSION_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ./algorithm.h \
    ./plugin.h \
    ./plugin_config.h
SOURCES += ./MyAlgorithm.cpp \
    ./algorithm.cpp \
    ./plugin.cpp
