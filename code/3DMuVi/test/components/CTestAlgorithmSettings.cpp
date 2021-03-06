#include "CTestAlgorithmSettings.h"

#include <gui/AlgorithmSettings/CAlgorithmSettingsView.h>
#include <workflow/workflow/cworkflowmanager.h>
#include <workflow/plugin/cpluginmanager.h>

QJsonObject CTestAlgorithmSettings::mSettings;
bool CTestAlgorithmSettings::mSettingsSet = false;
const int CTestAlgorithmSettings::TEST_VALUE_VALID = 33;
const int CTestAlgorithmSettings::TEST_VALUE_INVALID = 66;

void CTestAlgorithmSettings::setParameters(QJsonObject settings)
{
  mSettings = settings;
  mSettingsSet = true;
}

void CTestAlgorithmSettings::test()
{
  AWorkflow* workflow = CWorkflowManager::Instance()->getWorkflow("4Phase Workflow");
  QVector<IPlugin*> plugins = CPluginManager::Instance()->getPlugins();
  bool pluginFound = false;

  for(IPlugin* p : plugins)
  {
    if(p->Name() == "AlgorithmSettingsTest")
    {
      workflow->trySetStep(0, p);
      pluginFound = true;
      break;
    }
  }
  QCOMPARE(pluginFound, true);

  if(pluginFound)
  {
    CAlgorithmSettingsView* settingsView = new CAlgorithmSettingsView;
    QAbstractItemModel* model = nullptr;
    QModelIndex index;

    settingsView->setWorkflow(*workflow);
    model = static_cast<QTreeView*>(settingsView)->model();

    index = model->index(0, 0, settingsView->rootIndex());
    index = model->index(0, 1, index);

    mSettingsSet = false;
    model->setData(index, QVariant(TEST_VALUE_VALID));
    QVERIFY(mSettingsSet);
    QCOMPARE(mSettings.value("parameter").toInt(), TEST_VALUE_VALID);

    mSettingsSet = false;
    model->setData(index, QVariant(TEST_VALUE_INVALID));
    QVERIFY(!mSettingsSet);

    delete settingsView;
  }

  delete workflow;
}
