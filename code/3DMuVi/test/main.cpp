#include <QTest>

#include "gui/CTestCDatasetSelector.h"
#include "gui/CTestCLogWidget.h"
#include "gui/CTestCMainWindow.h"
#include "gui/CTestCSettingsDialog.h"

#include "io/CTestCImageIo.h"
#include "io/CTestCTextIo.h"
#include "io/CTestCInputDataSet.h"
#include "io/CTestCResultContext.h"

#include "logger/CTestLoggerControll.h"
#include "logger/CTestLoggerHistory.h"

#include "settings/CTestCAlgorithmSettingController.h"
#include "settings/CTestCGlobalSettingController.h"

#include "workflow/plugin/CTestCPluginmanager.h"
#include "workflow/CTestCWorkflowmanager.h"
#include "workflow/CTestCContextDataStore.h"
#include "workflow/CTestCWorkflow.h"
#include "gui/CTestCImageTab.h"

#include "components/CTestAlgorithmSettings.h"
#include "components/CTestAlgorithmExecution.h"
#include "components/CTestGlobalParameterSL.h"
#include "components/CTestResultDir.h"
#include "components/CTestLoggerOutput.h"
#include "components/CTestAlgorithmControllerOutput.h"
#include "components/CTestTabLog.h"
#include "components/CTestAlgorithmSelection.h"


int main(int argc, char* argv[])
{
  CTestCDatasetSelector datasetSelector;
  CTestCLogWidget logWidget;
  CTestCMainWindow mainWindow;
  CTestCSettingsDialog settingsDialog;

  CTestCImageIo imageIo;
  CTestCTextIo textIo;
  CTestCInputDataSet inputDataSet;
  CTestCResultContext resultContext;

  CTestLoggerControll logControll;
  CTestLoggerHistory logHistory;

  CTestCAlgorithmSettingController algorithmcontroller;
  CTestCGlobalSettingController globalcontroller;

  CTestCPluginmanager pluginmanager;
  CTestCWorkflowmanager workflowmanager;
  CTestCContextDataStore datastore;
  CTestCWorkflow workflow;
  CTestCImageTab imageTab;
  CTestAlgorithmSettings algorithmSettings;
  CTestAlgorithmExecution algorithmExecution;
  CTestGlobalParameterSL globalParameterSL;
  CTestResultDir resultDir;
  CTestLoggerOutput logoutput;
  CTestAlgorithmControllerOutput algorithmoutput;
  CTestTabLog tabLog;
  CTestAlgorithmSelection algorithmSelection;

  QApplication app(argc, argv);

  int failCounter = 0;
  failCounter += QTest::qExec(&datasetSelector, argc, argv);
  failCounter += QTest::qExec(&logWidget, argc, argv);
  failCounter += QTest::qExec(&mainWindow, argc, argv);
  failCounter += QTest::qExec(&settingsDialog, argc, argv);

  failCounter += QTest::qExec(&imageIo, argc, argv);
  failCounter += QTest::qExec(&textIo, argc, argv);
  failCounter += QTest::qExec(&inputDataSet, argc, argv);
  failCounter += QTest::qExec(&resultContext, argc, argv);

  failCounter += QTest::qExec(&logControll, argc, argv);
  failCounter += QTest::qExec(&logHistory, argc, argv);

  failCounter += QTest::qExec(&algorithmcontroller, argc, argv);
  failCounter += QTest::qExec(&globalcontroller, argc, argv);

  failCounter += QTest::qExec(&datastore, argc, argv);
  failCounter += QTest::qExec(&workflow, argc, argv);
  failCounter += QTest::qExec(&imageTab, argc, argv);
  failCounter += QTest::qExec(&pluginmanager, argc, argv);
  failCounter += QTest::qExec(&workflowmanager, argc, argv);
  failCounter += QTest::qExec(&datastore, argc, argv);
  failCounter += QTest::qExec(&workflow, argc, argv);

  failCounter += QTest::qExec(&algorithmSettings, argc, argv);
  failCounter += QTest::qExec(&algorithmExecution, argc, argv);
  failCounter += QTest::qExec(&globalParameterSL, argc, argv);
  failCounter += QTest::qExec(&resultDir, argc, argv);
  failCounter += QTest::qExec(&logoutput, argc, argv);
  failCounter += QTest::qExec(&algorithmoutput, argc, argv);
  failCounter += QTest::qExec(&tabLog, argc, argv);
  failCounter += QTest::qExec(&algorithmSelection, argc, argv);

  std::cout << "Total number of fails: " << failCounter << "\n";
  return 0;  
}
