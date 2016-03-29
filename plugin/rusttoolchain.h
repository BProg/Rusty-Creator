#ifndef RUSTTOOLCHAIN_H
#define RUSTTOOLCHAIN_H

#include <projectexplorer/toolchain.h>

namespace Rust {

/// Represents one compiler with its configuration.
///
/// Instances of this class can be created and modified in the
/// 'Tools/Options/Build&Run/Compilers' option tab, and can be selected in the
/// 'Tools/Options/Build&Run/Kits' options tab. They will be used in build step
/// configurations of Cargo commands, to choose the compiler used and to pass
/// options to it.
///
class RustToolChain : public ProjectExplorer::ToolChain
{
public:
    RustToolChain();

    /// See https://doc.rust-lang.org/book/release-channels.html
    ///
    /// Unofficial means that the compiler does not come from an official
    /// release channel.
    ///
    enum ReleaseChannel {
        ChannelStable = 0,
        ChannelBeta = 1,
        ChannelNightly = 2,
        ChannelUnofficial = 3
    };

    void setReleaseChannel(ReleaseChannel c);
    ReleaseChannel releaseChannel();

    // ProjectExplorer::ToolChain interface
    QString displayName() const;
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

private:

    /// This is mostly informative.
    ///
    ReleaseChannel releaseChannel_;
};

}

#endif
