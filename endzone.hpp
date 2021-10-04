#pragma once



#include "parentzone.hpp"


class EndZone : public ParentZone
{
public:
    EndZone(int xBound, int yBound, int px, int increment) : ParentZone(xBound, yBound)
    {
        setTiles('g', 'g', 'g');

        genZone(px, increment);
    }

    ~EndZone()
    {
        std::cout << "del EndZone" << std::endl;
    }




private:
   
};