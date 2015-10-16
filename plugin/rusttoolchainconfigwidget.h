#ifndef RUSTTOOLCHAINCONFIGWIDGET_H
#define RUSTTOOLCHAINCONFIGWIDGET_H

#include <projectexplorer/toolchainconfigwidget.h>

class QComboBox;
namespace ProjectExplorer { class ToolChain; }

namespace Rust {

class RustToolChainConfigWidget : public ProjectExplorer::ToolChainConfigWidget
{
    Q_OBJECT
public:
    RustToolChainConfigWidget(ProjectExplorer::ToolChain* toolChain);

    // ProjectExplorer::ToolChainConfigWidget interface
    virtual void applyImpl() override;
    virtual void discardImpl() override;
    virtual bool isDirtyImpl() const override;
    virtual void makeReadOnlyImpl() override;

private:
    QComboBox* releaseChannelCombo_;
};

}
#endif
