#ifndef RUSTTOOLCHAINCONFIGWIDGET_H
#define RUSTTOOLCHAINCONFIGWIDGET_H

#include <projectexplorer/toolchainconfigwidget.h>

namespace ProjectExplorer { class ToolChain; }

namespace Rust {

class RustToolChainConfigWidget : public ProjectExplorer::ToolChainConfigWidget
{
    Q_OBJECT
public:
    RustToolChainConfigWidget(ProjectExplorer::ToolChain* toolChain);

    virtual void applyImpl() override;
    virtual void discardImpl() override;
    virtual bool isDirtyImpl() const override;
    virtual void makeReadOnlyImpl() override;
};

}
#endif
