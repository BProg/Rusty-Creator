#include "rusttoolchainfactory.h"
#include "rusttoolchain.h"

#include <QList>

using namespace ProjectExplorer;

namespace Rust {

RustToolChainFactory::RustToolChainFactory()
{
    setDisplayName(QString::fromLatin1("Rust"));
}

QList<ToolChain*> RustToolChainFactory::autoDetect()
{
    return QList<ToolChain*>();
}

bool RustToolChainFactory::canCreate()
{
    return true;
}

ToolChain* RustToolChainFactory::create()
{
    return new RustToolChain;
}

bool RustToolChainFactory::canRestore(const QVariantMap& data)
{
    Q_UNUSED(data)
    return false;
}

ToolChain* RustToolChainFactory::restore(const QVariantMap& data)
{
    Q_UNUSED(data)
    return nullptr;
}

}
