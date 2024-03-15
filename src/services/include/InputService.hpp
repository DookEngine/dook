#pragma once
#include <memory>
#include <Command.hpp>

namespace dook
{
    /**
     * @brief This service user input.
     *
     * Fun fact, I planned to implement this in
     * co_await, co_yield. This plan was sadly destroyed
     * when I see the boilerplate to do so, and no, I am
     * NOT adding a library for this purpose.
     */
    class InputService
    {
    public:
        InputService() = default;

        /**
         * @brief Process the next user input.
         *
         * @return A unique ptr that either includes a user input
         * or nullptr if not available.
         * @return false otherwise.
         */
        virtual std::unique_ptr<Command> tick() = 0;

        /**
         * @brief Check if the user have inputted a keycharacter
         * that causes the game to be quit.
         *
         * @return true When user have requested game to quit.
         * @return false Otherwise.
         */
        virtual bool quit() = 0;
        virtual ~InputService() = default;
    };
};
