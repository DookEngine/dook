Manifest Entities
==================

These entities exist inside the game realm and are mostly
loaded from the manifest files one way or another. They all
derieve from the base class :cpp:class:`dook::Entity`.


==================
Base Entity Class
==================

Every single entity inherits this class, this class holds the
general bookkeeping information on entites to keep track of
where they were initiated.

Each entity includes a :cpp:enum:`dook::EntityType` for
easier distinguishing.

Each of these object also often carry a
:cpp:struct:`dook::SourceInfo` field to see where in the manifest
file they are included.

.. doxygenstruct:: dook::SourceInfo
    :members:

.. doxygenenum:: dook::EntityType

.. doxygenclass:: dook::Entity
    :members:

============
Media files
============

Used by object and characters to hold multimedia
info.

.. doxygenclass:: dook::Texture
    :members:

.. doxygenclass:: dook::NullTexture
    :members:

.. doxygenclass:: dook::Audio
    :members:

.. doxygenclass:: dook::NullAudio
    :members:

=====================
Objects & Characters
=====================

Objects & Characters are the moving parts of the engine,
they use the above Entities to interact with each other.

.. doxygenclass:: dook::State
    :members:

.. doxygenclass:: dook::Command
    :members:

.. doxygenclass:: dook::Object
    :members:

.. doxygenstruct:: dook::CharacterStates

.. doxygenstruct:: dook::CharacterStats
    :members:

.. doxygenclass:: dook::Character
    :members:

=======
Levels
=======

Finally, levels tie all of these things together.

.. doxygenclass:: dook::Level
    :members:

