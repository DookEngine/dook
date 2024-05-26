# Dook Runtime

[![build](https://github.com/DookEngine/dook/actions/workflows/build.yaml/badge.svg)](https://github.com/DookEngine/dook/actions/workflows/build.yaml)

> [!TIP]
> This is a work-in-progress project.

Dook Engine is a minimalist runtime for 2D sidescroller games.

## Building

We use the meson build system, this uses `cmake` and `ninja` on the
background, it also provides the dependency managment in a easy way.

We use `clang` and `clang++` in MacOS, you may have to install
a more recent version.

On Windows and Linux, we use `gcc` and `g++`.

```sh
pip install meson ninja # The dependencies.
meson setup build # Setup the build directory.
meson compile -c build # Initial compile, also install dependencies
```

This in going to emit an executable under `./build/dook`
