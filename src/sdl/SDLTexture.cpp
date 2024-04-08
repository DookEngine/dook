#include <SDLTexture.hpp>
#include <ServiceLocator.hpp>
#include <SDL_image.h>

void dook::SDLTexture::set_texture_size(dook::Rect size)
{
    this->_texture_size = size;
}

dook::Rect dook::SDLTexture::texture_size() const
{
    return this->_texture_size;
}

std::shared_ptr<SDL_Texture> dook::SDLTexture::texture()
{
    return this->_texture;
}

std::shared_ptr<SDL_Surface> dook::SDLTexture::surface()
{
    return this->_surface;
}

SDL_Rect dook::SDLTexture::draw_rect_as_sdl() const
{
    SDL_Rect rect;
    rect.x = this->draw_rectangle()->x;
    rect.y = this->draw_rectangle()->y;
    rect.w = this->draw_rectangle()->w;
    rect.h = this->draw_rectangle()->h;
    return rect;
}

dook::SDLTexture::SDLTexture(SDL_Renderer *renderer, std::string filename, Rect draw_rect, Rect animation_step) : Texture(filename, draw_rect, animation_step)
{
    std::shared_ptr<SDL_Surface> surface(IMG_Load(filename.c_str()), dook::SDLSurfaceDeleter{});
    auto error = IMG_GetError();
    if (error != NULL)
    {
        ServiceLocator::logger().error(error);
    }
    std::shared_ptr<SDL_Texture> texture(SDL_CreateTextureFromSurface(renderer, surface.get()), dook::SDLTextureDeleter{});
    this->_surface = surface;
    this->_texture = texture;
    this->set_texture_size(draw_rect);
}
