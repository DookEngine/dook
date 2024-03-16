#include <Level.hpp>
#include <Character.hpp>

void dook::Level::register_character(std::shared_ptr<dook::Character> character)
{
    if (character->stats().behaviour == AIType::CONTROLLED)
    {
        this->_main_character = character;
    }
    this->characters.push_back(character);
}

std::shared_ptr<dook::Character> dook::Level::main_character()
{
    return this->_main_character;
}

void dook::Level::tick()
{
    for (auto &obj : this->objects)
    {
        obj->tick();
    }

    for (auto &ch : this->characters)
    {
        ch->tick();
    }
}