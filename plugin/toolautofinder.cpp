#include "toolautofinder.h"
#include <QStandardPaths>

using namespace Rust;

ToolAutoFinder::ToolAutoFinder()
{

}


QString Rust::ToolAutoFinder::findCargoTool()
{
    return QStandardPaths::findExecutable(QString::fromLatin1("cargo"));
}


QString Rust::ToolAutoFinder::findRustcTool()
{
    return QStandardPaths::findExecutable(QString::fromLatin1("rustc"));
}
