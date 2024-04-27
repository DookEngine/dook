#include <NullLevelService.hpp>
#include <NullTexture.hpp>
#include <string>

dook::NullLevelService::NullLevelService() : LevelService()
{
    auto bg = std::make_unique<dook::NullTexture>(std::string{"empty"});
    auto fg = std::make_unique<dook::NullTexture>(std::string{"empty"});
    auto ps = std::make_unique<dook::NullTexture>(std::string{"empty"});
    this->set_level(std::make_shared<dook::Level>(
        std::string{"empty"},
        std::move(bg),
        std::move(fg),
        std::move(ps)));
}
