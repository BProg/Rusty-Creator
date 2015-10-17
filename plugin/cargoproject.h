#ifndef CARGOPROJECT_H
#define CARGOPROJECT_H

#include <QString>
#include <QScopedPointer>

#include "projectexplorer/project.h"

namespace Rust { class CargoProjectManager; }
namespace Rust { class CargoProjectNode; }
namespace Rust { class CargoProjectFile; }

namespace Rust {

/// Represents one entry in the "Projects" navigator view.
///
class CargoProject : public ProjectExplorer::Project
{
    Q_OBJECT

public:
    CargoProject(CargoProjectManager* projectManager, QString projectFileName);

    // ProjectExplorer::Project interface
    virtual QString displayName() const override;
    virtual Core::IDocument* document() const override;
    virtual ProjectExplorer::IProjectManager* projectManager() const override;
    virtual ProjectExplorer::ProjectNode* rootProjectNode() const override;
    virtual QStringList files(FilesMode fileMode) const override;

private:
    CargoProjectManager* projectManager_;
    QString projectFileName_;
    QScopedPointer<CargoProjectNode> rootNode_;
    QScopedPointer<CargoProjectFile> projectFile_;
};
}

#endif
