#ifndef CARGOPROJECTMANAGER_H
#define CARGOPROJECTMANAGER_H

#include "projectexplorer/iprojectmanager.h"

#include <QString>

namespace ProjectExplorer { class Project; }

namespace Rust {

class CargoProjectManager : public ProjectExplorer::IProjectManager
{
  Q_OBJECT

public:
  CargoProjectManager();

  virtual QString mimeType() const override;

  virtual ProjectExplorer::Project* openProject(const QString & fileName,
                                                QString * errorString) override;
};
}

#endif
