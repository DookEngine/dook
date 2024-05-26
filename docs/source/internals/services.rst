Services Module
================

Dook is an inherently service based system as mentioned in
:doc:`../development/services`, these classes are how.

=================
Service Locator
=================

.. doxygenclass:: dook::ServiceLocator
    :members:

=========================
Abstract & Null Services
=========================

These services are the ones that need to be extended with
concrete implementations before being used, each has a null
variant which is by default registered to the service locator.

.. doxygenclass:: dook::GraphicsService
    :members:

.. doxygenclass:: dook::InputService
    :members:

.. doxygenclass:: dook::LevelService
    :members:

.. doxygenclass:: dook::LoggerService
    :members:

.. doxygenclass:: dook::NullGraphicsService
.. doxygenclass:: dook::NullInputService
.. doxygenclass:: dook::NullLevelService
.. doxygenclass:: dook::NullLoggerService

================
Common Services
================

Some services are so common accross various domains that,
their concrete implementations are also written in the
module.

.. doxygenclass:: dook::CommonLoggerService
    :members:
