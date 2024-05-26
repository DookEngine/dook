Setting Up the Development Environment
=======================================

We should probably set up our development environment
before anything else.

You will need to have ``git`` and ``meson`` installed, but
meson build system should take care of the rest.

.. code-block:: bash

    git clone https://github.com/DookEngine/dook.git
    cd dook
    meson setup build
    meson compile -c build

We have downloaded our source code, setup our build directory
and compiled it for the first time. 

Next, I suggest opening your IDE and make sure everything
works as it should.