# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = 3DMuVi
DESTDIR = ../Win32/Debug
QT += core opengl widgets gui
CONFIG += debug c++11
DEFINES += QT_DLL QT_OPENGL_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug

PCL{
  INCLUDEPATH += ../pcl/common/include/ ../pcl-build/include/ ../pcl/visualization/include/
  INCLUDEPATH += ../pcl/geometry/include/
  INCLUDEPATH += /usr/include/eigen3/
  INCLUDEPATH += ../VTK-7.0.0/Common/Core/ ../VTK-build/Common/Core/
  INCLUDEPATH += ../VTK-7.0.0/Common/Math/ ../VTK-build/Common/Math/
  INCLUDEPATH += ../VTK-7.0.0/Rendering/LOD/ ../VTK-build/Rendering/LOD/
  INCLUDEPATH += ../VTK-7.0.0/Filters/Modeling/ ../VTK-build/Filters/Modeling/
  INCLUDEPATH += ../VTK-7.0.0/Filters/General/ ../VTK-build/Filters/General/
  INCLUDEPATH += ../VTK-7.0.0/Filters/Core/ ../VTK-build/Filters/Core/
  INCLUDEPATH += ../VTK-7.0.0/Filters/Sources/ ../VTK-build/Filters/Sources/
  INCLUDEPATH += ../VTK-7.0.0/Rendering/Core/ ../VTK-build/Rendering/Core/
  INCLUDEPATH += ../VTK-7.0.0/Interaction/Style/ ../VTK-build/Interaction/Style/
  INCLUDEPATH += ../VTK-7.0.0/Common/DataModel/ ../VTK-build/Common/DataModel/
  INCLUDEPATH += ../VTK-7.0.0/Rendering/Annotation/ ../VTK-build/Rendering/Annotation/
  INCLUDEPATH += ../VTK-7.0.0/Rendering/FreeType/ ../VTK-build/Rendering/FreeType/
  INCLUDEPATH += ../VTK-7.0.0/Common/ExecutionModel/ ../VTK-build/Common/ExecutionModel/
  INCLUDEPATH += ../VTK-7.0.0/Filters/Geometry/ ../VTK-build/Filters/Geometry/
  INCLUDEPATH += ../VTK-7.0.0/GUISupport/Qt/ ../VTK-build/GUISupport/Qt/
  INCLUDEPATH += ../VTK-7.0.0/Rendering/OpenGL/ ../VTK-build/Rendering/OpenGL/

  LIBS += -L"$$PWD/../VTK-build/lib/" -L"$$PWD/../pcl-build/lib/"


  LIBS += -lboost_system -lvtkGUISupportQt-7.0 -lvtkCommonCore-7.0 -lvtkRenderingCore-7.0
  LIBS += -lvtkCommonDataModel-7.0 -lvtkCommonMath-7.0 -lpcl_common -lpcl_visualization
}

win32{
  LIBS += -lopengl32 \
          -lglu32
}
else
{
  LIBS += -lGL \
          -lGLU
}

DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
win32:RC_FILE = 3DMuVi.rc
HEADERS += ./workflow/workflow/ccontextdatastore.h \
    ./workflow/workflow/aworkflow.h \
    ./workflow/workflow/cworkflowmanager.h \
    ./workflow/workflow/idatapacket.h \
    ./workflow/workflow/idataview.h \
    ./workflow/plugin/iplugin.h \
    ./workflow/plugin/cpluginmanager.h \
    ./workflow/plugin/ialgorithm.h \
    ./workflow/workflow/fourphase/cfourphaseworkflow.h\
    ./workflow/workflow/datapackets/CDataFeature.h \
    ./workflow/workflow/datapackets/CDataPose.h \
    ./workflow/workflow/datapackets/CDataDepth.h \
    ./workflow/workflow/datapackets/SPose.h \
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
    ./io/CInputDataSet.h \
    ./io/CResultContext.h \
    ./io/AStreamProvider.h \
    ./io/CSFStreamProvider.h \
    ./io/CMFStreamProvider.h \
    ./logger/controll/CAlgoMessage.h \
    ./logger/controll/CLogController.h \
    ./logger/controll/CLogHistory.h \
    ./logger/qslogging/QsLog.h \
    ./logger/qslogging/QsLogDest.h \
    ./logger/qslogging/QsLogDestConsole.h \
    ./logger/qslogging/QsLogDestFile.h \
    ./logger/qslogging/QsLogDestFunctor.h \
    ./logger/qslogging/QsLogLevel.h\
    ./settings/CGlobalSettingController.h\
    ./settings/CAlgorithmSettingController.h\
    ./settings/CAlgorithmSettingsModel.h\
    ./settings/CQJsonModel.h\
    ./settings/CQJsonItem.h

SOURCES += ./main.cpp \
    ./workflow/workflow/ccontextdatastore.cpp \
    ./workflow/workflow/cworkflowmanager.cpp \
    ./workflow/workflow/idatapacket.cpp \
    ./workflow/workflow/idataview.cpp \
    ./workflow/workflow/aworkflow.cpp \
    ./workflow/workflow/fourphase/cfourphaseworkflow.cpp \
    ./workflow/workflow/datapackets/CDataFeature.cpp \
    ./workflow/workflow/datapackets/CDataPose.cpp \
    ./workflow/workflow/datapackets/CDataDepth.cpp \
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
    ./io/CInputDataSet.cpp \
    ./io/CResultContext.cpp \
    ./io/AStreamProvider.cpp \
    ./io/CSFStreamProvider.cpp \
    ./io/CMFStreamProvider.cpp \
    ./logger/controll/CAlgoMessage.cpp \
    ./logger/controll/CLogController.cpp \
    ./logger/controll/CLogHistory.cpp \
    ./logger/qslogging/QsLog.cpp \
    ./logger/qslogging/QsLogDest.cpp \
    ./logger/qslogging/QsLogDestConsole.cpp \
    ./logger/qslogging/QsLogDestFile.cpp \
    ./logger/qslogging/QsLogDestFunctor.cpp\
    ./settings/CGlobalSettingController.cpp\
    ./settings/CAlgorithmSettingController.cpp\
    ./settings/CAlgorithmSettingsModel.cpp\
    ./settings/CQJsonModel.cpp\
    ./settings/CQJsonItem.cpp

PCL{
  HEADERS += ./gui/3dView/C3dView.h \
      ./gui/3dView/CPclView.h \
      ./workflow/workflow/datapackets/CDataFusion.h

  SOURCES += ./gui/3dView/C3dView.cpp \
    ./gui/3dView/CPclView.cpp \
    ./workflow/workflow/datapackets/CDataFusion.cpp
}

FORMS += ./gui/forms/CMainWindow.ui \
    ./gui/forms/CSettingsDialog.ui \
    ./gui/forms/CAlgorithmSettingsSaveLoad.ui \

DISTFILES += \
    gui/forms/CAlgorithmSettingsSaveLoad.ui.qml \
    gui/forms/CAlgorithmSettingsSaveLoad.qml

