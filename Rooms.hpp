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
//<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d

    Platform(const sf::Rect<double>& r)
        : collid(r)
    {}

    static std::vector<Platform> list;

<<<<<<< HEAD
/*=======

    Platform(const sf::Rect<double>& r)
        : collid(r)
    {}

    static std::vector<Platform> list;

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
=======
    
    Platform(const sf::Rect<double>& r)
        : collid(r)
    {}
    
    static std::vector<Platform> list;
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    static auto add(const sf::Rect<double>& r)
    {
        list.push_back(Platform(r));
        return list.end();
    }
<<<<<<< HEAD

//<<<<<<< HEAD
    constexpr static double tolerance = 2.5;

/*=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
    
<<<<<<< HEAD
    constexpr static double tolerance = 2.5;
    
=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    static std::vector<sf::Rect<double> > testAll(Object& o)
    {
        std::vector<sf::Rect<double> > res;
        for(auto& v : list)
        {
<<<<<<< HEAD
//<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
            if(v.collid.width > 1 || v.collid.height > 1)
            {
                /**/
                if(v.collid.width > v.collid.height)
                {
                    if(o.testCollision(sf::Rect<double>(v.collid.left + tolerance, v.collid.top, v.collid.width - tolerance*2, v.collid.height), false))
                    {
                        res.push_back(v.collid);
<<<<<<< HEAD
                    }
=======
                    }   
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
                }
                else
                {
                    if(o.testCollision(sf::Rect<double>(v.collid.left, v.collid.top + tolerance, v.collid.width, v.collid.height - tolerance*2), false))
                    {
                        res.push_back(v.collid);
<<<<<<< HEAD
                    }
=======
                    }   
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
                }
                /**/
                /*
                if(o.testCollision(sf::Rect<double>(v.collid.left, v.collid.top, v.collid.width, v.collid.height), false))
                {
                    res.push_back(v.collid);
<<<<<<< HEAD
                }
                /**/
/*=======
            if(o.testCollision(v.collid, false))
            {
                res.push_back(v.collid);
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
                } 
                /**/
=======
            if(o.testCollision(v.collid, false))
            {
                res.push_back(v.collid);
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
            }
        }
        return res;
    }
