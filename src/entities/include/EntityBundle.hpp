#pragma once
#include <Character.hpp>
#include <Level.hpp>
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
        std::vector<std::shared_ptr<Level>> levels;
        std::string first_level;
    };
}
