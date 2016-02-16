#ifndef TOOLAUTOFINDER_H
#define TOOLAUTOFINDER_H

#include <QString>

namespace Rust {

class ToolAutoFinder
{
public:
    ToolAutoFinder();
    static QString findCargoTool();
    static QString findRustcTool();
};

}

#endif // TOOLAUTOFINDER_H
