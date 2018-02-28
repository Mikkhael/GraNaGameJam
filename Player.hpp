#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "Vectors.hpp"
#include "Rooms.hpp"
<<<<<<< HEAD
#include "Cannon.hpp"


class Player : public Object
{

=======

double gravity = 0.5;
double drag    = 0.001;

class Player : public Object
{
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    void trySettingAnimation(const AnimationPreset& ap)
    {
        if(animation->compareWithPreset(ap))
            return;
        animation->setPreset(ap);
    }
<<<<<<< HEAD

public:

    bool isLeft = false;



    Vector2<double> velocity = Vectors::null;
    double speed = 40;


    bool movable = true;
    bool moving = false;
    bool inAir = false;
    const double fireRate = 1;
    double fired = 0;
    
    const double fireForce = 300;
    const double fireReppelForce = 200;

=======
    
public:
    
    bool isLeft = false;
    bool hasCannon = false;
    
    
    
    Vector2<double> velocity = Vectors::null;
    double speed = 40;
    
    
    bool movable = true;
    bool moving = false;
    bool inAir = false;
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
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
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    virtual void update(double deltaTime)
    {
        Vector2d newPos = sprite.getPosition();
        auto temp = sprite.getPosition();
<<<<<<< HEAD


        if(!inAir || velocity.magnatudeSquared()<0.00001)
            velocity = Vectors::null;


        velocity*=1-drag;

        if(inAir)
        {
            velocity+=Vectors::up*gravity*deltaTime;
        }


=======
        
        
        if(!inAir || velocity.magnatudeSquared()<0.00001)
            velocity = Vectors::null;
        
        
        velocity*=1-drag;
        
        if(inAir)
        {
            velocity+=Vectors::up*gravity;
        }
        
        
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
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
<<<<<<< HEAD

=======
            
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if(!inAir)
                {
                    inAir = true;
<<<<<<< HEAD
                    velocity += Vectors::down*300;
                    newPos.y-=1;
                    //std::cout<<velocity.x<<" "<<velocity.y<<std::endl;

                }
            }
            
            fired -= deltaTime;
            if(fired < 0)
                fired = 0;
                
            if(fired == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                auto dir = (mouseRealPosition - (Vector2d(sprite.getPosition()) + Vector2d(8,8))).normalize();
                CannonBall::spawn(Vector2d(sprite.getPosition().x + 8, sprite.getPosition().y + 8), dir, fireForce);
                if(inAir)
                {
                    velocity+=dir*(-fireReppelForce);
                }
                
                fired = fireRate;
            }

        }

        newPos+=velocity*deltaTime;

        sprite.setPosition(newPos);
        inAir = true;
        for(auto& rect : Platform::testAll(*this))
        {
            if(inAir && rect.width > rect.height)
            {
                
                //if(velocity.y >= 0)
                if(std::abs(rect.top - newPos.y) >= std::abs(newPos.y + 16 - rect.top))
=======
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
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
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
<<<<<<< HEAD
                if(std::abs(rect.left - newPos.x) > std::abs(newPos.x + 16 - rect.left))
=======
                if(temp.x < newPos.x)
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
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
<<<<<<< HEAD

        sprite.setPosition(newPos);
    }

=======
        
        sprite.setPosition(newPos);
    }
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
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
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    Player() : Object("creatures/player.bmp", AnimationPresets::PlayerIdle, "PLAYER")
    {
        setCollider(sf::Rect<double>(6, 1, 4, 16));
        velocity = Vector2d(10, 10);
    }
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    virtual ~Player(){};
};


#endif // PLAYER_HPP_INCLUDED
