DEFINES += RUST_LIBRARY

# Rust files

SOURCES += rustplugin.cpp \
    cargoprojectmanager.cpp \
    cargoproject.cpp \
    cargoprojectnode.cpp \
    cargoprojectfile.cpp \
    rusttoolchainfactory.cpp \
    rusttoolchain.cpp \
    rustoutputparser.cpp \
    rusttoolchainconfigwidget.cpp \
    toolautofinder.cpp \
    rustruncontrol.cpp \
    rustrunconfiguration.cpp \
    ProjectExplorer_Build/rustbuildconfiguration.cpp \
    ProjectExplorer_Build/rustbuildconfigurationfactory.cpp \
    ProjectExplorer_Build/rustbuildenvironmentwidget.cpp \
    ProjectExplorer_Kit/rustkitchooser.cpp \
    ProjectExplorer_Kit/rustkitinformation.cpp \
    ProjectExplorer_Kit/rustkitconfigwidget.cpp

HEADERS += rustplugin.h \
        rust_global.h \
        rustconstants.h \
    cargoprojectmanager.h \
    cargoproject.h \
    cargoprojectnode.h \
    cargoprojectfile.h \
    rusttoolchainfactory.h \
    rusttoolchain.h \
    rustoutputparser.h \
    rusttoolchainconfigwidget.h \
    toolautofinder.h \
    rustruncontrol.h \
    rustrunconfiguration.h \
    ProjectExplorer_Build/rustbuildconfiguration.h \
    ProjectExplorer_Build/rustbuildconfigurationfactory.h \
    ProjectExplorer_Build/rustbuildenvironmentwidget.h \
    ProjectExplorer_Kit/rustkitchooser.h \
    ProjectExplorer_Kit/rustkitinformation.h \
    ProjectExplorer_Kit/rustkitconfigwidget.h

# Qt Creator linking

## set the QTC_SOURCE environment variable to override the setting here
QTCREATOR_SOURCES = $$(QTC_SOURCE)
isEmpty(QTCREATOR_SOURCES):QTCREATOR_SOURCES=../qt-creator

## set the QTC_BUILD environment variable to override the setting here
IDE_BUILD_TREE = $$(QTC_BUILD)
isEmpty(IDE_BUILD_TREE):IDE_BUILD_TREE=../qt-creator-build

## uncomment to build plugin into user config directory
## <localappdata>/plugins/<ideversion>
##    where <localappdata> is e.g.
##    "%LOCALAPPDATA%\QtProject\qtcreator" on Windows Vista and later
##    "$XDG_DATA_HOME/data/QtProject/qtcreator" or "~/.local/share/data/QtProject/qtcreator" on Linux
##    "~/Library/Application Support/QtProject/Qt Creator" on Mac
# USE_USER_DESTDIR = yes

###### If the plugin can be depended upon by other plugins, this code needs to be outsourced to
###### <dirname>_dependencies.pri, where <dirname> is the name of the directory containing the
###### plugin's sources.

QTC_PLUGIN_NAME = Rust
QTC_LIB_DEPENDS += \
    # nothing here at this time

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    projectexplorer

QTC_PLUGIN_RECOMMENDS += \
    # optional plugin dependencies. nothing here at this time

###### End _dependencies.pri contents ######

include($$QTCREATOR_SOURCES/src/qtcreatorplugin.pri)

DISTFILES += \
    mimetypes.xml \
    ../dev-doc/classes-uml-diagram.qmodel \
    Rust.json

RESOURCES += \
    Rust.qrc

copy_highlights.target = highlights
copy_highlights.commands = $$QMAKE_COPY $$shell_path(generic-highlighter/*.xml) $$shell_path($$DESTDIR/../../../share/qtcreator/generic-highlighter)
QMAKE_EXTRA_TARGETS += copy_highlights
