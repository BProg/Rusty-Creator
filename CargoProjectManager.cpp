#include "cargoprojectmanager.h"

CargoProjectManager::CargoProjectManager()
{

}

QString CargoProjectManager::mimeType() const {
    return QString::fromLatin1("text/cargo.toml");
}

ProjectExplorer::Project* CargoProjectManager::openProject(
        const QString& fileName,
        QString* errorString)
{
    return nullptr;
}

