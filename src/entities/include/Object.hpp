#pragma once
#include <cstdlib>
#include <map>
#include <memory>
#include <Texture.hpp>
#include <Entity.hpp>
#include <EntityType.hpp>
#include <State.hpp>
#include <Audio.hpp>
#include <Command.hpp>

namespace dook
{
    /**
     * @brief Interactable game object.
     *
     * @tparam T Type of the raw textures.
     * @tparam S Type of the raw audio.
     */
    template <class T, class S>
    class Object : public Entity
    {
    private:
        std::map<State, Texture<T>> textures;
        std::map<State, Audio<S>> sounds;
        State current_state;
        State base_state;
        /** Final possible state of the object. */
        State terminal_state;
        /** Distinct from the normal id, used to distinguish between spawned objects. */
        int _instance_id;

    public:
        Object(
            std::string name,
            State base_state,
            State terminal_state,
            SourceInfo source)
            : Entity(name, EntityType::OBJECT, source),
              base_state(base_state),
              terminal_state(terminal_state),
              current_state(base_state),
              _instance_id(std::rand())
        {
        }
        Object(std::string name, State base_state, State terminal_state) : Object(name, base_state, terminal_state, {"", 0})
        {
        }
        /**
         * @brief Execute a command.
         */
        bool execute(const Command &command);

        /**
         * @brief Check if the object is in terminal state with completed anim.
         */
        bool can_remove() const;

        /**
         * @brief Get the current texture of the object.
         */
        Texture<T> &texture() const;

        /**
         * @brief Get the current state of the object.
         */
        const State &state() const;

        /**
         * @brief Perform a tick on an object.
         */
        virtual void tick();
    };
};