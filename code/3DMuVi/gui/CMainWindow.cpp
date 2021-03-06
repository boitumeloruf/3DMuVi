#include "CMainWindow.h"

#include <QMessageBox>
#include <QFileDialog>

#include <io/CInputDataSet.h>
#include <io/CResultContext.h>
#include <settings/CGlobalSettingController.h>
#include <workflow/workflow/cworkflowmanager.h>

#include "CSettingsDialog.h"

#include "ui_CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::CMainWindow)
{
  QVector<QString> workflows;
  AWorkflow* fourPhaseWorkflow = CWorkflowManager::Instance()->getWorkflow("4Phase Workflow");

  ui->setupUi(this);

  ui->dataViewTabContainer->setImagePreviewWidget(ui->imagePreviewWidget);

  setWorkflow(fourPhaseWorkflow);

  workflows = CWorkflowManager::Instance()->getAvailableWorkflows();
  for (QString w : workflows)
  {
    ui->menuWorkflow->addAction(w, this, SLOT(onWorkflowSelected()));
  }

  connect(ui->actionLoadImages, &QAction::triggered, this, &CMainWindow::onLoadImages);
  connect(ui->actionSettings, &QAction::triggered, this, &CMainWindow::onSettings);
  connect(ui->actionAbout, &QAction::triggered, this, &CMainWindow::onAbout);

  connect(ui->algorithmSelector, &CAlgorithmSelector::workflowRunning, ui->actionLoadImages,
          &QAction::setDisabled);
  connect(ui->algorithmSelector, &CAlgorithmSelector::workflowRunning, ui->menuWorkflow,
          &QMenu::setDisabled);
  connect(ui->algorithmSelector, &CAlgorithmSelector::workflowRunning, ui->actionSettings,
          &QAction::setDisabled);
  connect(ui->algorithmSelector, &CAlgorithmSelector::workflowRunning, ui->algorithmSettingsView,
          &CAlgorithmSettingsView::setDisabled);
  connect(ui->algorithmSelector, &CAlgorithmSelector::workflowRunning,ui->datasetSelector,
          &CDatasetSelector::setDisabled);

  connect(ui->algorithmSelector, &CAlgorithmSelector::workflowRunning, this,
          &CMainWindow::onWorkflowRunning);

  connect(ui->algorithmSelector, &CAlgorithmSelector::algorithmChanged, ui->algorithmSettingsView,
          &CAlgorithmSettingsView::onAlgorithmChanged);
  connect(ui->algorithmSelector, &CAlgorithmSelector::start, ui->algorithmSettingsView,
          &CAlgorithmSettingsView::onStart);

  connect(ui->logDebugCheckBox, &QCheckBox::stateChanged, ui->logWidget,
          &CLogWidget::onStateChangedDebug);
  connect(ui->logErrorCheckBox, &QCheckBox::stateChanged, ui->logWidget,
          &CLogWidget::onStateChangedError);
  connect(ui->logInfoCheckBox, &QCheckBox::stateChanged, ui->logWidget,
          &CLogWidget::onStateChangedInfo);
  connect(ui->logWarningCheckBox, &QCheckBox::stateChanged, ui->logWidget,
          &CLogWidget::onStateChangedWarning);

  connect(ui->datasetSelector, &CDatasetSelector::currentDataStoreChanged,
          this, &CMainWindow::onCurrentDataStoreChanged);
  connect(ui->datasetSelector, &CDatasetSelector::newDataStoreRequested,
          this, &CMainWindow::onNewDataStoreRequested);
  connect(ui->datasetSelector, &CDatasetSelector::dataStoreDeleted,
          this, &CMainWindow::onDataStoreDeleted);
}

CMainWindow::~CMainWindow()
{
  delete ui;
}

void CMainWindow::setLoadImage(QUrl url){
  if(!url.isEmpty() && mWorkflow)
  {
    CContextDataStore* dataStore = nullptr;
    if(!mDataStore || mDataStore->getData<CInputDataSet>().get() != nullptr)
    {
      dataStore = mWorkflow->addDataStore();
      ui->datasetSelector->newDataStore(dataStore);
    }
    else
    {
      dataStore = mDataStore;
    }

    CInputDataSet* dataSet = new CInputDataSet(url);
    dataStore->InitializeFromStorage(dataSet);

    QString iFrameworkM = QString::number(dataSet->getInputImages()->size());
    iFrameworkM.append(" images have been loaded from the directory");
    CLogController::instance().frameworkMessage(iFrameworkM);

    mDataStore = dataStore;
    onCurrentDataStoreChanged(dataStore);
  }
}

