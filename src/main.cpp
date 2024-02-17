#include <Rect.hpp>
#include <iostream>
#include <Level.hpp>
#include <Texture.hpp>
#include <Audio.hpp>

int main()
{
    auto bg = std::make_unique<dook::Texture>(std::string{"file.png"});
    auto fg = std::make_unique<dook::Texture>(std::string{"file.png"});
    auto ps = std::make_unique<dook::Texture>(std::string{"file.png"});
    // Generate empty level.
    dook::Level level(
        std::string{"Sample"},
        std::move(bg),
        std::move(fg),
        std::move(ps));
}