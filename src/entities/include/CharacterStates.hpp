#pragma once
#include <State.hpp>

namespace dook
{
    /**
     * @brief Each character must have these states.
     */
    struct CharacterStates
    {
        State idle;
        State dead;
        State hurting;
        State moving_left;
        State moving_right;
        State attacking;
    };
};
