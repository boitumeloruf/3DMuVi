#include "cpluginmanager.h"
#include <QtCore/qcoreapplication.h>

CPluginManager* CPluginManager::mInstance = nullptr;

const QString CPluginManager::PT_FeatureMatcher = "Feature Matcher";
const QString CPluginManager::PT_DepthMapper = "Depth Mapper";
const QString CPluginManager::PT_PoseEstimator = "Pose Estimator";
const QString CPluginManager::PT_PclReconstructor = "PCL Reconstructor";


CPluginManager::CPluginManager() {}

CPluginManager* CPluginManager::Instance() {
    if (mInstance == nullptr) {
        mInstance = new CPluginManager();
    }

    return mInstance;
}

QVector<IPlugin*> CPluginManager::getPlugins() const {
    return mPlugins;
}

qint32 CPluginManager::Initialize() {
    mPlugins.clear();

    // static plugins
    for(QObject *plugin : QPluginLoader::staticInstances()) {
        auto plugin_ptr = qobject_cast<IPlugin *>(plugin);
        if(plugin_ptr != nullptr) {
            mPlugins.push_back(plugin_ptr);
        }
    }

    mPluginsDir = QDir(qApp->applicationDirPath());
#if defined(Q_OS_WIN)
    if(mPluginsDir.dirName() == "debug" || mPluginsDir.dirName() == "release") {
        mPluginsDir.cdUp();
    }
#elif defined(Q_OS_MAC)
    if(mPluginsDir.dirName() == "MacOS") {
        mPluginsDir.cdUp();
        mPluginsDir.cdUp();
        mPluginsDir.cdUp();
    }
#endif
    mPluginsDir.cd("plugins");

    for(QString fileName : mPluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(mPluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        auto plugin_ptr = qobject_cast<IPlugin *>(plugin);

        if(plugin_ptr != nullptr) {
            mPlugins.push_back(plugin_ptr);
        }

    }

    auto size = mPlugins.size();
    return size;
}

QVector<IPlugin*> CPluginManager::getPlugins(QString type) const {
    QVector<IPlugin*> result;

    for(IPlugin *plugin : mPlugins) {
        auto pluginType = plugin->GetPluginType();
        if(pluginType.compare(type)) {
            result.push_back(plugin);
        }
    }

    return result;
}