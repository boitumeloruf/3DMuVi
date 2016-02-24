#include "CLogController.h"
#include "CLogHistory.h"
#include "../qslogging/QsLog.h"
#include "../qslogging/QsLogDest.h"
#include <QDir>
#include <iostream>
#include <ctime>
using namespace QsLogging;

CLogHistory history;
bool destSet;
bool windowlog;
bool datalog;
int loglevel;

/**
 * @brief CLogController::CLogController constructor
 * sets the private attrubute destSet to false;
 * use the function setLog(QUrl dest) to set an dest for the logger file
 */
CLogController::CLogController(){
   history = CLogHistory();
   destSet= false;
   loglevel = 2;
   windowlog = true;
   datalog = true;
 }
CLogController::activateWindowlog(){
   windowlog = true;
 }
CLogController::deactivateWindowlog(){
   windowlog = false;
 }
CLogController::activateDatalog(){
   datalog = true;
 }
CLogController::deactivateDatalog(){
   datalog = false;
 }
CLogController& operator<< (CLogController& logger,  const int& loglev)
{
  loglevel = loglev;
  return logger;
}

CLogController& operator<< (CLogController& logger,  const QString& message)
{

   QString type;
   if(loglevel == 0){
       type = "ERROR";
      }
   if(loglevel == 1){
       type = "WARNING";
      }
   if(loglevel == 2){
       type = "INFO";
      }
   if(loglevel == 3){
       type = "DEBUG";
      }


    if( !((type == "ERROR") || (type == "WARNING") || (type == "DEBUG")))
    {
            type = "INFO";
  }

    QString mtime = "";
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%A, %B %d, %Y %I:%M:%S %p",timeinfo);
    mtime = buffer;

    logger.manageNewLogMessage(message, mtime, type);
    return logger;
}


/**
 * @brief CLogController::manageNewLogMessage this function manage new Logmessages
 *        from CAlgoMessage objects. It adds this objects to the History, calls QsLogging
 *        to write it to a file, if Destination is set, and send a Signal to the GUI
 *        with the new message
 *
 * @param message QString text to log
 * @param time    QString timestamp of the logmessage
 * @param type    QString "INFO", "ERROR" , "WARNING" or "DEBUG"
 */
void CLogController::manageNewLogMessage(QString message, QString time, QString type) {

    if( !((type == "ERROR") || (type == "WARNING") || (type == "DEBUG")))
    {
            type = "INFO";
    }
    if(windowlog){
      history.addHistory(message,time,type);
      emit this->newLogMessage(message, time ,type );
    }

    if( destSet && datalog ){
        if(type == "INFO"){
        QLOG_INFO() << message;
        }
        if(type == "ERROR"){
        QLOG_ERROR() << message;
        }
        if(type == "WARNING"){
        QLOG_WARN() << message;
        }
        if(type == "DEBUG"){
        QLOG_DEBUG() << message;
        }


    }else{
    }

}
/**
 * @brief CLogController::getHistory give the History where the log messages are saved temp
 * @return CLogHistory& reference to the history object;
 */
CLogHistory& CLogController::getHistory( ){
    CLogHistory& refhistory = history;
    return refhistory;
}

/**
 * @brief CLogController::setLog this function is used
 *        to create a output destination for the txt files
 *        it activates the file logging
 * @param dest QUrl with the destination
 */
void CLogController::setLog(QUrl dest) {

    Logger& logger =  Logger::instance();
    logger.setLoggingLevel(TraceLevel);
    const QString sLogPath = dest.toString();
    DestinationPtr fileDestination(DestinationFactory::MakeFileDestination(
      sLogPath, EnableLogRotation, MaxSizeBytes(20000000), MaxOldLogCount(2000000)));
    DestinationPtr debugDestination(DestinationFactory::MakeDebugOutputDestination());
    //DestinationPtr functorDestination(DestinationFactory::MakeFunctorDestination(&logFunction));
    logger.addDestination(debugDestination);
    logger.addDestination(fileDestination);
   // logger.addDestination(functorDestination);

    destSet = true;

}
/**
 * @brief CLogController::closeLog this is used to close the log Destination
 * and stop the File Logging
 */
void CLogController::closeLog() {
    destSet = false;
    Logger::destroyInstance();

}

