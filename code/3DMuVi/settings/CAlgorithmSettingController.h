#ifndef CALGORITHMSETTINGCONTROLLER_H
#define CALGORITHMSETTINGCONTROLLER_H

#include <QString>
#include <QJsonObject>
#include <QUrl>
#include <QStringList>
/*!
* Controller for the parameters of the algortihms
* Author Jens Manig
*/
class CAlgorithmSettingController 
{
private:
    QUrl tempdirectory;
    QStringList algorithms;
public:
    /*!
    * Constructor for the Controller
    * @param directory temporal workdirectory
	*/
    CAlgorithmSettingController(QUrl directory);
    /*!
    * Returns the setting for a certain algorithm
    * @param name name of the algorithm
    * @return the setting of the algorithm
    */
    QJsonObject getSetting(QString name);
    /*!
    * sets a new setting for an algorithm
    * @param name name of the algorithm
    * @param data the parameters of the algorithm as QJsonObject
    * @return true if data was a legal setting, else false
    */
    bool setSetting(QString name, QJsonObject data);
    /*!
    * impoert a setting for an algorithm as QJsonObject
    *@param directory of the setting
    *@param name name of the setting
    */
    void import(QUrl directory, QString name);
    /*!
    * exports all algorithmsettings to a directory
    *@param directory where all seeting should go
    */
    void exportto(QUrl directory);
};

#endif //CALGORITHMSETTINGCONTROLLER_H
