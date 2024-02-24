#include <GraphicsService.hpp>

template <typename TextureType>
dook::Rect &dook::GraphicsService<TextureType>::viewport()
{
    return this->_viewport;
}

template <typename TextureType>
const dook::Rect &dook::GraphicsService<TextureType>::viewport() const
{
    return this->_viewport;
}

template <typename TextureType>
void dook::GraphicsService<TextureType>::tick()
{
    this->draw();
}
