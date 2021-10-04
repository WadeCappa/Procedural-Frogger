#pragma once



#include "parentzone.hpp"


class BoatZone : public ParentZone
{
public:
    BoatZone(int xBound, int yBound, int px, int increment) : ParentZone(xBound, yBound)
    {
        setTiles('w', 'p', 'B');

        genZone(px, increment);
    }

    ~BoatZone()
    {
        std::cout << "del BoatZone" << std::endl;
    }

private:
   
    //void genZone(void);

};