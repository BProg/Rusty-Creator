#ifndef RUSTBUILDENVIRONMENTWIDGET_H
#define RUSTBUILDENVIRONMENTWIDGET_H

#include <projectexplorer/namedwidget.h>
#include <utils/pathchooser.h>
#include "rustbuildconfiguration.h"

using namespace ProjectExplorer;


class RustBuildEnvironmentWidget : public NamedWidget
{
public:
    RustBuildEnvironmentWidget();
    QString displayName() const;
};

#endif // RUSTBUILDENVIRONMENTWIDGET_H
