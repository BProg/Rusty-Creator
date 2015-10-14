#ifndef RUSTTOOLCHAIN_H
#define RUSTTOOLCHAIN_H

#include <projectexplorer/toolchain.h>

namespace Rust {

class RustToolChain : public ProjectExplorer::ToolChain
{
public:
    RustToolChain();

    virtual QString type() const override;
    virtual QString typeDisplayName() const override;
    virtual ProjectExplorer::Abi targetAbi() const override;
    virtual bool isValid() const override;
    virtual QByteArray predefinedMacros(const QStringList& cxxflags) const override;
    virtual CompilerFlags compilerFlags(const QStringList& cxxflags) const override;
    virtual WarningFlags warningFlags(const QStringList& cflags) const override;
    virtual QList<ProjectExplorer::HeaderPath> systemHeaderPaths(const QStringList& cxxflags, const Utils::FileName& sysRoot) const override;
    virtual void addToEnvironment(Utils::Environment& env) const override;
    virtual QString makeCommand(const Utils::Environment& env) const override;
    virtual Utils::FileName compilerCommand() const override;
    virtual ProjectExplorer::IOutputParser* outputParser() const override;
    virtual ProjectExplorer::ToolChainConfigWidget* configurationWidget() override;
    virtual ProjectExplorer::ToolChain* clone() const override;
};

}

#endif
