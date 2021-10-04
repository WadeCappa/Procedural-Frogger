#include "parentzone.hpp"
#include "vector"

#include <SFML/Graphics.hpp>


ParentZone::ParentZone(int xGrid, int yGrid)
{
    xBound = xGrid;
    yBound = yGrid;
}

ParentZone::~ParentZone()
{
    std::cout << "deleting zone" << std::endl;
    for (int y_index = 0; y_index < yBound; y_index++)
    {
        for (int x_index  = 0; x_index < xBound; x_index++)
        {
            delete zoneBoard[y_index][x_index];            
        }
    }
}




void ParentZone::drawZone(int px, sf::RenderWindow* window, int zoneIncrement)
{
    for (int j = 0; j < yBound; j++)
    {
        for (int i = 0; i < xBound; i++)
        {
            //std::cout << "before getting val" << std::endl;
            // std::cout << zoneBoard[j][i]->getVal();
            (*window).draw(*zoneBoard[j][i]->getShape());
        }
        // std::cout << std::endl;
    }
}
// (px * i) - px


void ParentZone::setTiles(char nT, char hT, char haz)
{
    nTile = nT;
    hTile = hT;
    hazard = haz;
}




void ParentZone::genZone(int px, int zoneIncrement)
{
    Tile* placeholder;
    for (int y_index = 0; y_index < yBound; y_index++)
    {
        std::vector<Tile*> temp;
        for (int x_index  = 0; x_index < xBound; x_index++)
        {
            placeholder = new Tile(nTile, px);

            placeholder->setPlacement((px * x_index), (px * y_index) + (yBound * px * zoneIncrement));

            temp.push_back(placeholder);
        }
        zoneBoard.push_back(temp);
    }
}


