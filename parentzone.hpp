#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "tile.hpp"


class ParentZone
{
public:
    ParentZone(int xGrid, int yGrid);
    ~ParentZone();

    void setTiles(char nT, char hT, char haz);
    void setPositions(int px, int zoneIncrement);

    void handleHazard(void);

    void drawZone(int px, sf::RenderWindow* window, int zoneIncrement);
    
    virtual void genZone(int px, int zoneIncrement);

    friend class GameBoard;
    friend class App;


protected:
    std::vector<std::vector<Tile*>> zoneBoard;

    int xBound;
    int yBound;
    
    char nTile;
    char hTile;
    char hazard;


    

    
};