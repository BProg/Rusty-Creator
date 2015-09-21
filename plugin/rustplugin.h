#ifndef RUST_H
#define RUST_H

#include "rust_global.h"

#include <extensionsystem/iplugin.h>

namespace Rust {

class RustPlugin : public ExtensionSystem::IPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Rust.json")

public:
  RustPlugin();
  ~RustPlugin();

  bool initialize(const QStringList &arguments, QString *errorString);
  void extensionsInitialized();
  ShutdownFlag aboutToShutdown();

};
}

#endif
