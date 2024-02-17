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
#include <Position.hpp>

namespace dook
{
    class Object : public Entity
    {
    private:
        std::map<State, Texture> textures;
        std::map<State, Audio> sounds;
        State current_state;
        State base_state;
        /** Final possible state of the object. */
        State terminal_state;
        Position _position;
        /** Distinct from the normal id, used to distinguish between spawned objects. */
        int _instance_id;

    protected:
        Object(std::string name,
               State base_state,
               State terminal_state,
               EntityType type,
               Position position,
               SourceInfo source)
            : Entity(name, type, source),
              base_state(base_state),
              terminal_state(terminal_state),
              current_state(base_state),
              _instance_id(std::rand()),
              _position(position) {}

        /**
         * @brief Set the object to new state.
         *
         * @param state State to set to.
         * @return true if the state has a texture equivalent and
         * in general settable.
         * @return false otherwise.
         */
        bool set_state(const State &state);

    public:
        /**
         * @brief Construct a new Object object
         *
         * @param name Name of the object.
         * @param base_state Base state of the object, initilizes as this
         * and eventually reverts to this when, if, the time comes.
         * @param terminal_state When reached, object is determined
         * to be removable.
         * @param position The location of the object in 2D space.
         * @param source Information about the parsing source for this
         * object.
         */
        Object(
            std::string name,
            State base_state,
            State terminal_state,
            Position position,
            SourceInfo source)
            : Object(name,
                     base_state,
                     terminal_state,
                     EntityType::OBJECT,
                     position,
                     source)
        {
        }
        /**
         * @brief Construct a new Object object
         *
         * @param name Name of the object.
         * @param base_state Base state of the object, initilizes as this
         * and eventually reverts to this when, if, the time comes.
         * @param terminal_state When reached, object is determined
         * @param position Position of the object in 2D space.
         * to be removable.
         */
        Object(
            std::string name,
            State base_state,
            State terminal_state,
            Position position)
            : Object(
                  name,
                  base_state,
                  terminal_state,
                  position,
                  {"", 0})
        {
        }
        /**
         * @brief Execute a command.
         */
        virtual bool execute(const Command &command);

        /**
         * @brief Check if the object is in terminal state with completed anim.
         */
        bool can_remove() const;

        /**
         * @brief Get the current texture of the object.
         */
        const Texture &texture() const;

        /**
         * @brief Get a modifiable reference to the current texture.
         *
         * @return Texture& texture reference.
         */
        Texture &texture();

        /**
         * @brief Get the current state of the object.
         */
        const State &state() const;

        /**
         * @brief Perform a tick on an object.
         */
        virtual void tick();

        /**
         * @brief Reset the object to its initial state.
         */
        void reset();

        /**
         * @brief Check if the object is at base state.
         *
         * @return true
         * @return false
         */
        bool at_base_state();

        /**
         * @brief Get the object position.
         *
         * @return Position& Pass the object position by reference.
         */
        Position &position();
    };
};