#include "cargoprojectnode.h"

// `projectFilePath` is the path of the Cargo.toml file. It can be seen in the
// tooltip attached to the project explorer's root item.
//
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

// The name displayed on the project explorer's root item.
QString CargoProjectNode::displayName() const
{
    return QString::fromLatin1("Stub project node");
}
