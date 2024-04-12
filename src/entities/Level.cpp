#include <Level.hpp>
#include <Character.hpp>
#include <algorithm>

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

std::vector<std::shared_ptr<dook::Object>> dook::Level::objects_within_region(const dook::Rect &region)
{
    std::vector<std::shared_ptr<Object>> objects_within;
    // Get a list of objects in range.
    std::copy_if(
        this->objects.begin(),
        this->objects.end(),
        std::back_inserter(objects_within),
        [region](const std::shared_ptr<Object> &object)
        {
            return region.contains(
                object->position().x,
                object->position().y);
        });
    objects_within.push_back(this->main_character());
    return objects_within;
}