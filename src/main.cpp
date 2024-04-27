#include <Game.hpp>

int main()
{
    dook::Game game;
    game.load_game_data("../resources/resources.json");
    game.mainloop();
}