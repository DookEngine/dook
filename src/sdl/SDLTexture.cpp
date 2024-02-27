#include <SDLTexture.hpp>

void dook::SDLTexture::set_texture_size(dook::Rect size)
{
    this->_texture_size = size;
}

dook::Rect dook::SDLTexture::texture_size() const
{
    return this->_texture_size;
}

dook::SDLTexture::~SDLTexture()
{
    SDL_DestroyTexture(this->_texture);
    SDL_FreeSurface(this->_surface);
}

SDL_Texture *&dook::SDLTexture::texture()
{
    return this->_texture;
}

SDL_Surface *&dook::SDLTexture::surface()
{
    return this->_surface;
}
