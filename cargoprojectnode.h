#ifndef CARGOPROJECTNODE_H
#define CARGOPROJECTNODE_H

#include "projectexplorer/projectnodes.h"

class CargoProjectNode : public ProjectExplorer::ProjectNode
{
public:
    CargoProjectNode(const Utils::FileName& projectFilePath);

    virtual bool canAddSubProject(const QString &proFilePath) const override;
    virtual bool addSubProjects(const QStringList &proFilePaths) override;
    virtual bool removeSubProjects(const QStringList &proFilePaths) override;
};

#endif
