#include "cargoprojectnode.h"

CargoProjectNode::CargoProjectNode(const Utils::FileName& projectFilePath)
    : ProjectExplorer::ProjectNode(projectFilePath)
{

}

bool CargoProjectNode::canAddSubProject(const QString &proFilePath) const
{
    return false;
}

bool CargoProjectNode::addSubProjects(const QStringList &proFilePaths)
{
    return false;
}

bool CargoProjectNode::removeSubProjects(const QStringList &proFilePaths)
{
    return false;
}
