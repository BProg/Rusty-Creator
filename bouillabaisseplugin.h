#ifndef BOUILLABAISSE_H
#define BOUILLABAISSE_H

#include "bouillabaisse_global.h"

#include <extensionsystem/iplugin.h>

namespace Bouillabaisse {
namespace Internal {

class BouillabaissePlugin : public ExtensionSystem::IPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Bouillabaisse.json")

public:
  BouillabaissePlugin();
  ~BouillabaissePlugin();

  bool initialize(const QStringList &arguments, QString *errorString);
  void extensionsInitialized();
  ShutdownFlag aboutToShutdown();

private slots:
  void triggerAction();
};

} // namespace Internal
} // namespace Bouillabaisse

#endif // BOUILLABAISSE_H

