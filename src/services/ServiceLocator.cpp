#include <ServiceLocator.hpp>

std::unique_ptr<dook::ServiceLocator> dook::ServiceLocator::locator(new dook::ServiceLocator());

void dook::ServiceLocator::provide(std::unique_ptr<dook::LevelService> service)
{
    dook::ServiceLocator::locator->_level = std::move(service);
}

void dook::ServiceLocator::provide(std::unique_ptr<dook::GraphicsService> service)
{
    dook::ServiceLocator::locator->_graphics = std::move(service);
}

void dook::ServiceLocator::provide(std::unique_ptr<dook::LoggerService> service)
{
    dook::ServiceLocator::locator->_logger = std::move(service);
}

void dook::ServiceLocator::provide(std::unique_ptr<dook::InputService> service)
{
    dook::ServiceLocator::locator->_input = std::move(service);
}

dook::LevelService &dook::ServiceLocator::level()
{
    return *dook::ServiceLocator::locator->_level;
}

dook::GraphicsService &dook::ServiceLocator::graphics()
{
    return *dook::ServiceLocator::locator->_graphics;
}

dook::LoggerService &dook::ServiceLocator::logger()
{
    return *dook::ServiceLocator::locator->_logger;
}

dook::InputService &dook::ServiceLocator::input()
{
    return *dook::ServiceLocator::locator->_input;
}
