# Guide for the contributors

## QtCreator API

This project is mainly a QtCreator plugin. For now, it consists of only C++
code ; there is no Rust code involved, yet!

QtCreator is obviously based on the Qt library, so a minimum knowledge of Qt is
required. The most peculiar aspect being the ownership system: `QObjects` form
hierarchies, where the parents own the children. This is true even for
non-graphical objects. Parents of `QObjects` are often given explicitly, as the
last argument of their constructors. The second important aspect is the
signal/slot mechanism.

[A good entry point for an overview of the core of Qt](http://doc.qt.io/qt-5/topics-core.html)

In this project, most of the work actually consists of understanding the
architecture of QtCreator, and where to plug our own code in.

[An introduction to the plugin-oriented architecture of QtCreator](https://doc-snapshots.qt.io/qtcreator-extending/creating-plugins.html)

[The QtCreator API reference](https://doc-snapshots.qt.io/qtcreator-extending/qtcreator-api.html)

[A more comprehensive guide to writing QtCreator plugins](http://www.vcreatelogic.com/downloads/files/Writing-Qt-Creator-Plugins.pdf)

You will very soon notice that, unlike the Qt API, the QtCreator API is almost
entirely undocumented! This is sad, but fortunately the APIs generally make
sense. So far when I needed to extend an existing plugin, I was able to
implement a minimal set of methods with stub code, that compile and run fine
and that allowed me to then explore the API by trials and errors. These
unimplemented methods are marked with a "STUB" comment, that helps telling
apart the 'minimally implemented' methods from the 'consciously implemented'
ones.

QtCreator is entirely plugin-based. There is actually a super plugin called
`core`, that is the first plugin loaded and all other plugins depend on it. It
manages the toolbars/actions, and it defines the main visual components : the
concept of Modes (Ctrl-1, Ctrl-2, ...), the editor area on the center,
navigators area on the left, help area on the right, the "find" feature, the
global progress bar, the concept of Documents, the Locator (Ctrl-K), the Output
panes on the bottom, and the wizards.

There are two main mechanisms for extending QtCreator.

The first one is to retrieve an existing, singleton-like object, and call
methods on it (or sometime, directly call static methods). This is generally
done directly inside the plugin's entry point (`rusplugin.cpp`), for example
the call to `addMimeTypes` to register new MIME types.

The second one is to inherit some specific classes, that act like plugin
interfaces, and to instanciate and register them to the object pool. These base
classes start with an `I`, with some exceptions. This is the case for
`CargoProjectManager`, that inherits `IProjectManager` and is registered in
`rustplugin.cpp` using `addAutoReleasedObject(new CargoProjectManager)`.

## The Rust plugin

### Support for Cargo-based projects

The first thing we want to teach our plugin is the concept of a Cargo project.
Cargo is the official build tool for Rust projects, and it seems well designed
and well accepted. There is no reason to think that a competing build tool will
appear in the future. Makefiles are sometime used for particular use cases: for
the rustc project that has special boostrapping needs, for cross compilation
setups, and for platforms that don't support Cargo.

This plugin assumes that Rust projects are based on Cargo. QtCreator has the
ability to consider some types of files as project files, based on their mime
types. Thus, the `mimetypes.xml` file defines a MIME type dedicated to
`Cargo.toml` files: "text/x-cargo.toml". The same MIME type string is returned
by the `CargoProjectManager::mimeType` method, so that opening this file in
QtCreator is interpreted as opening a Cargo-based Rust project
(`CargoProjectManager::openProject`).

`CargoProjectManager`, `CargoProject` and `CargoProjectNode` are the three
classes that enable the support for Cargo-based projects. `CargoProjectManager`
creates an instance of `CargoProject` when the user opens a `Cargo.toml` file,
and a `CargoProject` instance has a `CargoProjectNode` to represent the root of
the project tree.

In a QMake-based project, the list of files is determined by `SOURCES` and
`HEADERS` configs in the `.pro` project file. In an 'imported' project, the
list of files is determined by the content of the `.files` file, and files must
be added and removed explicitely by the user. For Cargo-based projects, we
chose to simplify this, and to display the full content of the project (with
some exceptions). It is practical to do so because Cargo-based projects already
clearly separate the source files from the target directory (only sources are
displayed).

For now, we don't extract any information from `Cargo.toml`, but we will in the
future.

It is worth noting that QtCreator automatically stores all the user specific
configurations for a project, in a `Cargo.toml.user` file. This plugin does
nothing special regarding this file.

### Support for Cargo build steps

We want to make it easy to configure Cargo build steps and build targets. The
path to do it correctly is a bit unclear for now, but when in doubt we try to
copy the existing C++ support in QtCreator.

QtCreator has the notion of Kit, which is often the first thing a user needs to
choose when he creates or opens a project. A Kit is a grab-bag of settings,
including the target device, the compiler, the debugger, and the build tool.
Multiple Kits can be choosen for a given project, which will be handy for
letting the user choose his Rust compiler (stable/nightly, or MSVC/MinGW).

Kits are not specializable, so there is no Rust-specific Kit we can create. If
we need more types of settings than what the existing Kit contains, then we
will have to create and register our own subclass of `KitInformation`.

We started our Kit support by introducing the `RustToolChain` class, together
with `RustToolChainManager` (for auto-detecting and manually creating
compilers) and `RustToolChainConfigWidget` (for configuring the Rust
compilers). The base `ToolChain` class is actually thought as implicitly
representing a C++ compiler. But its content is mostly compatible with what we
Rust compiler needs, so it should not be too strange to mix compilers for
multiple languages in a same option tab.

We will need to introduce a way to autodetect and configure Cargo build
systems, in the same fashion as CMake today. Then we will be able to provide
Cargo build steps that use all these informations to build a command string.

### Basic syntax highlight

This is actually not part of the plugin, but as QtCreator supports Kate syntax
highlight configurations, this project provides Rust-related highlight syntax
files gathered from external sources.

A real Rust syntax highlight will be added in the future.
