#include <GraphicsService.hpp>

dook::Rect &dook::GraphicsService::viewport()
{
    return this->_viewport;
}

const dook::Rect &dook::GraphicsService::viewport() const
{
    return this->_viewport;
}

void dook::GraphicsService::tick()
{
    this->draw();
}
