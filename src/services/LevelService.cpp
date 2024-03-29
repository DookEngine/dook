#include <LevelService.hpp>

void dook::LevelService::set_level(std::shared_ptr<dook::Level> level)
{
    this->_level = level;
}

std::shared_ptr<dook::Level> dook::LevelService::current_level()
{
    return this->_level;
}

void dook::LevelService::tick()
{
    auto level = this->current_level();
    if (level != nullptr)
    {
        // Level encapsulates this behaviour.
        level->tick();
    }
}
