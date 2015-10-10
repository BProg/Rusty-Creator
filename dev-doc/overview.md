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
and that allowed me to then explore the API by trials and errors.

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
classes start with an `I`. This is the case for `CargoProjectManager`, that
inherits `IProjectManager` and is registered in `rustplugin.cpp` using
`addAutoReleasedObject(new CargoProjectManager)`.

## The Rust plugin

### CargoProjectManager

Opening and managing projects in QtCreator is the job of the `projectexplorer`
plugin. When exploring the
[`projectexplorer`](https://doc-snapshots.qt.io/qtcreator-extending/projectexplorer.html)
API, we see that `IProjectManager` is the entry point for supporting a new kind
of project. Thus, we introduce `CargoProjectManager`, that extends
`ProjectExplorer::IProjectManager` and we create an instance that we register
in the object pool. By virtue of being in the object pool and extending the
correct interface, this instance can be dicsovered and used by
`projectexplorer` to handle Cargo-based projects. There are two important
methods implemented: `mimeType` is a way to tell `projectexplorer` to kick in
when a project file with the MIME type "text/x-cargo.toml" is opened.
`openProject` is the code executed when the project is opened. It creates a new
instance of `CargoProject`.

### CargoProject

`CargoProject` inherits `ProjectExplorer::Project`. An instance of `Project`
represents one opened project in the "Projects" navigator view. The important
method is `rootProjectNode`, that returns the root of the project.

### CargoProjectNode

`CargoProjectNode` inherits `ProjectExplorer::ProjectNode`. In the "Projects"
navigator view, every line in the item tree is backed by a `ProjectNode`. All
items in a Cargo-based project are backed by a `CargoProjectNode`, even the
root. Most of the code in this class is for keeping this tree synchronized to
the content of the filesystem.

### CargoProjectFile

`CargoProjectFile` inherits `Core::IDocument`. This class exists because the
`CargoProject::document` method must return an `IDocument`, and I had to
implement it. I'm not sure where it is used, though.
