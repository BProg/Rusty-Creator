#include "rustkitinformation.h"
#include "../rustoutputparser.h"
#include "projectexplorer/kitconfigwidget.h"
#include "rustkitconfigwidget.h"

using namespace Rust;

QVariant RustKitInformation::defaultValue(ProjectExplorer::Kit *) const
{
    return QVariant(0);
}

QList<ProjectExplorer::Task> RustKitInformation::validate(const ProjectExplorer::Kit *) const
{
    return QList<ProjectExplorer::Task>();
}

void RustKitInformation::fix(ProjectExplorer::Kit *)
{

}

void RustKitInformation::setup(ProjectExplorer::Kit *)
{

}

ProjectExplorer::KitInformation::ItemList RustKitInformation::toUserOutput(const ProjectExplorer::Kit *) const
{
    return ProjectExplorer::KitInformation::ItemList();
}

ProjectExplorer::KitConfigWidget *RustKitInformation::createConfigWidget(ProjectExplorer::Kit *kit) const
{
    return new RustKitConfigWidget(kit, this);
}

void RustKitInformation::addToEnvironment(const ProjectExplorer::Kit *k, Utils::Environment &env) const
{

}

ProjectExplorer::IOutputParser *RustKitInformation::createOutputParser(const ProjectExplorer::Kit *k) const
{
    return new RustOutputParser();
}

QString RustKitInformation::displayNamePostfix(const ProjectExplorer::Kit *k) const
{
    return QString::fromLatin1("postfix");
}

QSet<QString> RustKitInformation::availablePlatforms(const ProjectExplorer::Kit *k) const
{
    return k->availablePlatforms();
}

QString RustKitInformation::displayNameForPlatform(const ProjectExplorer::Kit *k, const QString &platform) const
{
    return QString::fromLatin1("platform to show");
}

Core::FeatureSet RustKitInformation::availableFeatures(const ProjectExplorer::Kit *k) const
{
    return k->availableFeatures();
}

void RustKitInformation::addToMacroExpander(ProjectExplorer::Kit *kit, Utils::MacroExpander *expander) const
{

}
