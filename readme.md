# RustyCreator

[![Build status](https://ci.appveyor.com/api/projects/status/23dpy079mn75c50v?svg=true)](https://ci.appveyor.com/project/olivren/rustycreator)

This is a plugin for *QtCreator* (my C++ IDE of choice), to support the *Rust* programming language.

**This project is in its very early stage**. It is not yet useful for anyone, for now I focused on setting thing up correctly.

The primary goals for now are:

1. Allow the user to open a Cargo.toml file as a QtCreator project file.
2. Setup the compile/run targets to use the corresponding Cargo commands
3. Interpret the output of rustc to extract errors/warnings and link them to the files in the editor
4. Provide a project creation wizard, which will be a simple wrapper around Cargo new
5. Tweak various default configurations so that it is easy to work with Rust code out of the box

There is a ton of awesome features I can think of adding in the far future... But if I want to stay realistic, I would say that these 5 basic features are already enough to occupy my somewhat limited free time for a very long period!

## Target Platforms

QtCreator itself is multi-platform. My current main development machine is a *Windows 7 64 bits*, and thus it's what I use for this project. There is of course nothing Windows-specific on this project, so this should work *anywhere QtCreator can run*. The project is based on QtCreator 3.5.0 (open source version).

## Continuous integration

This repository is built using *Appveyor CI*. You can find the full configuration for it in the `appveyor.yml` file. It builds QtCreator and the plugin on Windows using MSVC 2013 and Qt 5.5, targeting x86_64 processors. The result of these builds are available as a zip file, that can be downloaded and run on a 64 bit Windows. Click the "build" button located at the top of this document, and click on the "artifacts" link to access the zip.

## Organization of the repository

This project consists of

1. `qt-creator`, a Hg subrepository that points to the Git QtCreator repository, on the v3.5.0 tag.
2. `plugin`, a QtCreator plugin project.

I configured the plugin's QMake project file so that it knows where to find the sources of QtCreator (`../qt-creator`). Also, QtCreator plugins are by default configured so that they install themselves in the QtCreator build directory.

## Building the project

To avoid a lot of headaches, it is recommended to use the same compiler for all the software stack. So, Qt, QtCreator and the plugin should be compiled with any supported compiler, but it should be the same for all. The CI build use MSVC 2013. I use MSVC 2015 on my development machine (it is free, and can be used for building open source projects).

This is an example of setup:

1. Download and install MSVC 2015
2. Download the sources of Qt 5.5.0
3. Compile Qt

```
CALL "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64
SET PATH=C:\path-to-qt-sources\gnuwin32\bin;%PATH%
.\configure -platform win32-msvc2015 -debug-and-release -opensource -c++11 -confirm-license
nmake
```

4. Add the newly compiled Qt `bin` directory to your path

```
SET PATH=C:\path-to-qt-sources\bin;%PATH%
```

5. Clone this project
6. Go in the qt-creator subdirectory, and compile it

```
qmake
nmake
```

7. Go in the plugin subdirectory, compile

```
qmake
nmake
```

8. Run QtCreator, in qt-creator/bin/qtcreator.exe
9. To checked that the plugin loaded correctly, click on `Help/About plugins`, and see if the `bouillabaisse` plugin is here and checked.
10. Congratulations! Your pull requests are welcome!

## Current state of the project

Besides the project infrastructure setup, I started implementing the first item on my list: interpret a Cargo.toml file as an entry point for a Cargo-based Rust project. When you click `File/Open File or Project`, and if you select a Cargo.toml file, the file will not be opened in the editor as usual. Instead it will create a project node in the "Projects" pane. That's it, you can't do anything with this node yet.