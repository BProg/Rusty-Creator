#include "rustbuildenvironmentwidget.h"
#include <QFormLayout>
#include <QSettings>
#include <utils/pathchooser.h>
#include <projectexplorer/target.h>
#include <projectexplorer/project.h>


RustBuildEnvironmentWidget::RustBuildEnvironmentWidget()
{
    NamedWidget::setDisplayName(QString::fromLatin1("Rust Build Configuration"));
}

