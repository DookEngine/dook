#include <SDLTexture.hpp>

void dook::SDLTexture::set_texture_size(dook::Rect size)
{
    this->_texture_size = size;
}

dook::Rect dook::SDLTexture::texture_size() const
{
    return this->_texture_size;
}
