#include <ServiceLocator.hpp>
#include <Game.hpp>
#include <memory>
#include <CommonLoggerService.hpp>
#include <SDLGraphicsService.hpp>
#include <SDLInputService.hpp>

void dook::Game::tick()
{
    ServiceLocator::input().tick();
    this->_quited = ServiceLocator::input().quit();
    // Render stuff.
    ServiceLocator::graphics().tick();
    // Let objects do their thing.
    ServiceLocator::level().tick();
}

void create_dummy_character();

bool dook::Game::mainloop()
{
    ServiceLocator::logger().log("Starting game mainloop...");
    create_dummy_character();
    while (!this->_quited)
    {
        this->tick();
    }
    ServiceLocator::logger().log("Mainloop terminated.");
    return this->_quited;
}

void create_dummy_character()
{
    dook::State state("standard");
    dook::CharacterStates states{state, state, state, state, state, state};
    dook::CharacterStats stats{
        dook::AIType::CONTROLLED,
        10,
        10,
        5,
        5,
        5,
        0.5,
        2};
    dook::Position position{0, 0};
    auto protogonist = std::make_shared<dook::Character>(
        std::string{"main_character"},
        stats,
        states,
        position);
    auto level = dook::ServiceLocator::level().current_level();
    level->register_character(protogonist);
}

dook::Game::Game() : _quited(false)
{
    ServiceLocator::provide(std::make_unique<CommonLoggerService>());
    ServiceLocator::logger().log("Game startup ongoing...");
    ServiceLocator::logger().log("Registering other services.");
    ServiceLocator::provide(std::make_unique<SDLGraphicsService>());
    ServiceLocator::provide(std::make_unique<SDLInputService>());
    ServiceLocator::logger().log("Game startup completed.");
}
