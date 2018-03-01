#ifndef COLISIONS_HPP_INCLUDED
#define COLISIONS_HPP_INCLUDED

#include "Vectors.hpp"

template<class T>
class Circle
{
public:
    Vector2<T> center;
    T radius;
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    Circle(const Vector2<T>& v, T r)
        : center(v), radius(r)
    {}
};

<<<<<<< HEAD
//<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d


namespace Collision
{
<<<<<<< HEAD
/*=======
namespace Collision
{

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
=======
=======
namespace Collision
{
    
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    template<class A, class B>
    bool test(const Vector2<A>& seg, B point, bool inclusive = true)
    {
        if(inclusive)
<<<<<<< HEAD
        {
=======
        {            
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
            return  std::min(seg.x, seg.y) <= point &&
                    std::max(seg.x, seg.y) >= point;
        }
        else
<<<<<<< HEAD
        {
=======
        {            
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
            return  std::min(seg.x, seg.y) < point &&
                    std::max(seg.x, seg.y) > point;
        }
    }
    template<class A, class B>
    bool test(B point, const Vector2<A>& seg, bool inclusive = true){return test(seg,point,inclusive);}
<<<<<<< HEAD


=======
    
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    template<class A, class B>
    bool test(const Vector2<A>& a, const Vector2<B>& b, bool inclusive = true)
    {
        return  test(a, std::min(b.x, b.y), inclusive) ||
                test(b, std::min(a.x, a.y), inclusive);
    }
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    template<class A, class B>
    bool test(const sf::Rect<A>& a, const Vector2<B>& b, bool inclusive = true)
    {
        return  test(Vector2<A>(a.left, a.left + a.width), b.x, inclusive) &&
                test(Vector2<A>(a.top, a.top + a.height),  b.y, inclusive);
    }
    template<class A, class B>
    bool test(const Vector2<B>& b, const sf::Rect<A>& a, bool inclusive = true){return test(a, b, inclusive);}
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    template<class A, class B>
    bool test(const sf::Rect<A>& a, const sf::Rect<B>& b, bool inclusive = true)
    {
        return  test(Vector2<A>(a.left, a.left+a.width), Vector2<B>(b.left, b.left+b.width), inclusive) &&
                test(Vector2<A>(a.top,  a.top+a.height), Vector2<B>(b.top,  b.top+b.height), inclusive);
    }
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    template<class A, class B>
    bool test(const Circle<A>& a, const Vector2<B>& b, bool inclusive = true)
    {
        if(inclusive)
            return (b-a.center).magnatudeSquared() <= a.radius*a.radius;
        else
            return (b-a.center).magnatudeSquared() <  a.radius*a.radius;
    }
    template<class A, class B>
    bool test(const Vector2<B>& b, const Circle<A>& a, bool inclusive = true){return test(a, b, inclusive);}
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    template<class A, class B>
    bool test(const Circle<A>& a, const Circle<B>& b, bool inclusive = true)
    {
        if(inclusive)
            return (b.center-a.center).magnatudeSquared() <= (a.radius+b.radius)*(a.radius+b.radius);
        else
            return (b.center-a.center).magnatudeSquared() <  (a.radius+b.radius)*(a.radius+b.radius);
    }
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    template<class A, class B>
    bool test(const Circle<A>& a, const sf::Rect<B>& b, bool inclusive = true)
    {
        return  (test(Vector2<B>(b.left, b.left+b.width), a.center.x) && test(Vector2<B>(b.top-a.radius,  b.top+b.height+a.radius),  a.center.y)) ||
                (test(Vector2<B>(b.top,  b.top+b.height), a.center.y) && test(Vector2<B>(b.left-a.radius, b.left+b.width+a.radius),  a.center.x))  ||
                test(a, Vector2<B>(b.left,          b.top         )) ||
                test(a, Vector2<B>(b.left+b.width,  b.top         )) ||
                test(a, Vector2<B>(b.left,          b.top+b.height)) ||
                test(a, Vector2<B>(b.left+b.width,  b.top+b.height));
    }
    template<class A, class B>
    bool test(const sf::Rect<B>& b, const Circle<A>& a, bool inclusive = true){return test(a, b, inclusive);}
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
};

class Collider
{
public:
    virtual ~Collider(){};
    virtual bool test(Collider*, bool) = 0;
    virtual bool test(const sf::Rect<double>&, bool) =0;
    virtual bool test(const Circle<double>&, bool) =0;
    virtual void updateCollider(const sf::Sprite&) =0;
};

static Circle<double> _getUpdatedCollider( Circle<double> c, const sf::Sprite& s)
{
    c.center.x+=s.getPosition().x*s.getScale().x;
    c.center.y+=s.getPosition().y*s.getScale().y;
    c.radius *= s.getScale().x;
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    return c;
}
static sf::Rect<double> _getUpdatedCollider( sf::Rect<double> c, const sf::Sprite& s)
{
    c.left+=s.getPosition().x*s.getScale().x;
    c.top +=s.getPosition().y*s.getScale().y;
    c.width*=s.getScale().x;
    c.height*=s.getScale().y;
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    return c;
}

template<class T>
class ShapeCollider : public Collider
{
    T accCol;
public:
    T col;
    ShapeCollider(T c)
        : accCol(c), col(c)
    {}
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    virtual bool test(Collider* c, bool in = true)
    {
        return c->test(accCol, in);
    }
    virtual bool test(const sf::Rect<double>& c, bool in = true)
    {
        return Collision::test(accCol, c, in);
    }
    virtual bool test(const Circle<double>& c, bool in = true)
    {
        return Collision::test(accCol, c, in);
    }
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    virtual void updateCollider(const sf::Sprite& spr)
    {
        accCol = _getUpdatedCollider(col, spr);
    }
<<<<<<< HEAD

=======
    
>>>>>>> 8fc76f9217a2771ed04dd076ac4ffe143a3a092d
    virtual ~ShapeCollider(){};
};
#endif // COLISIONS_HPP_INCLUDED
