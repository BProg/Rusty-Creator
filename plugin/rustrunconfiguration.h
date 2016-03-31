#ifndef RUSTRUNCONFIGURATION_H
#define RUSTRUNCONFIGURATION_H

#include <projectexplorer/runconfiguration.h>

using namespace ProjectExplorer;

class RustRunConfiguration : public ProjectExplorer::RunConfiguration
{
public:
    RustRunConfiguration(Target *parent, Core::Id id);
};

#endif // RUSTRUNCONFIGURATION_H
