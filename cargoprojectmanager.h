#ifndef CARGOPROJECTMANAGER_H
#define CARGOPROJECTMANAGER_H

#include "projectexplorer/iprojectmanager.h"

#include <QString>

namespace ProjectExplorer { class Project; }

class CargoProjectManager : public ProjectExplorer::IProjectManager
{
  Q_OBJECT

public:
  CargoProjectManager();

  virtual QString mimeType() const;

  virtual ProjectExplorer::Project* openProject(const QString & fileName, QString * errorString);
};

#endif
