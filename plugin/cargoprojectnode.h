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

/// Represents a root of a project, in the "Projects" navigator view. Under
/// this root, there are regular (non subclassed) `FolderNode` and `FileNode`
/// nodes.
///
/// Except for the root, all nodes represent real directories and files. The
/// content of the tree is a 1:1 view of the filesystem content, and is
/// synchronized using a `QFileSystemWatcher`.
///
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

    /// This slot is connected to the `QFileSystemWatcher::directoryChanged`
    /// signal. One signal/slot connection exists for each node that represents
    /// a directory in the tree.
    ///
    /// It modifies the tree content so that the nodes match the content of the
    /// filesystem.
    ///
    void updateDirContent(const QString&);

private:

    /// Almost all `FolderNode` nodes represent a directory, and their
    /// `ProjectNode::path` method returns the path of this directory. The
    /// exception is the root node, whose `path` method returns the Cargo.toml
    /// file path.
    ///
    /// In many circumstances, we want to consider the root just like a regular
    /// directory node, whose path is the Cargo.toml's parent directory. That's
    /// what this method does.
    ///
    const Utils::FileName& realDir(FolderNode* node);

    enum SearchState { SearchStop, SearchContinue };

    /// Implementation detail of `updateDirContent`. It searches recursively in
    /// the tree, for the node whose `path` matches the one that changed.
    ///
    /// Returns `SearchStop` to signal that the one matching directory was
    /// found, and thus indicate that the recursion must stop.
    ///
    SearchState updateDirContentRecursive(FolderNode* node, const Utils::FileName& dir);

    /// Calls `updateFiles` and `updateDirs`
    ///
    void updateFilesAndDirs(FolderNode* node);

    /// Perform a diff between the `FileNode` children that are already known,
    /// and the files on the filesystem. Add or remove nodes accordingly.
    ///
    /// Ignores the paths listed in `excludedPaths_`.
    ///
    void updateFiles(FolderNode* node);

    /// Perform a diff between the `FolderNode` children that are already
    /// known, and the subdirectories on the filesystem. Add or remove nodes
    /// accordingly.
    ///
    /// Ignores the paths listed in `excludedPaths_`.
    ///
    void updateDirs(FolderNode* node);

    /// Called with an empty FolderNode as an argument, to recursively populate
    /// its content based on the filesystem content.
    ///
    /// This method is also responsible for adding the path of the node to the
    /// list of the directories watched by the `QFileSystemWatcher`.
    ///
    void populateNode(ProjectExplorer::FolderNode* node);

    /// Absolute path to the project's root directory
    ///
    Utils::FileName projDir_;

    /// Simple name of the project's root directory
    ///
    QString projName_;

    /// The watcher used to watch the full tree hierarchy. Owned by
    /// `CargoProjectNode`.
    ///
    QFileSystemWatcher* fsWatcher_;

    /// List of absolute paths we don't want to display in the tree.
    ///
    QFileInfoList excludedPaths_;
};

}

#endif
