#pragma once
#include <Character.hpp>
#include <vector>
#include <memory>

namespace dook
{
    /**
     * @brief Holds entities together for processing and parsing.
     *
     */
    struct EntityBundle
    {
        std::vector<std::shared_ptr<Character>> characters;
    };
}
