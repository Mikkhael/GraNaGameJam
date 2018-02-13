#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "Vectors.hpp"
#include "Rooms.hpp"

double gravity = 0.5;
double drag    = 0.001;

class Player : public Object
{
    
    void trySettingAnimation(const AnimationPreset& ap)
    {
        if(animation->compareWithPreset(ap))
            return;
        animation->setPreset(ap);
    }
    
public:
    
    bool isLeft = false;
    bool hasCannon = false;
    
    
    
    Vector2<double> velocity = Vectors::null;
    double speed = 40;
    
    
    bool movable = true;
    bool moving = false;
    bool inAir = false;
    
    void setValidAnimation()
    {
        if(inAir)
        {
            trySettingAnimation(AnimationPresets::PlayerFly);
        }
        else
        {
            if(moving)
            {
                trySettingAnimation(AnimationPresets::PlayerWalk);
            }
            else
            {
                trySettingAnimation(AnimationPresets::PlayerIdle);
            }
        }
    }
    
    virtual void update(double deltaTime)
    {
        Vector2d newPos = sprite.getPosition();
        auto temp = sprite.getPosition();
        
        
        if(!inAir || velocity.magnatudeSquared()<0.00001)
            velocity = Vectors::null;
        
        
        velocity*=1-drag;
        
        if(inAir)
        {
            velocity+=Vectors::up*gravity;
        }
        
        
        if(movable)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                isLeft = true;
                moving = true;
                newPos+=Vectors::backward*speed*deltaTime;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                isLeft = false;
                moving = true;
                newPos+=Vectors::foreward*speed*deltaTime;
            }
            else
            {
                moving = false;
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if(!inAir)
                {
                    inAir = true;
                    velocity += Vectors::down*gravity*700;
                    newPos.y-=1;
                    //std::cout<<velocity.x<<" "<<velocity.y<<std::endl;
        
                }
            }
            
            
        }
                
        newPos+=velocity*deltaTime;
        
        sprite.setPosition(newPos);
        sf::Rect<double> rect;
        inAir = true;
        for(auto& rect : Platform::testAll(*this))
        {   
            if(inAir && rect.width > rect.height)
            {
                if(velocity.y >= 0)
                {
                    inAir = false;
                    newPos.y = rect.top - 16;
                }
                else if(velocity.y < 0)
                {
                    newPos.y = rect.top+rect.height;
                }
                velocity.y = 0;
            }
            else if(rect.width < rect.height)
            {
                if(temp.x < newPos.x)
                {
                    newPos.x = rect.left - 10;
                }
                else
                {
                    newPos.x = rect.left + rect.width - 6;
                }
                velocity.x = 0;
            }
            //std::cout<<rect.left<<" "<<rect.top<<" "<<rect.width<<" "<<rect.height<<" - ";
        }
        //8std::cout<<std::endl;
        
        sprite.setPosition(newPos);
    }
    
    virtual void draw(sf::RenderTarget& rt)
    {
        setValidAnimation();
        sprite.setTextureRect(animation->get());
        if(isLeft)
        {
            flip(sprite);
        }
        rt.draw(sprite);
    }
    
    Player() : Object("creatures/player.bmp", AnimationPresets::PlayerIdle, "PLAYER")
    {
        setCollider(sf::Rect<double>(6, 1, 4, 16));
        velocity = Vector2d(10, 10);
    }
    
    virtual ~Player(){};
};


#endif // PLAYER_HPP_INCLUDED
