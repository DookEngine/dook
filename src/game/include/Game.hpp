#pragma once
#include <string>
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
         * @brief Load game data from a file.
         *
         * @param file_path path to the file.
         * @return true If loads correctly.
         * @return false Otherwise.
         */
        bool load_game_data(std::string file_path);

        /**
         * @brief Execute the game mainloop until the user quits.
         *
         * @return true if user quits without problems.
         * @return false if error occurs.
         */
        bool mainloop();
    };
}
