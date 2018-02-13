#ifndef ROOMS_HPP_INCLUDED
#define ROOMS_HPP_INCLUDED
#include "Object.hpp"
#include <vector>
#include <tuple>


class Platform
{
public:
    sf::Rect<double> collid;
    
    Platform(const sf::Rect<double>& r)
        : collid(r)
    {}
    
    static std::vector<Platform> list;
    
    static auto add(const sf::Rect<double>& r)
    {
        list.push_back(Platform(r));
        return list.end();
    }
    
    static std::vector<sf::Rect<double> > testAll(Object& o)
    {
        std::vector<sf::Rect<double> > res;
        for(auto& v : list)
        {
            if(o.testCollision(v.collid, false))
            {
                res.push_back(v.collid);
            }
        }
        return res;
    }
};

std::vector<Platform> Platform::list;

class Room
{
public:
    
    Object o;
    static std::vector<Room> list;    
    
    Room(const Vector2f& pos, const Vector2i& size, const std::string& texture)
        : o(texture, sf::IntRect(0,0,size.x, size.y))
    {
        o.sprite.setPosition(pos);
    }
    
    static void add(const Vector2f& pos, const Vector2i& size, const std::string& texture)
    {
        list.push_back(Room(pos,size,texture));
    }
    
    static void draw(sf::RenderTarget& rt)
    {
        for(auto& i : list)
        {
            i.o.draw(rt);
        }
    }
    
    void cover()
    {
        //Platform::add(sf::Rect<double>(o.sprite.getPosition().x, o.sprite.getPosition().y, o.sprite.getTextureRect().width, 0.1));
        Platform::add(sf::Rect<double>(o.sprite.getPosition().x, o.sprite.getPosition().y, 0.1, o.sprite.getTextureRect().height));
        Platform::add(sf::Rect<double>(o.sprite.getPosition().x + o.sprite.getTextureRect().width, o.sprite.getPosition().y, 0.1, o.sprite.getTextureRect().height));
        Platform::add(sf::Rect<double>(o.sprite.getPosition().x, o.sprite.getPosition().y + o.sprite.getTextureRect().height, o.sprite.getTextureRect().width, 0.1));
    }
    
    static void coverAll()
    {
        std::vector<Platform> horizontal, vertical;
        for(auto& r : list)
        {                
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, r.o.sprite.getTextureRect().width, 0.1));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x + r.o.sprite.getTextureRect().width, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y + r.o.sprite.getTextureRect().height, r.o.sprite.getTextureRect().width, 0.1));
            
        }
        for(Platform& p : horizontal)
        {
            for(Platform& p2 : horizontal)
            {
                if(&p == &p2) continue;
                if(std::abs(p.collid.top - p2.collid.top) < 0.001)
                    continue;
                if(!Collision::test(Vector2d(p.collid.left, p.collid.left+p.collid.width), Vector2d(p2.collid.left, p2.collid.left + p2.collid.width)))
                    continue;
                
                sf::Rect<double>& l = p.collid.left < p2.collid.left ? p.collid : p2.collid;
                sf::Rect<double>& r = p.collid.left < p2.collid.left ? p2.collid : p.collid;
                
                if(l.left+l.width < r.left+r.width)
                {
                    double tempLwidth = l.width - (l.left + l.width) - r.left;
                    double tempRleft  = l.left + l.width;
                    double tempRwidth = r.width - (l.left + l.width) - r.left;
                    
                    l.width = tempLwidth;
                    r.left  = tempRleft;
                    r.width = tempRwidth;
                }
                else
                {
                    double tempLwidth = l.width - (l.left + l.width) - r.left;
                    double tempRleft  = r.left + r.width;
                    double tempRwidth = l.left + l.width - r.left - r.width;
                    
                    l.width = tempLwidth;
                    r.left  = tempRleft;
                    r.width = tempRwidth;
                }
            }
            
        }
        
        for(auto& p : horizontal)
        {
            if(p.collid.width > 0.0001)
            {
                Platform::list.push_back(p);
            }
        }
        for(auto& p : vertical)
        {
            if(p.collid.height > 0.0001)
            {
                Platform::list.push_back(p);
            }
        }
        
    }
    
};

std::vector<Room> Room::list;



#endif // ROOMS_HPP_INCLUDED
