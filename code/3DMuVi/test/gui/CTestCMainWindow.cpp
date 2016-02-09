#include <iostream>

#include <QMessageBox>
#include <QMenuBar>
#include <QTimer>
#include <QThread>

#include <gui/CMainWindow.h>
#include <gui/CSettingsDialog.h>

#include "CTestCMainWindow.h"

#define WAITING_TIME 10
#define WAITING_TIME_LONG 20

void CTestCMainWindow::about()
{
  CMainWindow mw;

  for(QWidget* w : QApplication::allWidgets())
  {
    QMenuBar* menuBar = qobject_cast<QMenuBar*>(w);

    if(menuBar)
    {
      QTest::mouseClick(menuBar, Qt::LeftButton, 0, QPoint(200, 3));
    }
  }

  for(QWidget* w : QApplication::allWidgets())
  {
    QMenu* menu = qobject_cast<QMenu*>(w);

    if(menu)
    {
      QTimer::singleShot(WAITING_TIME, this, &CTestCMainWindow::aboutCheckMessageBox);
      QTest::mouseClick(menu, Qt::LeftButton, 0, QPoint(3, 3));
    }
  }

  QVERIFY(mAboutSuccess);
}

void CTestCMainWindow::aboutCheckMessageBox()
{
  for(QWidget* w : QApplication::topLevelWidgets())
  {
    QMessageBox* messageBox = qobject_cast<QMessageBox*>(w);

    if(messageBox)
    {
      if(messageBox->windowTitle() == "About 3DMuVi")
      {
        mAboutSuccess = true;
      }

      QTest::keyClick(messageBox, Qt::Key_Enter);
    }
  }
}

void CTestCMainWindow::settings()
{
  CMainWindow mw;

  for(QWidget* w : QApplication::allWidgets())
  {
    QMenuBar* menuBar = qobject_cast<QMenuBar*>(w);

    if(menuBar)
    {
      QTest::mouseClick(menuBar, Qt::LeftButton, 0, QPoint(150, 3));
    }
  }

  for(QWidget* w : QApplication::allWidgets())
  {
    QMenu* menu = qobject_cast<QMenu*>(w);

    if(menu)
    {
      QTimer::singleShot(WAITING_TIME, this, &CTestCMainWindow::settingsCheckDialog);
      QTest::mouseClick(menu, Qt::LeftButton, 0, QPoint(3, 3));
    }
  }

  QVERIFY(mSettingsSuccess);
}

void CTestCMainWindow::settingsCheckDialog()
{
  for(QWidget* w : QApplication::topLevelWidgets())
  {
    CSettingsDialog* dialog = qobject_cast<CSettingsDialog*>(w);

    if(dialog)
    {
      if(dialog->windowTitle() == "Settings")
      {
        mSettingsSuccess = true;
      }

      QTest::keyClick(dialog, Qt::Key_Escape);
    }
  }
}