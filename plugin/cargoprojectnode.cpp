 #include "cargoprojectnode.h"

#include <QFileInfo>
#include <QDir>
#include <QFileInfoList>
#include <QFileSystemWatcher>
#include <projectexplorer/projectnodes.h>

using namespace Rust;
using namespace Utils;
using namespace ProjectExplorer;

// `projectFilePath` is the path of the Cargo.toml file. It can be seen in the
// tooltip attached to the project explorer's root item.
//
CargoProjectNode::CargoProjectNode(const FileName& projectFilePath)
    : ProjectExplorer::ProjectNode(projectFilePath),
      fsWatcher_(new QFileSystemWatcher(this))
{
    // Hack: `QFileSystemWatcher` does not work well on Windows. When a folder
    // is being watched, and if the user tries to delete its parent directory
    // using the Windows file explorer, then a "Folder access denied" error appears
    // and the folder cannot be deleted.
    //
    // To work around the problem, we force `QFileSystemWatcher` to use the
    // polling strategy (as opposed to the native filesystem watching API),
    // which is more resource intensive and less reactive, but does not cause
    // this problem.
    //
    // https://bugreports.qt.io/browse/QTBUG-2331
    // https://bugreports.qt.io/browse/QTBUG-38118
    // https://bugreports.qt.io/browse/QTBUG-7905
    //
    #ifdef Q_OS_WIN
    fsWatcher_->setObjectName(QString::fromLatin1("_qt_autotest_force_engine_poller"));
    #endif

    connect(fsWatcher_, SIGNAL(directoryChanged(QString)),
            this, SLOT(updateDirContent(QString)));

    projDir_ = projectFilePath.parentDir();
    projName_ = projDir_.fileName();
    QDir mainDir = QDir(projDir_.toString());
    excludedPaths_ << QFileInfo(mainDir, QString::fromLatin1("target"))
                   << QFileInfo(mainDir, QString::fromLatin1(".hg"))
                   << QFileInfo(mainDir, QString::fromLatin1(".git"))
                   << QFileInfo(mainDir, QString::fromLatin1(".svn"))
                   << QFileInfo(mainDir, QString::fromLatin1(".darcs"));
    populateNode(this);
}

bool CargoProjectNode::canAddSubProject(const QString &proFilePath) const
{
    Q_UNUSED(proFilePath)
    // STUB
    return false;
}

bool CargoProjectNode::addSubProjects(const QStringList &proFilePaths)
{
    Q_UNUSED(proFilePaths)
    // STUB
    return false;
}

bool CargoProjectNode::removeSubProjects(const QStringList &proFilePaths)
{
    Q_UNUSED(proFilePaths)
    // STUB
    return false;
}

// The name displayed on the project explorer's root item.
QString CargoProjectNode::displayName() const
{
    return projName_;
}

void CargoProjectNode::updateDirContent(const QString & dir) {
    updateDirContentRecursive(this, FileName::fromString(dir));
}

const FileName& CargoProjectNode::realDir(FolderNode* node) {
    return (node->asProjectNode())
            ? projDir_
            : node->path();
}

CargoProjectNode::SearchState
CargoProjectNode::updateDirContentRecursive(FolderNode* node,
                                            const FileName& dir)
{
    FileName currentDir = realDir(node);
    if(dir == currentDir) {
        updateFilesAndDirs(node);
        return SearchStop;
    }
    if(dir.isChildOf(currentDir)) {
        for(FolderNode* subDir: node->subFolderNodes()) {
            SearchState state = updateDirContentRecursive(subDir, dir);
            if(state == SearchStop)
                return SearchStop;
        }
    }
    return SearchContinue;
}

void CargoProjectNode::updateFilesAndDirs(FolderNode* node) {
    updateFiles(node);
    updateDirs(node);
}

void CargoProjectNode::updateFiles(FolderNode* node) {
    QSet<FileName> knownFiles;
    QMap<FileName, FileNode*> knownFilesWithNodes;
    {
        for(FileNode* f: node->fileNodes()) {
            knownFiles << f->path();
            knownFilesWithNodes.insert(f->path(), f);
        }
    }

    QSet<FileName> allFiles;
    {
        for (QFileInfo sub: QDir(realDir(node).toString()).entryInfoList(QDir::Files)) {
            if(excludedPaths_.contains(sub))
                continue;
            else
                allFiles << FileName(sub);
        }
    }

    QSet<FileName> newFiles = allFiles - knownFiles;
    QSet<FileName> obsoleteFiles = knownFiles - allFiles;

    QList<FileNode*> fileNodesToAdd;
    {
        for(const FileName& f: newFiles)
            fileNodesToAdd << new FileNode(FileName(f), UnknownFileType, false);
    }
    node->addFileNodes(fileNodesToAdd);

    QList<FileNode*> fileNodesToRemove;
    {
        for(const FileName& f: obsoleteFiles)
            fileNodesToRemove << knownFilesWithNodes[f];
    }
    node->removeFileNodes(fileNodesToRemove);
}

void CargoProjectNode::updateDirs(FolderNode* node) {
    QSet<FileName> knownDirs;
    QMap<FileName, FolderNode*> knownDirsWithNodes;
    {
        for(FolderNode* f: node->subFolderNodes()) {
            knownDirs << f->path();
            knownDirsWithNodes.insert(f->path(), f);
        }
    }

    QSet<FileName> allDirs;
    {
        for (QFileInfo sub: QDir(realDir(node).toString()).entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
            if(excludedPaths_.contains(sub))
                continue;
            else
                allDirs << FileName(sub);
        }
    }

    QSet<FileName> newDirs = allDirs - knownDirs;
    QSet<FileName> obsoleteDirs = knownDirs - allDirs;

    QList<FolderNode*> folderNodesToAdd;
    {
        for(const FileName& f: newDirs)
            folderNodesToAdd << new FolderNode(FileName(f), FolderNodeType, f.fileName());
    }
    node->addFolderNodes(folderNodesToAdd);
    for(FolderNode* newDir: folderNodesToAdd)
        populateNode(newDir);

    QList<FolderNode*> folderNodesToRemove;
    {
        for(const FileName& f: obsoleteDirs)
            folderNodesToRemove << knownDirsWithNodes[f];
    }
    node->removeFolderNodes(folderNodesToRemove);
}

void CargoProjectNode::populateNode(FolderNode* node)
{
    Q_ASSERT(node->fileNodes().empty() && node->subFolderNodes().empty());

    QString dirPath = realDir(node).toString();

    fsWatcher_->addPath(dirPath);

    QList<FolderNode*> subDirs;
    QList<FileNode*> subFiles;

    for (QFileInfo sub: QDir(dirPath).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
        if(excludedPaths_.contains(sub))
            continue;
        else if(sub.isDir())
            subDirs << new FolderNode(FileName(sub), FolderNodeType, sub.fileName());
        else
            subFiles << new FileNode(FileName(sub), UnknownFileType, false);
    }

    node->addFolderNodes(subDirs);
    node->addFileNodes(subFiles);

    for (FolderNode* subDir : subDirs)
        populateNode(subDir);
}
