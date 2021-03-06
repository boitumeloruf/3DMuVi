#include "CResultContext.h"

CResultContext::CResultContext(QUrl path,
    CAlgorithmSettingController* algoSettings,
    CGlobalSettingController* globalSettings) {


    folder = QDir(path.path());
    auto timeString = QDateTime::currentDateTime().toString();
    folder.mkdir(timeString);
    folder.cd(timeString);

    QUrl folderUrl(folder.path());
    CLogController::instance().setLog(folderUrl);
    algoSettings->exportTo(folderUrl);
    globalSettings->exportTo(folderUrl);
}

void CResultContext::addDataPacket(std::shared_ptr<IDataPacket> data) {
    auto dataType = data->getDataType();
    if (!folder.cd(dataType)) {
        folder.mkdir(dataType);
        folder.cd(dataType);
    }

    AStreamProvider* streamProvider = data->getStreamProvider();
    if(streamProvider)
    {
      streamProvider->setDestination(folder);
      data->serialize(streamProvider);
      data->cleanUpStreamProvider();
    }

    folder.cdUp();
}

std::vector<QString> CResultContext::getDataPacketIds() {
    std::vector<QString> list;
    auto resultFolders = folder.entryList(QDir::AllDirs);
    for (QString resultFolder : resultFolders) {
        folder.cd(resultFolder);
        auto resultFiles = folder.entryList(QDir::Files);
        for (auto resultFile : resultFiles) {
            list.push_back(resultFile);
        }
        folder.cdUp();
    }
    return list;
}

IDataPacket* CResultContext::getDataPacket(QString /*id*/) {
    //TODO NYI
    return nullptr;
}