<<<<<<< HEAD
//<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d

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
<<<<<<< HEAD
/*=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
};

std::vector<Platform> Platform::list;

class Room
{
public:
<<<<<<< HEAD
//<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d

    Object o;
    static std::vector<Room> list;

<<<<<<< HEAD
/*=======

    Object o;
    static std::vector<Room> list;

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
=======
    
    Object o;
    static std::vector<Room> list;    
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    Room(const Vector2f& pos, const Vector2i& size, const std::string& texture)
        : o(texture, sf::IntRect(0,0,size.x, size.y))
    {
        o.sprite.setPosition(pos);
    }
<<<<<<< HEAD
/*<<<<<<< HEAD

=======

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    static void add(const Vector2f& pos, const Vector2i& size, const std::string& texture)
    {
        list.push_back(Room(pos,size,texture));
    }
<<<<<<< HEAD
/*<<<<<<< HEAD

=======

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    static void draw(sf::RenderTarget& rt)
    {
        for(auto& i : list)
        {
            i.o.draw(rt);
        }
    }
<<<<<<< HEAD
/*<<<<<<< HEAD

=======

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    void cover()
    {
        //Platform::add(sf::Rect<double>(o.sprite.getPosition().x, o.sprite.getPosition().y, o.sprite.getTextureRect().width, 0.1));
        Platform::add(sf::Rect<double>(o.sprite.getPosition().x, o.sprite.getPosition().y, 0.1, o.sprite.getTextureRect().height));
        Platform::add(sf::Rect<double>(o.sprite.getPosition().x + o.sprite.getTextureRect().width, o.sprite.getPosition().y, 0.1, o.sprite.getTextureRect().height));
        Platform::add(sf::Rect<double>(o.sprite.getPosition().x, o.sprite.getPosition().y + o.sprite.getTextureRect().height, o.sprite.getTextureRect().width, 0.1));
    }
<<<<<<< HEAD
/*<<<<<<< HEAD

=======

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
<<<<<<< HEAD

=======
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    static void coverAll()
    {
        std::vector<Platform> horizontal, vertical;
        for(auto& r : list)
<<<<<<< HEAD
//<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
        {
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, r.o.sprite.getTextureRect().width, 0.1));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y + r.o.sprite.getTextureRect().height, r.o.sprite.getTextureRect().width, 0.1));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x + r.o.sprite.getTextureRect().width, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));

<<<<<<< HEAD
/*=======
        {
=======
=======
        {                
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, r.o.sprite.getTextureRect().width, 0.1));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));
            horizontal.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x + r.o.sprite.getTextureRect().width, r.o.sprite.getPosition().y, 0.1, r.o.sprite.getTextureRect().height));
            vertical.emplace_back(sf::Rect<double>(r.o.sprite.getPosition().x, r.o.sprite.getPosition().y + r.o.sprite.getTextureRect().height, r.o.sprite.getTextureRect().width, 0.1));
<<<<<<< HEAD

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
            
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
        }
        for(Platform& p : horizontal)
        {
            for(Platform& p2 : horizontal)
            {
                if(&p == &p2) continue;
<<<<<<< HEAD
//<<<<<<< HEAD
                if(std::abs(p.collid.top - p2.collid.top) > 0.001)
                    continue;
                if(!Collision::test(Vector2d(p.collid.left - 1, p.collid.left+p.collid.width + 1), Vector2d(p2.collid.left - 1, p2.collid.left + p2.collid.width + 1)))
=======
<<<<<<< HEAD
                if(std::abs(p.collid.top - p2.collid.top) > 0.001)
                    continue;
                if(!Collision::test(Vector2d(p.collid.left, p.collid.left+p.collid.width), Vector2d(p2.collid.left, p2.collid.left + p2.collid.width)))
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
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

<<<<<<< HEAD
                    //std::cout<<l.left<<" "<<l.width<<std::endl;
=======
                    std::cout<<l.left<<" "<<l.width<<std::endl;
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
                }
                else
                {
                    double tempLwidth = r.left - l.left;
                    double tempRleft  = r.left + r.width;
                    double tempRwidth = l.left + l.width - r.left - r.width;


<<<<<<< HEAD
/*=======
=======
=======
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
                if(std::abs(p.collid.top - p2.collid.top) < 0.001)
                    continue;
                if(!Collision::test(Vector2d(p.collid.left, p.collid.left+p.collid.width), Vector2d(p2.collid.left, p2.collid.left + p2.collid.width)))
                    continue;
<<<<<<< HEAD

                sf::Rect<double>& l = p.collid.left < p2.collid.left ? p.collid : p2.collid;
                sf::Rect<double>& r = p.collid.left < p2.collid.left ? p2.collid : p.collid;

=======
                
                sf::Rect<double>& l = p.collid.left < p2.collid.left ? p.collid : p2.collid;
                sf::Rect<double>& r = p.collid.left < p2.collid.left ? p2.collid : p.collid;
                
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
                if(l.left+l.width < r.left+r.width)
                {
                    double tempLwidth = l.width - (l.left + l.width) - r.left;
                    double tempRleft  = l.left + l.width;
                    double tempRwidth = r.width - (l.left + l.width) - r.left;
<<<<<<< HEAD

=======
                    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
                    l.width = tempLwidth;
                    r.left  = tempRleft;
                    r.width = tempRwidth;
                }
                else
                {
                    double tempLwidth = l.width - (l.left + l.width) - r.left;
                    double tempRleft  = r.left + r.width;
                    double tempRwidth = l.left + l.width - r.left - r.width;
<<<<<<< HEAD

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
                    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
                    l.width = tempLwidth;
                    r.left  = tempRleft;
                    r.width = tempRwidth;
                }
            }
<<<<<<< HEAD
//<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d

        }
        for(Platform& p : vertical)
        {
            for(Platform& p2 : vertical)
            {
                if(&p == &p2) continue;
                if(std::abs(p.collid.left - p2.collid.left) > 0.001)
                    continue;
<<<<<<< HEAD
                if(!Collision::test(Vector2d(p.collid.top - 1, p.collid.top+p.collid.height + 1), Vector2d(p2.collid.top - 1, p2.collid.top + p2.collid.height + 1)))
=======
                if(!Collision::test(Vector2d(p.collid.top, p.collid.top+p.collid.height), Vector2d(p2.collid.top, p2.collid.top + p2.collid.height)))
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
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

<<<<<<< HEAD
                    //std::cout<<l.top<<" "<<l.height<<std::endl;
=======
                    std::cout<<l.top<<" "<<l.height<<std::endl;
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
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

<<<<<<< HEAD
/*=======

        }

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
=======
            
        }
        
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
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
//<<<<<<< HEAD

    }

/*=======

    }

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
<<<<<<< HEAD

    }

=======
        
    }
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
};

std::vector<Room> Room::list;



#endif // ROOMS_HPP_INCLUDED
