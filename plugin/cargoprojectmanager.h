#ifndef CARGOPROJECTMANAGER_H
#define CARGOPROJECTMANAGER_H

#include "projectexplorer/iprojectmanager.h"

#include <QString>

namespace ProjectExplorer { class Project; }

namespace Rust {

/// This is actually a `CargoProject` factory.
///
/// An instance of this class is registered into the objects pool so that it is
/// available to the `ProjectExplorer` plugin. The `ProjectExplorer` plugin
/// uses the `mimeType` method to discover what type of file is considered a
/// project file, and calls `openProject` to instanciate a new project based on
/// such a file.
///
class CargoProjectManager : public ProjectExplorer::IProjectManager
{
  Q_OBJECT

public:
  CargoProjectManager();

  // ProjectExplorer::IProjectManager interface
  virtual QString mimeType() const override;
  virtual ProjectExplorer::Project* openProject(const QString & fileName,
                                                QString * errorString) override;
};
}

#endif
