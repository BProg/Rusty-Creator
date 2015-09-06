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

// The name of the project, that can be seen in the welcome project list,
// and in the project root's contextual menu.
QString CargoProject::displayName() const
{
    return QString::fromLatin1("Stub Display Name");
}

// Not sure in what context this document is used.
Core::IDocument* CargoProject::document() const
{
    return projectFile_.data();
}

ProjectExplorer::IProjectManager* CargoProject::projectManager() const
{
    return projectManager_;
}

// The returned object must be the same on each call to this method.
ProjectExplorer::ProjectNode* CargoProject::rootProjectNode() const
{
    return rootNode_.data();
}

QStringList CargoProject::files(ProjectExplorer::Project::FilesMode fileMode) const
{
    return QStringList();
}
