#include "rustkitchooser.h"

using namespace ProjectExplorer;

RustKitChooser::RustKitChooser()
{

}

Kit *RustKitChooser::currentKit()
{
    Kit *kit = new Kit();
    kit->setUnexpandedDisplayName(QString::fromLatin1("--RustKit--"));
    return kit;
}
