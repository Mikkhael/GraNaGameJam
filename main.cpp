#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Vectors.hpp"
#include "Object.hpp"
#include "Colisions.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
<<<<<<< HEAD
//<<<<<<< HEAD
#include "lights.hpp"
/*=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
<<<<<<< HEAD
#include "lights.hpp"
=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d

using namespace std;

vector<Object> creatures;

Player player;
<<<<<<< HEAD
//<<<<<<< HEAD

const float zoom = 2;
const float WIDTH = 800;
const float HTIGH = 600;
/*=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HTIGH), "Game", sf::Style::Titlebar | sf::Style::Close);


//<<<<<<< HEAD

    sf::RenderTexture albedo;
    albedo.create(WIDTH , HTIGH, false);
    sf::Sprite albedoSprite;

    sf::RenderTexture shadows;
    shadows.create(WIDTH , HTIGH, false);
    sf::Sprite shadowsSprite;

    LightEmmition lightEmmition;

=======
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
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    lightEmmition.texture.create(WIDTH, HTIGH, false);

    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerIdle, "player"));
    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerWalk, "playerWalking"));

    //creatures[0].sprite.setPosition(0,0);
    //creatures[1].sprite.setPosition(0,20);

<<<<<<< HEAD
    //player.sprite.setPosition(10,250);
    player.sprite.setPosition(10,250);

/*=======
    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerIdle, "player"));
    //creatures.push_back(Object("creatures/player.bmp", AnimationPresets::PlayerWalk, "playerWalking"));

    //creatures[0].sprite.setPosition(0,0);
    //creatures[1].sprite.setPosition(0,20);

    player.sprite.setPosition(0,0);

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
//<<<<<<< HEAD
/*
    Room::add(Vector2f(0,0), Vector2i(50,50), "walls/rocks.bmp");
    Room::add(Vector2f(20,50), Vector2i(60,100), "walls/planks.bmp");
    Room::add(Vector2f(80,110), Vector2i(100,40), "walls/brick.bmp");
*/

    Room::add(Vector2f(0,240), Vector2i(60,60), "walls/rocks.bmp");
    Room::add(Vector2f(60,240), Vector2i(20,40), "walls/rocks.bmp");
    Room::add(Vector2f(80,210), Vector2i(100,90), "walls/rocks.bmp");
    Room::add(Vector2f(180,210), Vector2i(120,35), "walls/rocks.bmp");
    Room::add(Vector2f(300,170), Vector2i(30,60), "walls/rocks.bmp");
    Room::add(Vector2f(270,130), Vector2i(30,60), "walls/rocks.bmp");
    Room::add(Vector2f(300,90), Vector2i(30,60), "walls/rocks.bmp");
    Room::add(Vector2f(230,80), Vector2i(70,30), "walls/rocks.bmp");
    Room::add(Vector2f(220,90), Vector2i(10,20), "walls/planks.bmp");
    Room::add(Vector2f(70,82), Vector2i(150,32), "walls/brick.bmp");
    Room::add(Vector2f(90,114), Vector2i(40,96), "walls/rocks.bmp");
    Room::add(Vector2f(20,89-5), Vector2i(50,25), "walls/planks.bmp");
    Room::add(Vector2f(30,114-5), Vector2i(27,126+5), "walls/rocks.bmp");
    Room::add(Vector2f(0,0), Vector2i(20,114), "walls/planks.bmp");
    Room::add(Vector2f(20,0), Vector2i(140,30), "walls/planks.bmp");
    Room::add(Vector2f(160,0), Vector2i(300,50), "walls/sky.bmp");
    


    Room::coverAll();
    
    sf::Rect<double> winTigger(180, 0, 300,50);
    sf::Text winningText;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    winningText.setFont(font);
    winningText.setCharacterSize(20);
    winningText.setFillColor(sf::Color::White);
=======
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
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    

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

    bool running = true;
    bool won = false;
    double Timer = 0;
/*=======

    Room::add(Vector2f(0,0), Vector2i(50,50), "walls/rocks.bmp");
    //Room::list.back().cover();
    Room::add(Vector2f(20,50), Vector2i(20,100), "walls/planks.bmp");

    Room::coverAll();



    sf::Clock clock;
    double deltaTime = 0;


    sf::View view;

    view.reset(sf::FloatRect(0,0,window.getSize().x/3,window.getSize().y/3));
    view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));


    window.setView(view);
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/

    double CutsceneTimer = 0;
    sf::Sprite cutsceneSprite;
    cutsceneSprite.setTexture(textureManager.get("hello.bmp"));
    cutsceneSprite.setScale(10/zoom, 10/zoom);


    while (window.isOpen())
    {
<<<<<<< HEAD
        
        if(won && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        
        deltaTime = clock.restart().asSeconds();
//<<<<<<< HEAD
        mouseRealPosition = getRealMouse(window);

/*=======


>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
        deltaTime = clock.restart().asSeconds();
<<<<<<< HEAD
        mouseRealPosition = getRealMouse(window);

=======
        
        
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(CutsceneTimer > 0)
        {
            if(CutsceneTimer> 3)
            {
    cutsceneSprite.setTexture(textureManager.get("hello.bmp"));
            }
            else
            {
    cutsceneSprite.setTexture(textureManager.get("hello2.bmp"));
            }
            window.clear();
            window.draw(cutsceneSprite);
            window.display();
            CutsceneTimer-=deltaTime;
            continue;
        }
       
        if(running)
            Timer += deltaTime;
        
        
<<<<<<< HEAD
        if(running && player.testWin(winTigger))
        {
            running = false;
            std::cout<<Timer<<std::endl;
            
            wstringstream ss;
            ss << L"Uciekłeś!!!\nTwój czas to: " << Timer <<L"\nsekund\nNaciśnij ESC aby wyjść.";
            winningText.setString(ss.str());
            won = true;
=======
        Timer += deltaTime;
        
        albedo.clear(sf::Color::Black);
        shadows.clear(sf::Color::Black);
        


        for(auto i = 0u; i<creatures.size(); i++)
        {
            creatures[i].base_update(deltaTime);
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
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
        
<<<<<<< HEAD
        if(won)
        {
            window.clear();
            window.draw(winningText);
            window.display();
            continue;
        }
            
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

        emitLight(shadows, lightEmmition, Vector2d(player.sprite.getPosition())+Vector2d(8,4), 100);


        Room::draw(albedo);


//<<<<<<< HEAD
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
/*=======

        for(auto i = 0u; i<creatures.size(); i++)
        {
            creatures[i].base_update(deltaTime);
        }

        player.base_update(deltaTime);


=======
        
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
        Room::draw(window);
        for(auto i = 0u; i<creatures.size(); i++)
        {
            creatures[i].draw(window);
        }
        player.draw(window);
<<<<<<< HEAD

        c.setPosition(getRealMouse(window));
        window.draw(c);

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/

        //std::cout<<player.sprite.getPosition().x<<" "<<player.sprite.getPosition().y<<std::endl;

        shadowsSprite.setTexture(shadows.getTexture());
        albedo.draw(shadowsSprite, sf::BlendMultiply);


        mouseRealPosition = getRealMouse(window);



        albedo.display();


        albedoSprite.setTexture(albedo.getTexture());


=======
        
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
        
        
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
        window.clear();
        window.draw(albedoSprite);
        //window.draw(shadowsSprite);
        //std::cout<<player.sprite.getPosition().x<<" "<<player.sprite.getPosition().y<<std::endl;

        window.display();
    }

    return 0;
}
