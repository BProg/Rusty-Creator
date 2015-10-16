#include "cargoprojectfile.h"

#include "utils/fileutils.h"

using namespace Rust;

CargoProjectFile::CargoProjectFile(const QString &fileName)
{
    setMimeType(QString::fromLatin1("text/x-cargo.toml"));
    setFilePath(Utils::FileName::fromString(fileName));
}

bool CargoProjectFile::save(QString *errorString, const QString &fileName, bool autoSave)
{
    Q_UNUSED(errorString)
    Q_UNUSED(fileName)
    Q_UNUSED(autoSave)
    // STUB
    return false;
}

QString CargoProjectFile::defaultPath() const
{
    // STUB
    return QString();
}

QString CargoProjectFile::suggestedFileName() const
{
    // STUB
    return QString();
}

bool CargoProjectFile::isModified() const
{
    // STUB
    return false;
}

bool CargoProjectFile::isSaveAsAllowed() const
{
    // STUB
    return false;
}

bool CargoProjectFile::reload(QString *errorString, Core::IDocument::ReloadFlag flag, Core::IDocument::ChangeType type)
{
    Q_UNUSED(errorString)
    Q_UNUSED(flag)
    Q_UNUSED(type)
    // STUB
    return false;
}
