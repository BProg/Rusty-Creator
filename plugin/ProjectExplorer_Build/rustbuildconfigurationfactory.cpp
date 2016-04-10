#include "rustbuildconfigurationfactory.h"
#include "rustbuildconfiguration.h"
#include "projectexplorer/buildinfo.h"

RustBuildConfigurationFactory::RustBuildConfigurationFactory()
{

}

int RustBuildConfigurationFactory::priority(const Target *parent) const
{
    return 0;
}

QList<BuildInfo *> RustBuildConfigurationFactory::availableBuilds(const Target *parent) const
{
    QList<BuildInfo*> builds;
    BuildInfo *debugBuild = new BuildInfo(this);
    debugBuild->buildType = BuildConfiguration::BuildType::Debug;
    debugBuild->displayName = QString::fromLatin1("Debug");
    debugBuild->typeName = QString::fromLatin1("Rust Debug");
    builds << debugBuild;
    return builds;
}

int RustBuildConfigurationFactory::priority(const Kit *k, const QString &projectPath) const
{
    return 0;
}

QList<BuildInfo *> RustBuildConfigurationFactory::availableSetups(const Kit *k, const QString &projectPath) const
{
    QList<BuildInfo*> builds;
    BuildInfo *debugBuild = new BuildInfo(this);
    debugBuild->buildType = BuildConfiguration::BuildType::Debug;
    debugBuild->displayName = QString::fromLatin1("Debug");
    debugBuild->typeName = QString::fromLatin1("Rust Debug");
    builds << debugBuild;
    return builds;
}

BuildConfiguration *RustBuildConfigurationFactory::create(Target *parent, const BuildInfo *info) const
{
    return new RustBuildConfiguration(parent, Core::Id::fromString(QString::fromLatin1("RustBuildConfiguration")));
}

bool RustBuildConfigurationFactory::canRestore(const Target *parent, const QVariantMap &map) const
{
    Q_UNUSED(parent);
    Q_UNUSED(map);
    return false;
}

BuildConfiguration *RustBuildConfigurationFactory::restore(Target *parent, const QVariantMap &map)
{
    Q_UNUSED(parent);
    Q_UNUSED(map);
}

bool RustBuildConfigurationFactory::canClone(const Target *parent, BuildConfiguration *product) const
{
    return false;
}

BuildConfiguration *RustBuildConfigurationFactory::clone(Target *parent, BuildConfiguration *product)
{
    return nullptr;
}
