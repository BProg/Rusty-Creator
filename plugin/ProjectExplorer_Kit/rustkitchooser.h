#ifndef RUSTKITCHOOSER_H
#define RUSTKITCHOOSER_H
#include <projectexplorer/kitchooser.h>
#include <projectexplorer/kit.h>

class RustKitChooser : public ProjectExplorer::KitChooser
{
public:
    RustKitChooser();
    ProjectExplorer::Kit* currentKit();
};

#endif // RUSTKITCHOOSER_H
