#include "rusttoolchainconfigwidget.h"

using namespace ProjectExplorer;

namespace Rust {

RustToolChainConfigWidget::RustToolChainConfigWidget(ToolChain* toolChain)
    : ToolChainConfigWidget(toolChain)
{

}


void Rust::RustToolChainConfigWidget::applyImpl()
{
}

void Rust::RustToolChainConfigWidget::discardImpl()
{
}

bool Rust::RustToolChainConfigWidget::isDirtyImpl() const
{
    return false;
}

void Rust::RustToolChainConfigWidget::makeReadOnlyImpl()
{
}

}
