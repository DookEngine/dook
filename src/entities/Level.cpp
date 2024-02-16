#include <Level.hpp>
#include <Character.hpp>

template <class T, class S>
void dook::Level<T, S>::register_character(std::shared_ptr<Character<T, S>> character)
{
    if (character->id == 0)
    {
        this->_main_character = character;
    }
    this->characters.push_back(character);
}

template <class T, class S>
std::shared_ptr<dook::Character<T, S>> dook::Level<T, S>::main_character()
{
    return this->_main_character;
}