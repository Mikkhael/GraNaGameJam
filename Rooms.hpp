#ifndef ROOMS_HPP_INCLUDED
#define ROOMS_HPP_INCLUDED
#include "Object.hpp"
#include <vector>
#include <tuple>


class Platform
{
public:
    sf::Rect<double> collid;
<<<<<<< HEAD

    Platform(const sf::Rect<double>& r)
        : collid(r)
    {}

    static std::vector<Platform> list;

=======
    
    Platform(const sf::Rect<double>& r)
        : collid(r)
    {}
    
    static std::vector<Platform> list;
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    static auto add(const sf::Rect<double>& r)
    {
        list.push_back(Platform(r));
        return list.end();
    }
    
<<<<<<< HEAD
    constexpr static double tolerance = 2.5;
    
=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    static std::vector<sf::Rect<double> > testAll(Object& o)
    {
        std::vector<sf::Rect<double> > res;
        for(auto& v : list)
        {
<<<<<<< HEAD
            if(v.collid.width > 1 || v.collid.height > 1)
            {
                /**/
                if(v.collid.width > v.collid.height)
                {
                    if(o.testCollision(sf::Rect<double>(v.collid.left + tolerance, v.collid.top, v.collid.width - tolerance*2, v.collid.height), false))
                    {
                        res.push_back(v.collid);
                    }   
                }
                else
                {
                    if(o.testCollision(sf::Rect<double>(v.collid.left, v.collid.top + tolerance, v.collid.width, v.collid.height - tolerance*2), false))
                    {
                        res.push_back(v.collid);
                    }   
                }
                /**/
                /*
                if(o.testCollision(sf::Rect<double>(v.collid.left, v.collid.top, v.collid.width, v.collid.height), false))
                {
                    res.push_back(v.collid);
                } 
                /**/
=======
            if(o.testCollision(v.collid, false))
            {
                res.push_back(v.collid);
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
            }
        }
        return res;
    }
<<<<<<< HEAD

    static void show(sf::RenderTarget& rt)
    {
        sf::RectangleShape rs;
        rs.setOutlineColor(sf::Color::Red);
        rs.setFillColor(sf::Color::Transparent);
        rs.setOutlineThickness(1);
        for(const auto& p : list)
        {
            rs.setPosition(p.collid.left, p.collid.top);
            rs.setSize({std::max(p.collid.width,1.0) ,std::max(p.collid.height,1.0)});

            rt.draw(rs);
        }
    }
=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
};

std::vector<Platform> Platform::list;

class Room
{
public:
<<<<<<< HEAD

    Object o;
    static std::vector<Room> list;

=======
    
    Object o;
    static std::vector<Room> list;    
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    Room(const Vector2f& pos, const Vector2i& size, const std::string& texture)
        : o(texture, sf::IntRect(0,0,size.x, size.y))
    {
        o.sprite.setPosition(pos);
    }
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    static void add(const Vector2f& pos, const Vector2i& size, const std::string& texture)
    {
        list.push_back(Room(pos,size,texture));
    }
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    static void draw(sf::RenderTarget& rt)
    {
        for(auto& i : list)
        {
            i.o.draw(rt);
        }
    }
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    void cover()
    {
        //Platform::add(sf::Rect<double>(o.sprite.getPosition().x, o.sprite.getPosition().y, o.sprite.getTextureRect().width, 0.1));
        Platform::add(sf::Rect<double>(o.sprite.getPosition().x, o.sprite.getPosition().y, 0.1, o.sprite.getTextureRect().height));
        Platform::add(sf::Rect<double>(o.sprite.getPosition().x + o.sprite.getTextureRect().width, o.sprite.getPosition().y, 0.1, o.sprite.getTextureRect().height));
        Platform::add(sf::Rect<double>(o.sprite.getPosition().x, o.sprite.getPosition().y + o.sprite.getTextureRect().height, o.sprite.getTextureRect().width, 0.1));
    }
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    static void coverAll()
    {
        std::vector<Platform> horizontal, vertical;
        for(auto& r : list)
<<<<<<< HEAD
        {
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, r.o.sprite.getTextureRect().width, 0.1));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y + r.o.sprite.getTextureRect().height, r.o.sprite.getTextureRect().width, 0.1));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x + r.o.sprite.getTextureRect().width, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));

=======
        {                
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, r.o.sprite.getTextureRect().width, 0.1));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x + r.o.sprite.getTextureRect().width, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y + r.o.sprite.getTextureRect().height, r.o.sprite.getTextureRect().width, 0.1));
            
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
        }
        for(Platform& p : horizontal)
        {
            for(Platform& p2 : horizontal)
            {
                if(&p == &p2) continue;
<<<<<<< HEAD
                if(std::abs(p.collid.top - p2.collid.top) > 0.001)
                    continue;
                if(!Collision::test(Vector2d(p.collid.left, p.collid.left+p.collid.width), Vector2d(p2.collid.left, p2.collid.left + p2.collid.width)))
                    continue;

                sf::Rect<double>& l = p.collid.left < p2.collid.left ? p.collid : p2.collid;
                sf::Rect<double>& r = p.collid.left < p2.collid.left ? p2.collid : p.collid;

                if(l.left+l.width < r.left+r.width)
                {
                    double tempLwidth = r.left - l.left;
                    double tempRleft  = l.left + l.width;
                    double tempRwidth = r.left + r.width - l.left - l.width;

                    l.width = tempLwidth;
                    r.left  = tempRleft;
                    r.width = tempRwidth;

                    std::cout<<l.left<<" "<<l.width<<std::endl;
                }
                else
                {
                    double tempLwidth = r.left - l.left;
                    double tempRleft  = r.left + r.width;
                    double tempRwidth = l.left + l.width - r.left - r.width;


=======
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
                    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
                    l.width = tempLwidth;
                    r.left  = tempRleft;
                    r.width = tempRwidth;
                }
            }
<<<<<<< HEAD

        }
        for(Platform& p : vertical)
        {
            for(Platform& p2 : vertical)
            {
                if(&p == &p2) continue;
                if(std::abs(p.collid.left - p2.collid.left) > 0.001)
                    continue;
                if(!Collision::test(Vector2d(p.collid.top, p.collid.top+p.collid.height), Vector2d(p2.collid.top, p2.collid.top + p2.collid.height)))
                    continue;

                sf::Rect<double>& l = p.collid.top < p2.collid.top ? p.collid : p2.collid;
                sf::Rect<double>& r = p.collid.top < p2.collid.top ? p2.collid : p.collid;

                if(l.top+l.height < r.top+r.height)
                {
                    double tempLwidth = r.top - l.top;
                    double tempRleft  = l.top + l.height;
                    double tempRwidth = r.top + r.height - l.top - l.height;

                    l.height = tempLwidth;
                    r.top  = tempRleft;
                    r.height = tempRwidth;

                    std::cout<<l.top<<" "<<l.height<<std::endl;
                }
                else
                {
                    double tempLwidth = r.top - l.top;
                    double tempRleft  = r.top + r.height;
                    double tempRwidth = l.top + l.height - r.top - r.height;


                    l.height = tempLwidth;
                    r.top  = tempRleft;
                    r.height = tempRwidth;
                }
            }

        }

=======
            
        }
        
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
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
<<<<<<< HEAD

    }

=======
        
    }
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
};

std::vector<Room> Room::list;



#endif // ROOMS_HPP_INCLUDED
