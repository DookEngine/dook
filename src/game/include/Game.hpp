#pragma once
namespace dook
{
    /**
     * @brief Encapsulates all the game logic including the mainloop.
     *
     */
    class Game
    {
    private:
        bool _quited;

        /**
         * @brief Execute a single tick of the game mainloop.
         */
        void tick();

    public:
        Game();
        ~Game() = default;

        /**
         * @brief Execute the game mainloop until the user quits.
         *
         * @return true if user quits without problems.
         * @return false if error occurs.
         */
        bool mainloop();
    };
}
