#pragma once
#include <AIType.hpp>

namespace dook
{
    /**
     * @brief Holds information about character behaviour and abilities.
     */
    struct CharacterStats
    {
        /** Determines AI behaviour. */
        AIType behaviour;
        /** Max health this character can hae.*/
        float max_health;
        /** Current character health. */
        float health;
        /** Range in metres this character can detect other characters */
        float detection_range;
        /**
         * @brief Range at which the character can hurt other characters.
         */
        float attack_range;
        /**
         * Amount of attack points, ie: when attacking the other character's
         * health is subtracted by this amount.
         */
        float attack;
        /**
         * Amount of health points recovered per tick
         * when the character have not been damaged for
         * some ticks.
         */
        float health_recovery_per_tick;
        /**
         * @brief Walking speed of the character.
         */
        float speed;
    };
};