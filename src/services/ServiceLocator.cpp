#include <ServiceLocator.hpp>

template <typename TextureType>
std::unique_ptr<dook::ServiceLocator<TextureType>> dook::ServiceLocator<TextureType>::locator(new dook::ServiceLocator());

template <typename TextureType>
void dook::ServiceLocator<TextureType>::provide(std::unique_ptr<dook::LevelService> service)
{
    dook::ServiceLocator::locator->_level = std::move(service);
}

template <typename TextureType>
dook::LevelService &dook::ServiceLocator<TextureType>::level()
{
    return *dook::ServiceLocator::locator->_level;
}
