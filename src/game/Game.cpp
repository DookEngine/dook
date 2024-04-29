#include <ServiceLocator.hpp>
#include <Game.hpp>
#include <memory>
#include <CommonLoggerService.hpp>
#include <SDLGraphicsService.hpp>
#include <SDLInputService.hpp>
#include <SDLTexture.hpp>
#include <JSONParserService.hpp>

void dook::Game::tick()
{
    ServiceLocator::input().tick();
    this->_quited = ServiceLocator::input().quit();
    // Render stuff.
    ServiceLocator::graphics().tick();
    // Let objects do their thing.
    ServiceLocator::level().tick();
}

bool dook::Game::mainloop()
{
    ServiceLocator::logger().log("Starting game mainloop...");
    while (!this->_quited)
    {
        this->tick();
    }
    ServiceLocator::logger().log("Mainloop terminated.");
    return this->_quited;
}

dook::Game::Game() : _quited(false)
{
    ServiceLocator::provide(std::make_unique<CommonLoggerService>());
    ServiceLocator::logger().log("Game startup ongoing...");
    ServiceLocator::logger().log("Registering other services.");
    ServiceLocator::provide(std::make_unique<SDLGraphicsService>());
    ServiceLocator::provide(std::make_unique<SDLInputService>());
    ServiceLocator::provide(std::make_unique<JSONParserService>());
    ServiceLocator::logger().log("Game startup completed.");
}

/**
 * @brief Load the data of a game.
 *
 * @param file_path Path to the manifest file.
 * @return true Load if it is true.
 * @return false Otherwise.
 */
bool dook::Game::load_game_data(std::string file_path)
{
    auto entity_bundle = ServiceLocator::parser().load_manifest(file_path);
    auto level = ServiceLocator::parser().switch_level(entity_bundle.first_level);
    ServiceLocator::level().load_level(level);
    return true;
}
