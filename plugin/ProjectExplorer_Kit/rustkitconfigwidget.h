#ifndef RUSTKITCONFIGWIDGET_H
#define RUSTKITCONFIGWIDGET_H
#include <projectexplorer/kitconfigwidget.h>
#include <projectexplorer/kit.h>
#include <projectexplorer/kitinformation.h>
#include "rustkitinformation.h"

using namespace ProjectExplorer;

class RustKitConfigWidget : public KitConfigWidget
{
public:
    RustKitConfigWidget(Kit *kit, const RustKitInformation *ki);
    // KitConfigWidget interface
public:
    QString displayName() const override;
    void makeReadOnly() override;
    void refresh() override;
    QWidget *mainWidget() const override;
};

#endif // RUSTKITCONFIGWIDGET_H
