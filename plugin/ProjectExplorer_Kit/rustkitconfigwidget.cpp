#include "rustkitconfigwidget.h"
#include <QWidget>




RustKitConfigWidget::RustKitConfigWidget(Kit *kit, const RustKitInformation *ki) : KitConfigWidget(kit, ki)
{

}

QString RustKitConfigWidget::displayName() const
{
    return QString::fromLatin1("--Rust KLit<--");
}

void RustKitConfigWidget::makeReadOnly()
{

}

void RustKitConfigWidget::refresh()
{

}

QWidget *RustKitConfigWidget::mainWidget() const
{
    return new QWidget();
}
