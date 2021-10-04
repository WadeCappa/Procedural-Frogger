#include "gameboard.hpp"
#include "app.hpp"
#include "tile.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>



App::App()
{
    window = new sf::RenderWindow(sf::VideoMode(600, 1000), "Frog");
    window->setFramerateLimit(60);

    curBoard = new GameBoard(window);  

    frog = new Frog(280 / 20, 980 / 20, 600 / 20, 1000 / 20);
}



App::~App()
{
    delete window;
    delete curBoard;
    delete frog;
}



void App::run(void)
{

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window->close();    
            }                
        }   

        if (event.type == sf::Event::KeyReleased)
        {
            releaseKey(event);
        }   

        if (event.type == sf::Event::KeyPressed)
        {
            characterAction(event);
        }

        

        window->clear();

        curBoard->drawBoard();
        window->draw(*(frog->getShape()));

        window->display();        
    }   
}




void App::characterAction(sf::Event event)
{
    std::cout << frog->getX() << ",    " << frog->getY() << std::endl;
    if (event.key.code == sf::Keyboard::Up && frog->changeLocked()[0] == 0)         
    { 
        frog->upY(); 
        frog->changeLocked()[0] = 1; 
    }

    if (event.key.code == sf::Keyboard::Down && frog->changeLocked()[1] == 0)       
    { 
        frog->downY(); 
        frog->changeLocked()[1] = 1; 
    }

    if (event.key.code == sf::Keyboard::Left && frog->changeLocked()[2] == 0)       
    { 
        frog->downX(); 
        frog->changeLocked()[2] = 1; 
    }

    if (event.key.code == sf::Keyboard::Right && frog->changeLocked()[3] == 0)      
    { 
        frog->upX(); 
        frog->changeLocked()[3] = 1; 
    }

    checkSaftey();
}



void App::releaseKey(sf::Event event)
{
    if (event.key.code == sf::Keyboard::Up)         
    { 
        frog->changeLocked()[0] = 0; 
    }

    if (event.key.code == sf::Keyboard::Down)       
    { 
        frog->changeLocked()[1] = 0; 
    }

    if (event.key.code == sf::Keyboard::Left)       
    { 
        frog->changeLocked()[2] = 0; 
    }

    if (event.key.code == sf::Keyboard::Right)      
    { 
        frog->changeLocked()[3] = 0; 
    }
}


int App::checkSaftey(void)
{
    
    std::cout << getTile(frog->getX(), frog->getY())->getVal() << std::endl;

    //Tile *checkTile = curBoard->fetchTile(frog->getX(), frog->getY());
    //std::cout << checkTile->getVal() << std::endl;

    return 1;
}


Tile* App::getTile(int x_cord, int y_cord)
{
    return curBoard->zones[y_cord / 5]->zoneBoard[y_cord % 5][x_cord];
}