#pragma once

#include "parentzone.hpp"
#include "tile.hpp"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class GameBoard
{
public:
    GameBoard(sf::RenderWindow* inwin);
    ~GameBoard();

    void drawBoard(void);

    int getDim();
    int getxBound();
    int getyBound();
    int getTotalZones();
    int getZoneSize();

    Tile* fetchTile(int gridX, int gridY);

    friend class App;

protected:
    std::vector<ParentZone*> zones;
    sf::RenderWindow* window;

    int tilePX;

    int xBound;
    int yBound;
    int totalZones;

    
    int zoneSize;

private:

    void genBoard(void);
    ParentZone* genZone(int catagory, int px, int increment);


};
