#include "rustbuildconfiguration.h"
#include <projectexplorer/buildenvironmentwidget.h>

#include <projectexplorer/buildconfiguration.h>

BuildConfiguration::BuildType RustBuildConfiguration::buildType() const
{
    return BuildConfiguration::BuildType::Debug;
}

RustBuildConfiguration::RustBuildConfiguration(Target *target, Core::Id id) : BuildConfiguration(target, id)
{

}

NamedWidget *RustBuildConfiguration::createConfigWidget()
{
    return new BuildEnvironmentWidget(this);
}
