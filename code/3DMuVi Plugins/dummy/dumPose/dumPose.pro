# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = dumPose
DESTDIR = ../../../Win32/Debug
QT += core opengl widgets gui
CONFIG += debug c++11
DEFINES += QT_DLL QT_OPENGL_LIB QT_WIDGETS_LIB DUMPOSE_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug \
    ../../../3DMuVi/
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ./algorithm.h \
    ./plugin.h \
    ./plugin_config.h
SOURCES += ./algorithm.cpp \
    ./MyAlgorithm.cpp \
    ./plugin.cpp
