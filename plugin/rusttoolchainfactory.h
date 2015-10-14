#ifndef RUSTTOOLCHAINFACTORY_H
#define RUSTTOOLCHAINFACTORY_H

#include <projectexplorer/toolchain.h>

namespace Rust {

class RustToolChainFactory : public ProjectExplorer::ToolChainFactory
{
public:
    RustToolChainFactory();

    virtual QList<ProjectExplorer::ToolChain*> autoDetect() override;
    virtual bool canCreate() override;
    virtual ProjectExplorer::ToolChain* create() override;
    virtual bool canRestore(const QVariantMap& data) override;
    virtual ProjectExplorer::ToolChain* restore(const QVariantMap& data) override;
};

}
#endif
