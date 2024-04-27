#pragma once
#include <Character.hpp>
#include <vector>
#include <memory>
#include <string>

namespace dook
{
    /**
     * @brief Holds entities together for processing and parsing.
     *
     */
    struct EntityBundle
    {
        std::vector<std::shared_ptr<Character>> characters;
        std::string first_level;
    };
}
