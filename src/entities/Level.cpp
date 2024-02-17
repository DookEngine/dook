#include <Level.hpp>
#include <Character.hpp>

void dook::Level::register_character(std::shared_ptr<dook::Character> character)
{
    if (character->id() == 0)
    {
        this->_main_character = character;
    }
    this->characters.push_back(character);
}

std::shared_ptr<dook::Character> dook::Level::main_character()
{
    return this->_main_character;
}