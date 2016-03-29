#ifndef RUSTTOOLCHAINFACTORY_H
#define RUSTTOOLCHAINFACTORY_H

#include <projectexplorer/toolchain.h>

namespace Rust {

/// An instance of this class is registered into the objects pool so that it is
/// available to the `ProjectExplorer` plugin (the base class should actually
/// be named `IToolChainFactory`, to follow the conventions).
///
/// The `ProjectExplorer` plugin uses the `autoDetect` method to automatically
/// create `RustToolChain` instances that will be displayed in the
/// 'Tools/Options/Build&Run/Compilers' option tab. It also uses the `create`
/// method when the user clicks the "Rust" menu item that appears on the "Add"
/// button.
///
class RustToolChainFactory : public ProjectExplorer::ToolChainFactory
{
public:
    RustToolChainFactory();

    // ProjectExplorer::ToolChainFactory interface
    virtual QList<ProjectExplorer::ToolChain*> autoDetect(const QList<ProjectExplorer::ToolChain *> &alreadyKnown) override;
    virtual bool canCreate() override;
    virtual ProjectExplorer::ToolChain* create() override;
    virtual bool canRestore(const QVariantMap& data) override;
    virtual ProjectExplorer::ToolChain* restore(const QVariantMap& data) override;
};

}
#endif
