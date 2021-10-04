#include "frog.hpp"

#include <SFML/Graphics.hpp>

Frog::Frog(int initX, int initY, int gridX, int gridY)
{
    x_pos = initX;
    y_pos = initY;

    maxGrid_X = gridX;
    maxGrid_Y = gridY;

    texture = new sf::RectangleShape({20, 20});    
    texture->setFillColor(sf::Color::Red);
    texture->setPosition({float(initX * 20), float(initY * 20)});

    for (int i = 0; i < 4; i++)
    {
        locked[i] = 0;
    }
}


Frog::~Frog()
{
    delete texture;
}

int Frog::getX()
{
    return x_pos;
}


int Frog::getY()
{
    return y_pos;
}


sf::RectangleShape* Frog::getShape()
{
    return texture;
}




void Frog::upX()
{
    if (x_pos + 1 < maxGrid_X)
    {
        x_pos ++;
        texture->setPosition({float(x_pos * 20), float(y_pos * 20)});
    }
}


void Frog::downY()
{
    if (y_pos + 1 < maxGrid_Y)
    {
        y_pos ++;
        texture->setPosition({float(x_pos * 20), float(y_pos * 20)});
    }
}


void Frog::upY()
{
    if (y_pos > 0)
    {
        y_pos --;
        texture->setPosition({float(x_pos * 20), float(y_pos * 20)});
    }
}   


void Frog::downX()
{
    if (x_pos > 0)
    {
        x_pos --;
        texture->setPosition({float(x_pos * 20), float(y_pos * 20)});
    }
}


int* Frog::changeLocked()
{
    return locked;
}