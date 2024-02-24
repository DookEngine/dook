#include <SDLGraphicsService.hpp>
#include <SDLTexture.hpp>

std::unique_ptr<dook::Texture> dook::SDLGraphicsService::load_texture(std::string filename)
{
    // Obviously more will happen here.
    auto texture = std::make_unique<SDLTexture>(filename);
    texture->set_texture_size({0, 0, 0, 0});
    return texture;
}

void dook::SDLGraphicsService::draw()
{
    // This is where the drawing loop will take place.
    return;
}
