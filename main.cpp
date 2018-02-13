#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Vectors.hpp"
#include "Object.hpp"
#include "Colisions.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"

using namespace std;

vector<Object> creatures;

Player player;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    
    
    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerIdle, "player"));
    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerWalk, "playerWalking"));
    
    //creatures[0].sprite.setPosition(0,0);
    //creatures[1].sprite.setPosition(0,20);
    
    player.sprite.setPosition(0,0);
    
    sf::CircleShape c;
    c.setFillColor(sf::Color::Red);
    c.setRadius(5);
    c.setOrigin(5,5);
    
    Room::add(Vector2f(0,0), Vector2i(50,50), "walls/rocks.bmp");
    //Room::list.back().cover();
    Room::add(Vector2f(20,50), Vector2i(20,100), "walls/planks.bmp");
    
    Room::coverAll();
    
    
    /*
    Object A, B;
    A.setCollider(sf::Rect<double>(0,0,10,10));
    A.sprite.setPosition(0,0);
    B.setCollider(sf::Rect<double>(5,10,10,10));
    B.sprite.setPosition(0,0);
    std::cout<<A.testCollision(B);
    std::cin.get();
    */
    
    sf::Clock clock;
    double deltaTime = 0;
    
    
    sf::View view;
    
    view.reset(sf::FloatRect(0,0,window.getSize().x/3,window.getSize().y/3));
    view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    
    
    window.setView(view);
    
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        window.clear();     
        
        
        for(auto i = 0u; i<creatures.size(); i++)
        {
            creatures[i].base_update(deltaTime);
        }
    
        player.base_update(deltaTime);
        
        
        Room::draw(window);
        for(auto i = 0u; i<creatures.size(); i++)
        {
            creatures[i].draw(window);
        }
        player.draw(window);
        
        c.setPosition(getRealMouse(window));
        window.draw(c);
        
        
        std::cout<<player.sprite.getPosition().x<<" "<<player.sprite.getPosition().y<<std::endl;
        
        window.display();
    }

    return 0;
}
