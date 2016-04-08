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
    builds.append(new BuildInfo(this));
    return QList<BuildInfo*>();
}

int RustBuildConfigurationFactory::priority(const Kit *k, const QString &projectPath) const
{
    return 0;
}

QList<BuildInfo *> RustBuildConfigurationFactory::availableSetups(const Kit *k, const QString &projectPath) const
{
    return QList<BuildInfo*>();
}

BuildConfiguration *RustBuildConfigurationFactory::create(Target *parent, const BuildInfo *info) const
{
    return new RustBuildConfiguration(parent, Core::Id::fromString(QString::fromLatin1("RustBuildConfiguration")));
}

bool RustBuildConfigurationFactory::canRestore(const Target *parent, const QVariantMap &map) const
{
    return false;
}

BuildConfiguration *RustBuildConfigurationFactory::restore(Target *parent, const QVariantMap &map)
{
    return nullptr;
}

bool RustBuildConfigurationFactory::canClone(const Target *parent, BuildConfiguration *product) const
{
    return false;
}

BuildConfiguration *RustBuildConfigurationFactory::clone(Target *parent, BuildConfiguration *product)
{
    return nullptr;
}
