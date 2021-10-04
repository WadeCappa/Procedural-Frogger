#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

class Tile
{
public:
    Tile(char input, int insize)
    {
        size = insize;
        val = input;

        hazard = false;

        texture = new sf::RectangleShape({float(size), float(size)});;
        alt = new sf::RectangleShape({float(size), float(size)});;

        findTexture();
    }

    ~Tile()
    {
        delete texture;
        delete alt;
    }

    char getVal(void)
    {
        return val;
    }

    bool getHazard(void)
    {
        return hazard;
    }

    sf::RectangleShape* getShape(void)
    {
        return texture;
    }

    void setVal(char input)
    {
        val = input;
        delete texture->getTexture();
        delete alt->getTexture();
        findTexture();
    }

    void setPlacement(int x, int y)
    {
        texture->setPosition(float(x), float(y));
        alt->setPosition(float(x), float(y));
    }

private:
    char val;
    sf::RectangleShape* texture;
    sf::RectangleShape* alt;
    int size;

    bool hazard;

    void findTexture(void)
    {
        sf::Texture* newText = new sf::Texture;    
        sf::Texture* altText = new sf::Texture;

        switch (val)
        {
            case 'g':
                newText->loadFromFile("tileset/g_tile.jpg");
                altText->loadFromFile("tileset/g_tileALT.jpg");
                hazard = false;
                break;

            case 'w':
                newText->loadFromFile("tileset/w_tile.jpg");
                altText->loadFromFile("tileset/w_tileALT.jpg");
                hazard = true;
                break;
            
            case 'r':
                newText->loadFromFile("tileset/r_tile.jpg");
                altText->loadFromFile("tileset/r_tile.jpg");
                hazard = false;
                break;

            case 'R':
                newText->loadFromFile("tileset/r_tileALT.jpg");
                altText->loadFromFile("tileset/r_tile.jpg");
                hazard = false;
                break;
            
            case 'l':
                newText->loadFromFile("tileset/l_tile.jpg");
                altText->loadFromFile("tileset/l_tile.jpg");
                hazard = false;
                break;
            
            case 't':
                newText->loadFromFile("tileset/t_tile.jpg");
                altText->loadFromFile("tileset/t_tile.jpg");
                hazard = false;
                break;

            case 'p':
                newText->loadFromFile("tileset/p_tile.jpg");
                altText->loadFromFile("tileset/p_tileALT.jpg");
                hazard = false;
                break;

            case 'E':
                newText->loadFromFile("tileset/E_tile.jpg");
                altText->loadFromFile("tileset/E_tileALT.jpg");
                hazard = false;

        }

        texture->setTexture(newText);
        alt->setTexture(altText);
    }


};


