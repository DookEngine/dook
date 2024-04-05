#include <SDLGraphicsService.hpp>
#include <SDLTexture.hpp>
#include <ServiceLocator.hpp>
#include <SDL_image.h>

std::unique_ptr<dook::Texture> dook::SDLGraphicsService::load_texture(std::string filename)
{
    // Obviously more will happen here.
    auto texture = std::make_unique<SDLTexture>(filename);
    texture->surface() = IMG_Load(filename.c_str());
    texture->texture() = SDL_CreateTextureFromSurface(this->renderer, texture->surface());
    texture->set_texture_size({0, 0, 0, 0});
    return texture;
}

void dook::SDLGraphicsService::draw()
{
    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(this->renderer);
    auto objects = ServiceLocator::level().current_level()->objects_within_region(this->viewport());
    SDL_RenderPresent(this->renderer);
}

dook::SDLGraphicsService::~SDLGraphicsService()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

dook::SDLGraphicsService::SDLGraphicsService(dook::Rect screen_size)
{
    ServiceLocator::logger().log("Attempting display service startup...");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        ServiceLocator::logger().error("Video initialization failed.");
        return;
    };

    if (SDL_CreateWindowAndRenderer(screen_size.w, screen_size.h, SDL_WINDOW_RESIZABLE, &this->window, &this->renderer))
    {
        ServiceLocator::logger().error("Window creation failed.");
    }

    ServiceLocator::logger().log("Generated display.");
}
