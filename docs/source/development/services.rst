Working with Services
=====================

Dook closely follows the Service Locator pattern `as laid out by Robert Nystrom <https://gameprogrammingpatterns.com/service-locator.html>`_,

Reasoning behind this is to create a interface for each service,
and then providing correct implementation depending on the targeted
platform and runtime. For instance, :cpp:class:`dook::CommonLoggerService`
may be normally loaded in development, thus providing logs to the command
line, but on production we may substitute it with
:cpp:class:`dook::NullLoggerService`, to shutdown logging alltogether.
Alternatively, we can implement our own logger service which sends data 
over the internet and link it only if we are targeting the web.

.. note::
    This page explains the general principle, if you are looking
    for the specific functions, take a look at the modules reference.

===================
Acessing a Service
===================

Acessor methods of the :cpp:class:`dook::ServiceLocator` is static
and return a reference to the loaded service, or its null variant
if one has not been explicitly loaded.

.. codeblock::cpp

    // Accesses the loaded graphics service and ticks it.
    dook::ServiceLocator::graphics().tick();

======================
Registering a Service
======================

You can register a service using the ``dook::ServiceLocator.register()``
if an overload of this function is provided for the base
virtual service class you have inherited from.

If one does not exist, you will have to override it first, of course.

=============
Null Services
=============
Each of the abstract services have a null variant, this
means each service is insantiated automatically on game start
and the game can be run without some services.