#include <SDLTexture.hpp>
#include <ServiceLocator.hpp>
#include <SDL_image.h>

struct SDLDeleter
{
    void operator()(SDL_Surface *surface)
    {
        SDL_FreeSurface(surface);
    }

    void operator()(SDL_Texture *texture)
    {
        SDL_DestroyTexture(texture);
    }
};

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

dook::SDLTexture::SDLTexture(SDL_Renderer *renderer, std::string filename, Rect draw_rect) : Texture(filename, draw_rect)
{
    std::shared_ptr<SDL_Surface> surface(IMG_Load(filename.c_str()), SDLDeleter{});
    auto error = IMG_GetError();
    if (error != NULL)
    {
        ServiceLocator::logger().error(error);
    }
    std::shared_ptr<SDL_Texture> texture(SDL_CreateTextureFromSurface(renderer, surface.get()), SDLDeleter{});
    this->_surface = surface;
    this->set_texture_size(Rect{
        0,
        0,
        (float)this->_surface->w,
        (float)this->_surface->h});

    if (this->draw_rectangle().value().w < this->_surface->w)
    {
        // When the draw rectangle is smaller than the image itself
        // that means the image is animated on the x-axes.
        this->_animation_step.emplace(Rect{
            0,
            0,
            (float)this->draw_rectangle().value().w,
            0});
    }
    this->_texture = texture;
}
