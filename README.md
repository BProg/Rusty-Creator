# RustyCreator


This is a plugin for *QtCreator* to support the *Rust*
programming language.

This project was started by Olivier Renaud, his original project can be found
in the [bitbucket](https://bitbucket.org/olivren/rustycreator)

**This project is in its very early stage**. It is not yet useful for anyone,
for now I focused on setting things up correctly.

The primary goals for now are:

1. Allow the user to open a Cargo.toml file as a QtCreator project file.
2. Setup the compile/run targets to use the corresponding Cargo commands
3. Interpret the output of rustc to extract errors/warnings and link them to
   the files in the editor
4. Provide a project creation wizard, which will be a simple wrapper around
   Cargo new
5. Tweak various default configurations so that it is easy to work with Rust
   code out of the box

There is a ton of awesome features I can think of adding in the far future...
But if I want to stay realistic, I would say that these 5 basic features are
already enough to occupy my somewhat limited free time for a very long period!

## Target Platforms

QtCreator itself is multi-platform. My current main development machine is a
*Windows 10 x64*, *Debian 8 x64 stable*, and thus it's what I use for this project.
There is of course nothing Windows-specific on this project, so this should
work *anywhere QtCreator can run*. The project is based on QtCreator 3.5.0
(open source version).

## Continuous integration

Just thinking of integrating with jenkins.

## Organization of the repository

This project consists of

1. `qt-creator`, a git/Hg subrepository that points to the Git QtCreator
   repository, on the v3.5.0 tag.
2. `dev-doc`, some developers-oriented docs.
3. `plugin`, a QtCreator plugin project.
4. `plugin/generic-highlighter`, syntax highlighting files that are copiedto
   the QtCreator install.

I configured the plugin's QMake project file so that it knows where to find the
sources of QtCreator (`../qt-creator`). Also, QtCreator plugins are by default
configured so that they install themselves in the QtCreator build directory.

## Building the project

### Building on Linux(Debian 8)

1) Insall **basic requirements for building Qt applications**.
*Tested only on Debian 8*, but for other distros you can try:

**Debian/Ubuntu (apt-get)**
```sh
sudo apt-get install build-essential libgl1-mesa-dev
```
**Fedora/RHEL/CentOS (yum)**
```sh
sudo yum groupinstall "C Development Tools and Libraries"
sudo yum install mesa-libGL-devel
```
**openSUSE (zypper)**
```sh
sudo zypper install -t pattern devel_basis
```

2) Download and install [QT Community](http://www.qt.io/download/). *At this moment 5.5 version is needed*

3) Clone this project

4) Go to Rusty-Creator subdirectory (QT recomends to create shadow builds)

```sh
mkdir qt-creator-build ; cd qt-creator-build
path/to/QTCommunity/{QT-version}/{Compiler-Version}/bin/qmake -r ../qt-creator
make
```
5) Go to Rusty-Creator/plugin directory

```sh
path/to/QTCommunity/{QT-version}/{Compiler-Version}/bin/qmake
make 
make highlights
```

### Building on OS X

1) Open terminal and type

```sh
xcode-select --install
```
2) Download and install [QT Community](http://www.qt.io/download/). *At this moment 5.5 version is needed*

3) Clone this project

4) Go to Rusty-Creator subdirectory (QT recomends to create shadow builds)

