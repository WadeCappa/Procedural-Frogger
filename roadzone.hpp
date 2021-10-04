#pragma once



#include "parentzone.hpp"


class RoadZone : public ParentZone
{
public:
    RoadZone(int xBound, int yBound, int px, int increment) : ParentZone(xBound, yBound)
    {
        setTiles('r', 'R', 'C');

        genZone(px, increment);
    }

    ~RoadZone()
    {
        std::cout << "del RoadZone" << std::endl;
    }
    

void genZone(int px, int zoneIncrement)
{
    Tile* placeholder;
    for (int y_index = 0; y_index < yBound; y_index++)
    {
        std::vector<Tile*> temp;
        for (int x_index  = 0; x_index < xBound; x_index++)
        {
            if (y_index == 2) { placeholder = new Tile(hTile, px); }
            else { placeholder = new Tile(nTile, px); }

            placeholder->setPlacement((px * x_index), (px * y_index) + (yBound * px * zoneIncrement));

            temp.push_back(placeholder);
        }
        zoneBoard.push_back(temp);
    }
}



private:
    

};