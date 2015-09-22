#ifndef CARGOPROJECTNODE_H
#define CARGOPROJECTNODE_H

#include "projectexplorer/projectnodes.h"
#include <QObject>
#include <QString>
#include <QFileInfo>

class QStringList;
class QFileSystemWatcher;
namespace ProjectExplorer { class FolderNode; }

namespace Rust {

class CargoProjectNode : public QObject, public ProjectExplorer::ProjectNode
{
    Q_OBJECT

public:
    CargoProjectNode(const Utils::FileName& projectFilePath);

    virtual bool canAddSubProject(const QString &proFilePath) const override;
    virtual bool addSubProjects(const QStringList &proFilePaths) override;
    virtual bool removeSubProjects(const QStringList &proFilePaths) override;
    virtual QString displayName() const override;

private slots:
    void updateDirectoryContent(const QString&);

private:
    void populateNode(ProjectExplorer::FolderNode* node,
                      const QFileInfoList& excluded,
                      QString dirPath = QString());
    QString projName_;
    QFileSystemWatcher* fsWatcher_;
};

}

#endif
