#include <GraphicsService.hpp>
#include <ServiceLocator.hpp>

dook::Camera &dook::GraphicsService::viewport()
{
    return this->_viewport;
}

const dook::Camera &dook::GraphicsService::viewport() const
{
    return this->_viewport;
}

void dook::GraphicsService::tick()
{
    ServiceLocator::logger().log("Tickin'");
    this->draw();
}
