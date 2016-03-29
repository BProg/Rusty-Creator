#include "rusttoolchainfactory.h"
#include "rusttoolchain.h"

#include <QList>

using namespace ProjectExplorer;

namespace Rust {

RustToolChainFactory::RustToolChainFactory()
{
    // This name appears in the 'Tools/Options/Build&Run/Compilers' options
    // tab, in the list that appears when the "Add" button is clicked.
    //
    setDisplayName(QString::fromLatin1("Rust"));
}

QList<ToolChain*> RustToolChainFactory::autoDetect(const QList<ToolChain *> &alreadyKnown)
{
    // STUB
    return alreadyKnown;
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
    // STUB
    return false;
}

ToolChain* RustToolChainFactory::restore(const QVariantMap& data)
{
    Q_UNUSED(data)
    // STUB
    return nullptr;
}

}
