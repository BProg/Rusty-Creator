#ifndef RUSTOUTPUTPARSER_H
#define RUSTOUTPUTPARSER_H

#include <projectexplorer/ioutputparser.h>

namespace Rust {

/// Needed by `RustToolChain::outputParser`
///
class RustOutputParser : public ProjectExplorer::IOutputParser
{
public:
    RustOutputParser();

};

}
#endif