```sh
mkdir qt-creator-build ; cd qt-creator-build
path/to/QTCommunity/{QT-version}/clang_64/bin/qmake -r ../qt-creator
make
````
5) Go  to Rusty-Creator/plugin directory

```sh
path/to/QTCommunity/{QT-version}/clang_64/bin/qmake
make 
make highlights
```
6) Run qt creator located at `qt-creator-build/bin/qtcreator`

7) To check that the plugin loaded correctly, click on `Help/About plugins`,
   and see if the `Rust` plugin appears in the "Other Languages" section, and
   is checked.
   
8) Congratulations! You can now hack some code and send me pull requests!

### Building on Windows (_not tested by me_)

To avoid a lot of headaches, it is recommended to use the same compiler for all
the software stack. So, Qt, QtCreator and the plugin should be compiled with
any supported compiler, but it should be the same for all. The CI build uses
MSVC 2013. I use MSVC 2015 on my development machine (it is free, and can be
used for building open source projects).

This is an example of setup:

1) Download and install MSVC 2015

2) Download the sources of Qt 5.5.0

3) Compile Qt

```bat
CALL "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64
SET PATH=C:\path-to-qt-sources\gnuwin32\bin;%PATH%
.\configure -platform win32-msvc2015 -debug-and-release -opensource -c++11 -confirm-license
nmake
```

4) Add the newly compiled Qt `bin` directory to your path

```bat
SET PATH=C:\path-to-qt-sources\bin;%PATH%
```

5) Clone this project

6) Go in the `qt-creator` subdirectory, and compile it

```bat
qmake
nmake
```

7) Go in the `plugin` subdirectory, compile

```bat
qmake
nmake
nmake highlights
```

8) Run QtCreator, located at `qt-creator/bin/qtcreator.exe`

9) To check that the plugin loaded correctly, click on `Help/About plugins`,
   and see if the `Rust` plugin appears in the "Other Languages" section, and
   is checked.

10) Congratulations! You can now hack some code and send me pull requests!

## Current state of the project

RustyCreator contains exactly the same features as QtCreator opensource, plus
the following enhancements:


* Syntax highlight based on the Kate format:
    * Rust (`*.rs`): it's a cheap way to provide syntax highlight for now
    * Markdown (`*.md`, `*.mmd`, `*.markdown`): often used for readme files
    * Toml (`*.toml`, `Cargo.lock`, `.cargo/config`): used by Cargo
    * Yaml (`*.yml`, `*.yaml`): used for Travis CI and Appveyor CI configuration
    * Json (`*.json`): 'cause it's popular

    Note that I just integrated existing Kate syntax highlight files, I didn't
    write any of them.

* Cargo project files (`Cargo.toml`) are supported as QtCreator project files.
  This means that in `File/Open File of Project`, the user can choose a
  `Cargo.toml` file and the project will be imported into the projects list.

* In the Projects view, a Cargo-based project shows the content of the
  directory where `Cargo.toml` lives, and all its subdirectories. Also, any
  change on the filesystem is reflected automatically in this tree.

* Work in progress: auto-detection and manual creation of Rust compilers, in the
  'Build&Run/Compilers' options tab

## Guide for the contributors

There is a technical overview of the project in [overview.md](dev-doc/overview.md).

## Candidate features list

- ✓✓ = complete support
- ✓ = partial support
- ⋯ = work in progress
- (empty) = not started

| State | Feature                                                      |
|-------|--------------------------------------------------------------|
| ✓✓    | Interpret `Cargo.toml` files as QtCreator project file       |
| ✓✓    | Synchronize the project tree with the filesystem content     |
| ✓✓    | Add generic syntax highlight support                         |
| ✓✓    | Integrate with a Windows CI service (Appveyor)               |
| ✓     | Add `rustc` in the list of compilers                         |
|       | Integrate with a MacOS CI service                            |
|       | Integrate with a Linux CI service                            |
| ✓     | Autodetect `rustc` compilers on the system                   |
|       | Add Cargo as a new build tool                                |
|       | Autodetect `cargo` tools on the system                       |
|       | Add Cargo-specific build step                                |
|       | Add Cargo-specific run step                                  |
|       | Add Cargo-specific deploy step                               |
|       | Auto-generate targets for example bins                       |
|       | Integrate unit tests and benches                             |
|       | Add either an autodetected kit or a default one              |
|       | Add common code snippets                                     |
|       | Support for cross compilation                                |
|       | Real syntax highlight                                        |
|       | Basic text manipulation: auto-close parens, split strings... |
|       | Proper code indentation, based on Rust conventions           |
|       | Customize default code style to match Rust conventions       |
|       | Decorate project/files with the Rust icon!                   |
|       | Provide a more Rusty theme for the UI!                       |
|       | Debugger support                                             |
|       | Code navigation                                              |
|       | Code completion                                              |
|       | find symbols using the Locator                               |
|       | Parse compiler output                                        |
|       | Integrate lints/Clippy, possibly using a QuickFix suggestion |
|       | Handle Cargo sub-projects                                    |
|       | Display/open crate dependencies                              |
|       | UI or autocompletion to work with the Cargo.toml file        |
|       | Inline documentation                                         |
|       | Various wizards                                              |
