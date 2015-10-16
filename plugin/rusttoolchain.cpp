#include "rusttoolchain.h"
#include "rustoutputparser.h"
#include "rusttoolchainconfigwidget.h"

#include <projectexplorer/abi.h>
#include <projectexplorer/headerpath.h>
#include <utils/fileutils.h>

using namespace ProjectExplorer;
using namespace Utils;

namespace Rust {

RustToolChain::RustToolChain()
    : ToolChain(QString::fromLatin1("RustToolChainId"), ToolChain::ManualDetection)
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

QString RustToolChain::type() const
{
    return QString::fromLatin1("rustc");
}

QString RustToolChain::typeDisplayName() const
{
    return QString::fromLatin1("MSVC");
}

Abi RustToolChain::targetAbi() const
{
    return Abi::hostAbi();
}

bool RustToolChain::isValid() const
{
    return true;
}

QByteArray RustToolChain::predefinedMacros(const QStringList& cxxflags) const
{
    Q_UNUSED(cxxflags)
    return QByteArray();
}

ToolChain::CompilerFlags RustToolChain::compilerFlags(const QStringList& cxxflags) const
{
    Q_UNUSED(cxxflags)
    return ToolChain::NoFlags;
}

ToolChain::WarningFlags RustToolChain::warningFlags(const QStringList& cflags) const
{
    Q_UNUSED(cflags)
    return ToolChain::WarningsDefault;
}

QList<HeaderPath> RustToolChain::systemHeaderPaths(const QStringList& cxxflags, const FileName& sysRoot) const
{
    Q_UNUSED(cxxflags)
    Q_UNUSED(sysRoot)
    return QList<HeaderPath>();
}

void RustToolChain::addToEnvironment(Environment& env) const
{
    Q_UNUSED(env)
}

QString RustToolChain::makeCommand(const Environment& env) const
{
    Q_UNUSED(env)
    return QString::fromLatin1("rustc");
}

FileName RustToolChain::compilerCommand() const
{
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
    return nullptr;
}

}
