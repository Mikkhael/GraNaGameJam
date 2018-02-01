#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Vectors.hpp"
#include "Object.hpp"
#include "TextureManager.hpp"

using namespace std;

vector<Object> walls;


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    
    walls.push_back(Object("walls/brick.bmp", sf::IntRect(0,0,400,400)));
    walls.push_back(Object("walls/planks.bmp", sf::IntRect(0,0,100,50)));
    walls.push_back(Object("walls/rocks.bmp"));
    walls.push_back(Object("walls/rocks.bmp"));
    walls.push_back(Object("walls/brick.bmp"));
    
    walls[0].sprite.setPosition(2,0);
    
    walls[1].sprite.setPosition(50,0);
    
    walls[2].sprite.setPosition(200,200);
    walls[2].setSize(sf::IntRect(0,0,30,100));
    
    walls[3].sprite.setPosition(300,200);
    walls[3].setSize(sf::IntRect(0,0,30,100));
    
    walls[4].sprite.setPosition(400,400);
    walls[4].setSize(sf::IntRect(0,0,100,100));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        window.clear();     
        
        for(auto i = 0u; i<walls.size(); i++)
        {
            walls[i].draw(window);
        }
        
        
        window.display();
    }

    return 0;
}
