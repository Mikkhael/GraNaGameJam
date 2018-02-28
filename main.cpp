#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Vectors.hpp"
#include "Object.hpp"
#include "Colisions.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
<<<<<<< HEAD
#include "lights.hpp"
=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957

using namespace std;

vector<Object> creatures;

Player player;
<<<<<<< HEAD

const float zoom = 3;
const float WIDTH = 800;
const float HTIGH = 600;
=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HTIGH), "Game");
    
    
<<<<<<< HEAD
    
    sf::RenderTexture albedo;
    albedo.create(WIDTH , HTIGH, false);
    sf::Sprite albedoSprite;
    
    sf::RenderTexture shadows;
    shadows.create(WIDTH , HTIGH, false);
    sf::Sprite shadowsSprite;
    
    LightEmmition lightEmmition;
    
    lightEmmition.texture.create(WIDTH, HTIGH, false);

    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerIdle, "player"));
    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerWalk, "playerWalking"));

    //creatures[0].sprite.setPosition(0,0);
    //creatures[1].sprite.setPosition(0,20);

    player.sprite.setPosition(0,0);

=======
    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerIdle, "player"));
    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerWalk, "playerWalking"));
    
    //creatures[0].sprite.setPosition(0,0);
    //creatures[1].sprite.setPosition(0,20);
    
    player.sprite.setPosition(0,0);
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    sf::CircleShape c;
    c.setFillColor(sf::Color::Red);
    c.setRadius(5);
    c.setOrigin(5,5);
<<<<<<< HEAD

    Room::add(Vector2f(0,0), Vector2i(50,50), "walls/rocks.bmp");
    Room::add(Vector2f(20,50), Vector2i(60,100), "walls/planks.bmp");
    Room::add(Vector2f(80,110), Vector2i(100,40), "walls/brick.bmp");

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

    view.reset(sf::FloatRect(0,0,window.getSize().x/zoom,window.getSize().y/zoom));
    view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));


    window.setView(view);
    
    
    double Timer = 0;
=======
    
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
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
<<<<<<< HEAD
        mouseRealPosition = getRealMouse(window);

=======
        
        
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        Timer += deltaTime;
        
        albedo.clear(sf::Color::Black);
        shadows.clear(sf::Color::Black);
        


        for(auto i = 0u; i<creatures.size(); i++)
        {
            creatures[i].base_update(deltaTime);
        }
        player.base_update(deltaTime);
        for(auto i = 0u; i<CannonBall::list.size(); i++)
        {
            CannonBall::list[i].base_update(deltaTime);
        }
        
        emitLight(shadows, lightEmmition, Vector2d(player.sprite.getPosition())+Vector2d(8,4), 1000);


        Room::draw(albedo);
        
        
<<<<<<< HEAD
        for(auto i = 0u; i<creatures.size(); i++)
        {
            creatures[i].draw(albedo);
        }
        player.draw(albedo);
        for(auto i = 0u; i<CannonBall::list.size(); i++)
        {
            CannonBall::list[i].draw(albedo);
        }
        //Platform::show(albedo);
=======
        
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
        
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
        
        std::cout<<player.sprite.getPosition().x<<" "<<player.sprite.getPosition().y<<std::endl;
        
        shadowsSprite.setTexture(shadows.getTexture());
        albedo.draw(shadowsSprite, sf::BlendMultiply);
        
        
        mouseRealPosition = getRealMouse(window);
        c.setPosition(getRealMouse(window));
        albedo.draw(c);
        
        
        
        albedo.display();
        
        
        albedoSprite.setTexture(albedo.getTexture());
        
        
        window.clear();
        window.draw(albedoSprite);
        //window.draw(shadowsSprite);
        //std::cout<<player.sprite.getPosition().x<<" "<<player.sprite.getPosition().y<<std::endl;

        window.display();
    }

    return 0;
}
