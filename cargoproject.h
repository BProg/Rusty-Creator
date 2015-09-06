#ifndef CARGOPROJECT_H
#define CARGOPROJECT_H

#include <QString>

#include "projectexplorer/project.h"

class CargoProjectManager;
class CargoProjectNode;
class CargoProjectFile;

class CargoProject : public ProjectExplorer::Project
{
    Q_OBJECT

public:
    CargoProject(CargoProjectManager* projectManager, QString projectFileName);

    virtual QString displayName() const override;
    virtual Core::IDocument* document() const override;
    virtual ProjectExplorer::IProjectManager* projectManager() const override;
    virtual ProjectExplorer::ProjectNode* rootProjectNode() const override;
    virtual QStringList files(FilesMode fileMode) const override;

private:
    CargoProjectManager* projectManager_;
    QString projectFileName_;
    CargoProjectNode* rootNode_;
    CargoProjectFile* projectFile_;
};

#endif
