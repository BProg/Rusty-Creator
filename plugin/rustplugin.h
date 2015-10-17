#ifndef RUST_H
#define RUST_H

#include "rust_global.h"

#include <extensionsystem/iplugin.h>

namespace Rust {

/// The entry point in QtCreator's extension system.
///
class RustPlugin : public ExtensionSystem::IPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Rust.json")

public:
  RustPlugin();
  ~RustPlugin();

  // ExtensionSystem::IPlugin interface
  bool initialize(const QStringList &arguments, QString *errorString) override;
  void extensionsInitialized() override;
  ShutdownFlag aboutToShutdown() override;

};
}

#endif
