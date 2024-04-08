#include <SDLGraphicsService.hpp>
#include <SDLTexture.hpp>
#include <ServiceLocator.hpp>
#include <SDL_image.h>

std::unique_ptr<dook::Texture>
dook::SDLGraphicsService::load_texture(std::string filename, const Rect &draw_rect)
{
    // Obviously more will happen here.
    return std::make_unique<SDLTexture>(this->renderer, filename, draw_rect);
}

std::unique_ptr<dook::Texture> dook::SDLGraphicsService::load_texture(std::string filename)
{
    // TODO: We can get the texture size here.
    return this->load_texture(filename, {0, 0, 0, 0});
}

void dook::SDLGraphicsService::draw()
{
    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(this->renderer);
    auto objects = ServiceLocator::level().current_level()->objects_within_region(this->viewport());
    for (const auto &object : objects)
    {
        auto texture = dynamic_cast<SDLTexture &>(object->texture());
        auto raw_texture = texture.texture();
        SDL_Rect srcrect = texture.draw_rect_as_sdl();
        SDL_Rect destrct{
            0,
            0,
            240,
            360};
        SDL_RenderCopy(
            this->renderer,
            raw_texture.get(),
            &srcrect,
            &destrct);
    }
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
