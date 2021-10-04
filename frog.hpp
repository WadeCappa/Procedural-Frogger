#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

class Frog
{
public:
    Frog(int initX, int initY, int gridX, int gridY);
    ~Frog();

    int getX();
    int getY();

    void upX();
    void upY();  
    void downY();
    void downX();

    int* changeLocked();

    sf::RectangleShape* getShape();

private:
    char rep;
    sf::RectangleShape* texture;

    int x_pos;
    int y_pos;
    int maxGrid_X;
    int maxGrid_Y;

    int locked[4];
};


