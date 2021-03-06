#ifndef ASTREAMPROVIDER_H
#define ASTREAMPROVIDER_H

#include <QDataStream>
#include <QDir>
#include <QFile>

/*!
 * \class AStreamProvider
 * \brief The AStreamProvider class
 * \author Laurenz Thiel
 *
 * Provide essential functions of a StreamProvider.
 */
class AStreamProvider {
public:
    virtual ~AStreamProvider() {}

    AStreamProvider();
    virtual QDataStream* getNextStream() = 0;
    /*!
    \brief Sets the path to the destination folder.
    \param destinationFolder is the folder where the results should be stored.
    */
    void setDestination(QDir destinationFolder);
    /*!
    \brief Provide the path to the destination folder.
    \return QDir is the folder where the results are stored.
    */
    QDir getDestination() const;
    /*!
    \brief Sets the file name.
    \param fileName Name of the file.
    */
    virtual void setFileName(const QString& fileName);
protected:
    QDir folder;
    QString fileName;
};

#endif // ASTREAMPROVIDER_H
