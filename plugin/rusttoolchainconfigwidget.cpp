#include "rusttoolchainconfigwidget.h"

#include "rusttoolchain.h"

#include <QComboBox>
#include <QFormlayout>

using namespace ProjectExplorer;
using ReleaseChannel = Rust::RustToolChain::ReleaseChannel;

namespace Rust {

RustToolChainConfigWidget::RustToolChainConfigWidget(ToolChain* toolChain)
    : ToolChainConfigWidget(toolChain),
      releaseChannelCombo_(new QComboBox)
{
    releaseChannelCombo_->addItem(QString::fromLatin1("Stable"),
                                  RustToolChain::ChannelStable);
    releaseChannelCombo_->addItem(QString::fromLatin1("Beta"),
                                  RustToolChain::ChannelBeta);
    releaseChannelCombo_->addItem(QString::fromLatin1("Nightly"),
                                  RustToolChain::ChannelNightly);
    releaseChannelCombo_->addItem(QString::fromLatin1("Unofficial"),
                                  RustToolChain::ChannelUnofficial);
    m_mainLayout->addRow(QString::fromLatin1("Release Channel"),
                         releaseChannelCombo_);
}


void Rust::RustToolChainConfigWidget::applyImpl()
{
    RustToolChain* tc = dynamic_cast<RustToolChain*>(toolChain());
    Q_ASSERT(tc);
    auto chan = ReleaseChannel(releaseChannelCombo_->currentData().toInt());
    tc->setReleaseChannel(chan);
}

void Rust::RustToolChainConfigWidget::discardImpl()
{
}

bool Rust::RustToolChainConfigWidget::isDirtyImpl() const
{
    RustToolChain* tc = dynamic_cast<RustToolChain*>(toolChain());
    Q_ASSERT(tc);
    auto chan = ReleaseChannel(releaseChannelCombo_->currentData().toInt());
    return chan != tc->releaseChannel();
}

void Rust::RustToolChainConfigWidget::makeReadOnlyImpl()
{
    releaseChannelCombo_->setEnabled(false);
}

}
