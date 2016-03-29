#include "rusttoolchain.h"
#include "rustoutputparser.h"
#include "rusttoolchainconfigwidget.h"

#include <projectexplorer/abi.h>
#include <projectexplorer/headerpath.h>
#include <utils/fileutils.h>
#include <utils/environment.h>

using namespace ProjectExplorer;
using namespace Utils;

namespace Rust {

RustToolChain::RustToolChain()
    : ToolChain(Core::Id("RustToolChainId"), ToolChain::ManualDetection)
{
    setDisplayName(QString::fromLatin1("Rust Compiler"));
}

void RustToolChain::setReleaseChannel(RustToolChain::ReleaseChannel c)
{
    releaseChannel_ = c;
}

RustToolChain::ReleaseChannel RustToolChain::releaseChannel()
{
    return releaseChannel_;
}

QString RustToolChain::displayName() const
{
    return QString::fromLatin1("rustc");
}

QString RustToolChain::typeDisplayName() const
{
    // STUB
    return QString::fromLatin1("MSVC");
}

Abi RustToolChain::targetAbi() const
{
    // STUB
    return Abi::hostAbi();
}

bool RustToolChain::isValid() const
{
    // STUB
    return true;
}

QByteArray RustToolChain::predefinedMacros(const QStringList& cxxflags) const
{
    Q_UNUSED(cxxflags)
    // STUB
    return QByteArray();
}

ToolChain::CompilerFlags RustToolChain::compilerFlags(const QStringList& cxxflags) const
{
    Q_UNUSED(cxxflags)
    // STUB
    return ToolChain::NoFlags;
}

ToolChain::WarningFlags RustToolChain::warningFlags(const QStringList& cflags) const
{
    Q_UNUSED(cflags)
    // STUB
    return ToolChain::WarningsDefault;
}

QList<HeaderPath> RustToolChain::systemHeaderPaths(const QStringList& cxxflags, const FileName& sysRoot) const
{
    Q_UNUSED(cxxflags)
    Q_UNUSED(sysRoot)
    // STUB
    return QList<HeaderPath>();
}

void RustToolChain::addToEnvironment(Environment& env) const
{
    Q_UNUSED(env)
    // STUB
}

QString RustToolChain::makeCommand(const Environment& env) const
{
    Q_UNUSED(env)
    // STUB
    return QString::fromLatin1("rustc");
}

FileName RustToolChain::compilerCommand() const
{
    // STUB
    return FileName::fromString(QString::fromLatin1(R"(C:\Program Files\Rust stable 1.1\bin\rustc.exe)"));
}

IOutputParser* RustToolChain::outputParser() const
{
    return new RustOutputParser;
}

ToolChainConfigWidget* RustToolChain::configurationWidget()
{
    return new RustToolChainConfigWidget(this);
}

ToolChain* RustToolChain::clone() const
{
    // STUB
    return nullptr;
}

}
