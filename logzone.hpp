#pragma once




#include "parentzone.hpp"


class LogZone : public ParentZone
{
public:
    LogZone(int xBound, int yBound, int px, int increment) : ParentZone(xBound, yBound)
    {
        setTiles('w', 'l', 'G');

        genZone(px, increment);
    }

    ~LogZone()
    {
        std::cout << "del LogZone" << std::endl;
    }


    



private:
   
    //void genZone(void);

};