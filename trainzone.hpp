#pragma once

#include "parentzone.hpp"


class TrainZone : public ParentZone
{
public:
    TrainZone(int xBound, int yBound, int px, int increment) : ParentZone(xBound, yBound)
    {
        setTiles('g', 't', 'T');

        genZone(px, increment);
    }

    ~TrainZone()
    {
        std::cout << "del TrainZone" << std::endl;
    }


void genZone(int px, int zoneIncrement)
{
    Tile* placeholder;
    for (int y_index = 0; y_index < yBound; y_index++)
    {
        std::vector<Tile*> temp;
        for (int x_index  = 0; x_index < xBound; x_index++)
        {
            if (y_index > 0 and y_index < 4) { placeholder = new Tile(hTile, px); }
            else { placeholder = new Tile(nTile, px); }

            placeholder->setPlacement((px * x_index), (px * y_index) + (yBound * px * zoneIncrement));

            temp.push_back(placeholder);
        }
        zoneBoard.push_back(temp);
    }
}

private:
   
};