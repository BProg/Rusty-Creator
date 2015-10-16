#ifndef CARGOPROJECTFILE_H
#define CARGOPROJECTFILE_H

#include "coreplugin/idocument.h"

#include <QString>

namespace Rust {class CargoProject;}

namespace Rust {

class CargoProjectFile : public Core::IDocument
{
    Q_OBJECT

public:
    CargoProjectFile(const QString &fileName);

    // Core::IDocument interface
    virtual bool save(QString *errorString, const QString &fileName, bool autoSave) override;
    virtual QString defaultPath() const override;
    virtual QString suggestedFileName() const override;
    virtual bool isModified() const override;
    virtual bool isSaveAsAllowed() const override;
    virtual bool reload(QString *errorString, ReloadFlag flag, ChangeType type) override;
};
}

#endif
