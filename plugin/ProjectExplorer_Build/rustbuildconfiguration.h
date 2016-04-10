#ifndef RUSTBUILDCONFIGURATION_H
#define RUSTBUILDCONFIGURATION_H

#include <projectexplorer/buildconfiguration.h>

using namespace ProjectExplorer;

class RustBuildConfiguration : public BuildConfiguration
{
    // BuildConfiguration interface
public:
    BuildType buildType() const override;
    RustBuildConfiguration(Target *target, Core::Id id);
    NamedWidget *createConfigWidget() override;

};

#endif // RUSTBUILDCONFIGURATION_H
