#ifndef RUSTBUILDCONFIGURATIONFACTORY_H
#define RUSTBUILDCONFIGURATIONFACTORY_H

#include <projectexplorer/buildconfiguration.h>

using namespace ProjectExplorer;

class RustBuildConfigurationFactory : public IBuildConfigurationFactory
{
public:
    RustBuildConfigurationFactory();

    // IBuildConfigurationFactory interface
public:
    int priority(const Target *parent) const override;
    QList<BuildInfo *> availableBuilds(const Target *parent) const override;
    int priority(const Kit *k, const QString &projectPath) const override;
    QList<BuildInfo *> availableSetups(const Kit *k, const QString &projectPath) const override;
    BuildConfiguration *create(Target *parent, const BuildInfo *info) const override;
    bool canRestore(const Target *parent, const QVariantMap &map) const override;
    BuildConfiguration *restore(Target *parent, const QVariantMap &map) override;
    bool canClone(const Target *parent, BuildConfiguration *product) const override;
    BuildConfiguration *clone(Target *parent, BuildConfiguration *product) override;
};

#endif // RUSTBUILDCONFIGURATIONFACTORY_H
