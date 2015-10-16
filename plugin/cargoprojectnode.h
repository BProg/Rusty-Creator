#ifndef CARGOPROJECTNODE_H
#define CARGOPROJECTNODE_H

#include "projectexplorer/projectnodes.h"
#include <QObject>
#include <QString>
#include <QFileInfoList>
#include "utils/fileutils.h"

class QStringList;
class QFileSystemWatcher;
namespace ProjectExplorer { class FolderNode; }

namespace Rust {

class CargoProjectNode : public QObject, public ProjectExplorer::ProjectNode
{
    Q_OBJECT

public:
    CargoProjectNode(const Utils::FileName& projectFilePath);

    // ProjectExplorer::ProjectNode interface
    virtual bool canAddSubProject(const QString &proFilePath) const override;
    virtual bool addSubProjects(const QStringList &proFilePaths) override;
    virtual bool removeSubProjects(const QStringList &proFilePaths) override;
    virtual QString displayName() const override;

private slots:
    void updateDirContent(const QString&);

private:
    const Utils::FileName& realDir(FolderNode* node);
    enum SearchState { SearchStop, SearchContinue };
    SearchState updateDirContentRecursive(FolderNode* node, const Utils::FileName& dir);
    void updateFilesAndDirs(FolderNode* node);
    void updateFiles(FolderNode* node);
    void updateDirs(FolderNode* node);
    void populateNode(ProjectExplorer::FolderNode* node);
    Utils::FileName projDir_;
    QString projName_;
    QFileSystemWatcher* fsWatcher_;
    QFileInfoList excludedPaths_;
};

}

#endif
