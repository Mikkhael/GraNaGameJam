#ifndef CANNON_HPP_INCLUDED
#define CANNON_HPP_INCLUDED

#include "Object.hpp"
#include "Colisions.hpp"
#include <vector>

class CannonBall : public Object
{
public:
    
    virtual ~CannonBall(){};
    CannonBall(Vector2d pos, Vector2d dir, double speed)
        :Object("creatures/player.bmp", sf::IntRect(0,16*2,5,5))
    {
        sprite.setPosition(pos);
        velocity = dir * speed;
        
        setCollider(sf::Rect<double>(0, 0, 5, 5));
    }
    
    
    Vector2<double> velocity = Vectors::null;
    double speed;
    
    virtual void update(double deltaTime)
    {
        
        Vector2d newPos = sprite.getPosition();
        auto temp = sprite.getPosition();
        
        velocity+=Vectors::up*gravity*deltaTime;
        velocity*=1-drag;
        newPos+=velocity*deltaTime;
        
        sprite.setPosition(newPos);
        
        for(auto& rect : Platform::testAll(*this))
        {
            if(rect.width > rect.height)
            {
                
                //if(std::abs(rect.top - newPos.y) >= std::abs(newPos.y + 5 - rect.top))
                if(velocity.y >= 0)
                {
                    newPos.y = rect.top - 5;
                }
                else if(velocity.y < 0)
                {
                    newPos.y = rect.top+rect.height;
                }
                velocity.y = 0;
            }
            else if(rect.width < rect.height)
            {
                //if(std::abs(rect.left - newPos.x) > std::abs(newPos.x + 5 - rect.left))
                if(velocity.x > 0)
                {
                    newPos.x = rect.left - 5;
                }
                else
                {
                    newPos.x = rect.left + rect.width;
                }
                velocity.x = 0;
            }
            //std::cout<<rect.left<<" "<<rect.top<<" "<<rect.width<<" "<<rect.height<<" - ";
        }
        sprite.setPosition(newPos);
    }
    
    static std::vector<CannonBall> list;
    
    static void spawn(Vector2d pos, Vector2d dir, double speed)
    {
        list.push_back(CannonBall(pos, dir, speed));
    }
    
};
std::vector<CannonBall> CannonBall::list;

#endif // CANNON_HPP_INCLUDED
