#include <ServiceLocator.hpp>

std::unique_ptr<dook::ServiceLocator> dook::ServiceLocator::locator(new dook::ServiceLocator());

void dook::ServiceLocator::provide(std::unique_ptr<dook::LevelService> service)
{
    dook::ServiceLocator::locator->_level = std::move(service);
}

dook::LevelService &dook::ServiceLocator::level()
{
    return *dook::ServiceLocator::locator->_level;
}
