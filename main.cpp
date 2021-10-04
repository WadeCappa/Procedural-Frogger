#include "gameboard.hpp"
#include "app.hpp"
#include "tile.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>



int main()
{
    srand((unsigned int)time(NULL));

    App game;
    game.run();

    return 0;
}