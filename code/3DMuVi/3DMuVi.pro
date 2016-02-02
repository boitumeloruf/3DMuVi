# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = 3DMuVi
DESTDIR = ../Win32/Debug
QT += core opengl widgets gui
CONFIG += qtestlib debug c++11
DEFINES += QT_DLL QT_TESTLIB_LIB QT_OPENGL_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
LIBS += -lopengl32 \
    -lglu32
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
win32:RC_FILE = 3DMuVi.rc
HEADERS += ./workflow/workflow/acontextdatastore.h \
    ./workflow/workflow/aworkflow.h \
    ./workflow/workflow/cworkflowmanager.h \
    ./workflow/workflow/idatapacket.h \
    ./workflow/workflow/idataview.h \
    ./workflow/workflow/tdatapacket.h \
    ./workflow/plugin/iplugin.h \
    ./workflow/plugin/cpluginmanager.h \
    ./workflow/plugin/ialgorithm.h \
    ./gui/3dView/C3dView.h \
    ./gui/AlgorithmSettings/CAlgorithmSettingsSaveLoadWidget.h \
    ./gui/AlgorithmSettings/CAlgorithmSettingsView.h \
    ./gui/ImageViews/CDepthMapView.h \
    ./gui/ImageViews/CFeatureView.h \
    ./gui/ImageViews/CImageView.h \
    ./gui/ImageViews/CInputImageView.h \
    ./gui/CAlgorithmSelector.h \
    ./gui/CDatasetSelector.h \
    ./gui/CDataViewTabContainer.h \
    ./gui/CImagePreviewItem.h \
    ./gui/CImagePreviewWidget.h \
    ./gui/CLogWidget.h \
    ./gui/CMainWindow.h \
    ./gui/CSettingsDialog.h \
    ./gui/CStepComboBox.h \
    ./gui/IGuiDataView.h \
    ./io/CImageIo.h \
    ./io/CTextIo.h \
    ./io/CInputDataSet.h\
    ./settings/CGlobalSettingController.h\
    ./settings/CAlgorithmSettingController.h\
    ./settings/CAlgorithmSettingsModel.h\
    ./settings/CQJsonModel.h\
    ./settings/CQJsonItem.h
SOURCES += ./main.cpp \
    ./workflow/workflow/acontextdatastore.cpp \
    ./workflow/workflow/aworkflow.cpp \
    ./workflow/workflow/cworkflowmanager.cpp \
    ./workflow/workflow/idatapacket.cpp \
    ./workflow/workflow/idataview.cpp \
    ./workflow/workflow/tdatapacket.cpp \
    ./gui/3dView/C3dView.cpp \
    ./workflow/plugin/cpluginmanager.cpp \
    ./gui/AlgorithmSettings/CAlgorithmSettingsSaveLoadWidget.cpp \
    ./gui/AlgorithmSettings/CAlgorithmSettingsView.cpp \
    ./gui/ImageViews/CDepthMapView.cpp \
    ./gui/ImageViews/CFeatureView.cpp \
    ./gui/ImageViews/CImageView.cpp \
    ./gui/ImageViews/CInputImageView.cpp \
    ./gui/CAlgorithmSelector.cpp \
    ./gui/CDatasetSelector.cpp \
    ./gui/CDataViewTabContainer.cpp \
    ./gui/CImagePreviewItem.cpp \
    ./gui/CImagePreviewWidget.cpp \
    ./gui/CLogWidget.cpp \
    ./gui/CMainWindow.cpp \
    ./gui/CSettingsDialog.cpp \
    ./gui/CStepComboBox.cpp \
    ./io/CImageIo.cpp \
    ./io/CTextIo.cpp \
    ./io/CInputDataSet.cpp\
    ./settings/CGlobalSettingController.cpp\
    ./settings/CAlgorithmSettingController.cpp\
    ./settings/CAlgorithmSettingsModel.cpp\
    ./settings/CQJsonModel.cpp\
    ./settings/CQJsonItem.cpp
FORMS += ./gui/forms/CMainWindow.ui \
    ./gui/forms/CSettingsDialog.ui \

