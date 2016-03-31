#include "rustplugin.h"
#include "rustconstants.h"

#include <QtPlugin>

#include <utils/mimetypes/mimedatabase.h>

#include "cargoprojectmanager.h"
#include "rusttoolchainfactory.h"
#include "ProjectExplorer_Build/rustbuildconfigurationfactory.h"

using namespace Rust;

RustPlugin::RustPlugin()
{
    // Create your members
}

RustPlugin::~RustPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool RustPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    Utils::MimeDatabase::addMimeTypes(QLatin1String(":/rust/mimetypes.xml"));

    addAutoReleasedObject(new CargoProjectManager);
    addAutoReleasedObject(new RustToolChainFactory);
    addAutoReleasedObject(new RustBuildConfigurationFactory);

    return true;
}

void RustPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag RustPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}
