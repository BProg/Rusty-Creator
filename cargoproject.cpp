#include "cargoproject.h"

#include "cargoprojectnode.h"
#include "utils/fileutils.h"
#include "cargoprojectmanager.h"
#include "cargoprojectfile.h"

CargoProject::CargoProject(CargoProjectManager* projectManager, QString projectFileName)
    : projectManager_(projectManager),
      projectFileName_(projectFileName),
      rootNode_(new CargoProjectNode(Utils::FileName::fromString(projectFileName))),
      projectFile_(new CargoProjectFile(projectFileName))
{

}

QString CargoProject::displayName() const
{
    return QString::fromLatin1("Stub Display Name");
}

Core::IDocument* CargoProject::document() const
{
    return projectFile_;
}

ProjectExplorer::IProjectManager* CargoProject::projectManager() const
{
    return projectManager_;
}

ProjectExplorer::ProjectNode* CargoProject::rootProjectNode() const
{
    return rootNode_;
}

QStringList CargoProject::files(ProjectExplorer::Project::FilesMode fileMode) const
{
    return QStringList();
}
