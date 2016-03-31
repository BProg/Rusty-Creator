#ifndef RUSTRUNCONTROL_H
#define RUSTRUNCONTROL_H

#include "rustrunconfiguration.h"
#include <projectexplorer/runconfiguration.h>

using namespace ProjectExplorer;


class RustRunControl : public RunControl
{
public:
    RustRunControl(RustRunConfiguration *runConfiguration, Core::Id mode);
};

#endif // RUSTRUNCONTROL_H
