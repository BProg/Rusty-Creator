#ifndef RUSTKITINFORMATION_H
#define RUSTKITINFORMATION_H

#include <projectexplorer/kitinformation.h>

class RustKitInformation : public ProjectExplorer::KitInformation {

// KitInformation interface
public:
    QVariant defaultValue(ProjectExplorer::Kit *) const override;
    QList<ProjectExplorer::Task> validate(const ProjectExplorer::Kit *) const override;
    void fix(ProjectExplorer::Kit *) override;
    void setup(ProjectExplorer::Kit *) override;
    ItemList toUserOutput(const ProjectExplorer::Kit *) const override;
    ProjectExplorer::KitConfigWidget *createConfigWidget(ProjectExplorer::Kit *kit) const override;
    void addToEnvironment(const ProjectExplorer::Kit *k, Utils::Environment &env) const override;
    ProjectExplorer::IOutputParser *createOutputParser(const ProjectExplorer::Kit *k) const override;
    QString displayNamePostfix(const ProjectExplorer::Kit *k) const override;
    QSet<QString> availablePlatforms(const ProjectExplorer::Kit *k) const override;
    QString displayNameForPlatform(const ProjectExplorer::Kit *k, const QString &platform) const override;
    Core::FeatureSet availableFeatures(const ProjectExplorer::Kit *k) const override;
    void addToMacroExpander(ProjectExplorer::Kit *kit, Utils::MacroExpander *expander) const override;
};

#endif // RUSTKITINFORMATION_H
