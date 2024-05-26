#pragma once
#include <State.hpp>

namespace dook
{
    /**
     * @brief Each character must have these states.
     *
     * Define which concrete dook::State objects each character's
     * state is assigned to.
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
