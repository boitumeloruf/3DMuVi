#include <QMessageBox>
#include <QFileDialog>

#include <io/CInputDataSet.h>
#include <workflow/workflow/cworkflowmanager.h>

#include "CSettingsDialog.h"

#include "CMainWindow.h"
#include "ui_CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::CMainWindow)
{
  QVector<QString> workflows;
  AWorkflow* fourPhaseWorkflow = CWorkflowManager::Instance()->getWorkflow("4Phase Workflow");

  ui->setupUi(this);

  setWorkflow(fourPhaseWorkflow);

  workflows = CWorkflowManager::Instance()->getAvailableWorkflows();
  for (QString w : workflows)
  {
    ui->menuWorkflow->addAction(w, this, SLOT(onWorkflowSelected()));
  }

  connect(ui->actionLoadImages, &QAction::triggered, this, &CMainWindow::onLoadImages);
//TODO: advanced load files
  connect(ui->actionSettings, &QAction::triggered, this, &CMainWindow::onSettings);
  connect(ui->actionAbout, &QAction::triggered, this, &CMainWindow::onAbout);
}

CMainWindow::~CMainWindow()
{
  delete ui;
}

void CMainWindow::setWorkflow(AWorkflow* workflow)
{
  ui->algorithmSelector->setWorkflow(*workflow);
  mWorkflow.reset(workflow);

  connect(workflow, &AWorkflow::sigDataStoreFinished, this,
          &CMainWindow::onDataStoreFinished);
}

void CMainWindow::onSaveWorkflow()
{
  //TODO: Doesn't need to be implemented
}

void CMainWindow::onSaveWorkflowAs()
{
  //TODO: Doesn't need to be implemented
}

void CMainWindow::onLoadImages()
{
  QUrl url = QFileDialog::getExistingDirectoryUrl(this, "Select image directory");

  if(!url.isEmpty() && mWorkflow)
  {
    CInputDataSet* dataSet = new CInputDataSet(url);
    std::vector<std::tuple<uint32_t, QImage, CImagePreviewItem>>* images =
      dataSet->getInputImages();
    std::vector<CImagePreviewItem*> imageItems;
    CContextDataStore* dataStore = mWorkflow->addDataStore();

    dataStore->InitializeFromStorage(dataSet);
    mDataStore.reset(dataStore);

    for(std::tuple<uint32_t, QImage, CImagePreviewItem> i : *images)
    {
      imageItems.push_back(&(std::get<2>(i)));
    }

    ui->imagePreviewWidget->setImages(imageItems);
    ui->algorithmSelector->setDataStore(dataStore->getId());
  }
}

void CMainWindow::onAdvancedLoadFiles()
{
  //TODO: Doesn't need to be implemented
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

void CMainWindow::onDataStoreFinished(CContextDataStore* dataStorage)
{
  ui->dataViewTabContainer->applyDataStorage(dataStorage);
}
