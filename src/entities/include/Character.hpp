#pragma once
#include <CharacterStats.hpp>
#include <Object.hpp>
#include <SourceInfo.hpp>
#include <EntityType.hpp>
#include <State.hpp>
#include <CharacterStates.hpp>
#include <Position.hpp>

namespace dook
{
    /**
     * @brief Moving objects that interact with the player.
     *
     * @tparam T Type of their raw texture.
     * @tparam S Type of their raw audio.
     */
    class Character final : public Object
    {
    private:
        CharacterStats _stats;
        CharacterStates _states;
        int ticks_since_last_damage;
        /** Get a modifiable reference to the stats object. */
        CharacterStats &mut_stats() { return _stats; }

    public:
        /**
         * @brief Construct a new Character object
         *
         * @param name Name of the character.
         * @param base_state Base state for the object, initilized and
         * reverts to this state.
         * @param terminal_state When reached, the character is deemed
         * removable.
         * @param stats Stats for character.
         * @param source Information about the entity parse.
         */
        Character(std::string name,
                  CharacterStats stats,
                  CharacterStates states,
                  Position position,
                  SourceInfo source)
            : Object(name,
                     states.idle,
                     states.dead,
                     EntityType::CHARACTER,
                     position,
                     source),
              _stats(stats),
              _states(states) {}
        /**
         * @brief Construct a new Character object
         *
         * @param name Name of the character.
         * @param base_state Base state for the object, initilized and
         * reverts to this state.
         * @param terminal_state When reached, the character is deemed
         * removable.
         * @param stats Stats for character.
         * @param position Position of the character.
         */
        Character(
            std::string name,
            CharacterStats stats,
            CharacterStates states,
            Position position)
            : Character(name,
                        stats,
                        states,
                        position,
                        {"", 0}) {}

        /** Get a readonly reference to the stats object. */
        const CharacterStats &stats() const { return _stats; }
        const CharacterStates &states() const { return _states; }

        virtual void tick() override;

        /**
         * @brief Hurt a character by applying damage.
         *
         * @param damage Damage to be applied to health.
         */
        void hurt(float damage);
    };
};
