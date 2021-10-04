#include "gameboard.hpp"
#include "vector"
#include "roadzone.hpp"
#include "logzone.hpp"
#include "trainzone.hpp"
#include "boatzone.hpp"
#include "endzone.hpp"



GameBoard::GameBoard(sf::RenderWindow* inwin)
{
    window = inwin;
    tilePX = 20;
    zoneSize = 5;

    yBound = int(window->getSize().y / tilePX);
    xBound = int(window->getSize().x / tilePX);

    totalZones = int(yBound / zoneSize);

    if (yBound % zoneSize == 0)
    {
        totalZones--;
    }
    
    genBoard();
}


GameBoard::~GameBoard()
{
    for (int increment = 0; increment < totalZones; increment++)
    {
        delete zones[increment];
    }
}





void GameBoard::genBoard(void)
{
    //zones.push_back(new EndZone(xBound, 2, tilePX, 0));

    for (int increment = 0; increment < totalZones; increment++)
    {
        zones.push_back(genZone(rand() % 4, tilePX, increment));
    }

    totalZones++;
    zones.push_back(new EndZone(xBound, zoneSize, tilePX, totalZones - 1));

}



ParentZone* GameBoard::genZone(int catagory, int px, int increment)
{
    switch (catagory)
    {
        case 0:
            return new RoadZone(xBound, zoneSize, px, increment);
            break;
            
        case 1:
            return new LogZone(xBound, zoneSize, px, increment);
            break;
            
        case 2:
            return new TrainZone(xBound, zoneSize, px, increment);
            break;
            
        case 3:
            return new BoatZone(xBound, zoneSize, px, increment);
            break;

    }
}



void GameBoard::drawBoard(void)
{
    for (int increment = 0; increment < totalZones; increment++)
    {
        //std::cout << "started Zone" << std::endl;

        zones[increment]->drawZone(tilePX, window, increment);

        //std::cout << "Finished Zone" << std::endl;
    }
}





int GameBoard::getDim()
{
    return tilePX;
}


int GameBoard::getxBound()
{
    return xBound;
}



int GameBoard::getyBound()
{
    return yBound;
}



int GameBoard::getTotalZones()
{
    return totalZones;
}



int GameBoard::getZoneSize()
{
    return zoneSize;
}



Tile* GameBoard::fetchTile(int gridX, int gridY)
{
    int curZone = int(gridY / zoneSize);
    std::cout << " " << curZone << " " << gridX << " " << gridY << " " << gridY % zoneSize << std::endl;
    std::cout << totalZones << std::endl;
    std::cout << zones[curZone]->zoneBoard[gridX][gridY % zoneSize]->getVal() << std::endl;
    return zones[curZone]->zoneBoard[gridX][gridY % zoneSize];
}