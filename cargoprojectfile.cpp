#include "cargoprojectfile.h"

#include "utils/fileutils.h"

CargoProjectFile::CargoProjectFile(const QString &fileName)
{
    setMimeType(QString::fromLatin1("text/cargo.toml"));
    setFilePath(Utils::FileName::fromString(fileName));
}

bool CargoProjectFile::save(QString *errorString, const QString &fileName, bool autoSave)
{
    return false;
}

QString CargoProjectFile::defaultPath() const
{
    return QString();
}

QString CargoProjectFile::suggestedFileName() const
{
    return QString();
}

bool CargoProjectFile::isModified() const
{
    return false;
}

bool CargoProjectFile::isSaveAsAllowed() const
{
    return false;
}

bool CargoProjectFile::reload(QString *errorString, Core::IDocument::ReloadFlag flag, Core::IDocument::ChangeType type)
{
    return false;
}
