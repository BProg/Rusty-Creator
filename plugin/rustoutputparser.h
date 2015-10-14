#ifndef RUSTOUTPUTPARSER_H
#define RUSTOUTPUTPARSER_H

#include <projectexplorer/ioutputparser.h>

namespace Rust {

class RustOutputParser : public ProjectExplorer::IOutputParser
{
public:
    RustOutputParser();

};

}
#endif
