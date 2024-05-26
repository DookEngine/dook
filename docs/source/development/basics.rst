Basics
========================


======================
Build System Overview
======================

Dook uses the ``meson`` build system to fetch and manage
dependencies, in addition, each subfolder in the `src/`
directory is a different library, this allows us to link
some but not all of them, which is useful in case we don't
want to add in sdl support or json parsing and substitute them
with other technologies.

To support this, dook makes use of a service locator infrastructure,
that way we can write code without thinking about external dependencies.
(for instance we can say `ServiceLocator::graphics().draw()`) without
knowing which specific drawing backend is being used, more info
on this can be found in :doc:`services`.

=================
Coding standards
=================

Dook code tries to use modern C++ coding standards, namely,
we avoid using raw pointers and model resource acqusition
using smart pointers and try to use RAII.

We use C++ 20 as the standard, and try to stay compatible with
gcc and clang, these are tested in each push by our CI.

