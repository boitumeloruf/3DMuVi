#ifndef CGLOBALSETTINGCONTROLLER_H
#define CGLOBALSETTINGCONTROLLER_H

#include <QString>
#include <QUrl>
#include <QJsonObject>
#include "io/CTextIo.h"

class CGlobalSettingController {
private:
    QJsonObject settings;
    CTextIo io;
public:
    /*!
     * \brief CGlobalSettingController
     */
    CGlobalSettingController();
    /*!
     * \gets a certain global setting
     * \param name name of the setting
     * \return value of teh setting as QString
     */
    QString getSetting(QString name) const;
    /*!
     * \sets a global setting
     * \param name mane of the setting
     * \param data value of the setting
     */
    bool setSetting(QString name, QString data);
    /*!
     * \imports a globalconfig file from a directory, file must be in Json Format
     * \param directory directoy of the file
     * \param name name of the file
     */
    void import(QUrl diretory, QString name);
    /*!
     * \exports the globalsettings in a config file in JsonFormat
     * \param directory the directory where the config should be
     */
    void exportTo(QUrl diretory) const;
    /*!
     * \resets all settings to default
     */
    void resetToDefault();
};
#endif //CGLOBALSETTINGCONTROLLER_H
