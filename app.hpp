#include "gameboard.hpp"
#include "tile.hpp"
#include "frog.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>


class App
{
public:
    App();
    ~App();

    void run(void);

private:
    sf::RenderWindow* window;
    GameBoard *curBoard;

    Frog *frog;

    int checkSaftey(void);

    Tile* getTile(int x_cord, int y_cord);

    void characterAction(sf::Event event);
    void releaseKey(sf::Event event);

};