void CMainWindow::setWorkflow(AWorkflow* workflow)
{
  if(mDataStore)
  {
    resetDataStore();
  }

  ui->algorithmSelector->setWorkflow(*workflow);
  ui->algorithmSettingsView->setWorkflow(*workflow);
  mWorkflow.reset(workflow);

  connect(workflow, &AWorkflow::sigDataStoreFinished, this,
          &CMainWindow::onDataStoreFinished);
}

void CMainWindow::resetDataStore()
{
  ui->datasetSelector->clear();
  ui->imagePreviewWidget->setImages(std::vector<CImagePreviewItem*>());
  ui->algorithmSelector->setDataStore(QString());

  ui->dataViewTabContainer->clearData();

  if(mDataStore && mWorkflow)
  {
    mWorkflow->removeDataStore(mDataStore->getId());
  }
  mDataStore = nullptr;
}

void CMainWindow::onLoadImages()
{
  QUrl url = QFileDialog::getExistingDirectoryUrl(this, "Select image directory");
  setLoadImage(url);
}

void CMainWindow::onWorkflowSelected()
{
  QAction* callingAction = qobject_cast<QAction*>(sender());

  if(callingAction)
  {
    AWorkflow* workflow = CWorkflowManager::Instance()->getWorkflow(callingAction->text());

    setWorkflow(workflow);
  }
}

void CMainWindow::onSettings()
{
  CSettingsDialog dialog(this);
  dialog.exec();
}

void CMainWindow::onAbout()
{
  QMessageBox::about(this, "About 3DMuVi", "3DMuVi is a framework for testing " \
                                           "3D-reconstruction-algorithms.\nCopyright 2016 Tim " \
                                           "Brodbeck, Jens Manig, Grigori Schapoval, Nathanael " \
                                           "Schneider, Laurenz Thiel and Stefan Wolf.");
}

void CMainWindow::onWorkflowRunning(bool isRunning)
{
  if(isRunning)
  {
    CGlobalSettingController settings;
    auto result = new CResultContext(settings.getSetting("resultDirectory"),
                                     ui->algorithmSettingsView->getAlgorithmController(),
                                     &settings);

    mCurrentResultContext.reset(result);
  }
}

void CMainWindow::onDataStoreFinished(CContextDataStore* dataStorage)
{
  ui->dataViewTabContainer->applyDataStorage(dataStorage);

  if(mCurrentResultContext)
  {
    dataStorage->Serialize(mCurrentResultContext.get());
  }
}

void CMainWindow::onCurrentDataStoreChanged(CContextDataStore* dataStore)
{
  auto dataSet = dataStore ? dataStore->getData<CInputDataSet>() : nullptr;

  std::vector<CImagePreviewItem*> imageItems;

  if(dataSet)
  {
    std::vector<std::tuple<uint32_t, QImage, CImagePreviewItem>> const* images =
      dataSet->getInputImages();

    for(std::tuple<uint32_t, QImage, CImagePreviewItem> i : *images)
    {
      imageItems.push_back(new CImagePreviewItem(std::get<2>(i)));
    }
  }

  ui->imagePreviewWidget->setImages(imageItems);

  if(dataStore)
  {
    ui->algorithmSelector->setDataStore(dataStore->getId());
    ui->dataViewTabContainer->applyDataStorage(dataStore);
  }
  else
  {
    ui->algorithmSelector->setDataStore(QString());
    ui->dataViewTabContainer->clearData();
  }

  mDataStore = dataStore;
}

void CMainWindow::onDataStoreDeleted(CContextDataStore* dataStore)
{
  if(dataStore)
  {
    mWorkflow->removeDataStore(dataStore->getId());
  }
}

void CMainWindow::onNewDataStoreRequested()
{
  ui->datasetSelector->newDataStore(mWorkflow->addDataStore());
}
