#ifndef VECTORS_HPP_INCLUDED
#define VECTORS_HPP_INCLUDED

#include <iostream>
#include <cmath>

#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_180   0.01745329251994329577

#define TORAD(x) x*M_PI_180

template<typename T>
class Vector2
{
public:
    
    T x;
    T y;

    Vector2(){}
    Vector2(T _x, T _y)
        : x(_x), y(_y)
    {}
    
    template<typename _T>
    Vector2(const sf::Vector2<_T>& v)
        : x(v.x), y(v.y)
    {}
    
    template<typename T_>
    Vector2<T> operator+(Vector2<T_> v) const
    {
        return Vector2<T>(x + v.x, y + v.y);
    }
    template<typename T_>
    Vector2<T> operator-(Vector2<T_> v) const
    {
        return Vector2<T>(x - v.x, y - v.y);
    }
    template<typename T_>
    Vector2<T> operator*(T_ s) const
    {
        return Vector2<T>(x * s, y * s);
    }
    template<typename T_>
    Vector2<T> operator/(T_ s) const
    {
        return Vector2<T>(x / s, y / s);
    }
    
    template<typename T_>
    Vector2<T>& operator+=(Vector2<T_> v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    template<typename T_>
    Vector2<T>& operator-=(Vector2<T_> v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    template<typename T_>
    Vector2<T>& operator*=(T_ s)
    {
        x *= s;
        y *= s;
        return *this;
    }
    template<typename T_>
    Vector2<T>& operator/=(T_ s)
    {
        x /= s;
        y /= s;
        return *this;
    }
    
    long double magnatudeSquared() const;
    long double magnatude() const;
    Vector2<long double> normalize() const;
    Vector2<T>& normalizeSelf();
    Vector2<T> rotate(double angle) const;
    Vector2<T>& rotateSelf(double angle);
    
    template<typename _T>
    operator sf::Vector2<_T>() const
    {
        return sf::Vector2<_T>(x, y);
    }
    
    
    void SHOW()
    {
        std::cout<<"("<<x<<" , "<<y<<")"<<std::endl;
    }
    
};

template<typename T>
long double Vector2<T>::magnatudeSquared() const
{
    return x*x+y*y;
}

template<typename T>
long double Vector2<T>::magnatude() const
{
    return std::sqrt(x*x+y*y);
}

template<typename T>
Vector2<long double> Vector2<T>::normalize() const
{
    auto mag = magnatude();
    return Vector2<long double>(x/mag, y/mag);
}

template<typename T>
Vector2<T>& Vector2<T>::normalizeSelf()
{
    auto mag = magnatude();
    x /= mag;
    y /= mag;
    return *this;    
}

template<typename T>
Vector2<T> Vector2<T>::rotate(double angle) const
{
    auto c = std::cos(angle);
    auto s = std::sin(angle);
    return Vector2<T>(c*x-s*y, c*y+s*x);
}

template<typename T>
Vector2<T>& Vector2<T>::rotateSelf(double angle)
{
    auto c = std::cos(angle);
    auto s = std::sin(angle);
    auto tx = x;
    x = c*x-s*y;
    y = c*y+s*tx;
    return *this;
}

template<typename T, typename _T>
Vector2<_T> operator*(T s, const Vector2<_T>& v)
{
    return Vector2<_T>(v.x * s, v.y * s);
}
template<typename T, typename _T>
Vector2<_T> operator/(T s, const Vector2<_T>& v)
{
    return Vector2<_T>(s / v.x, s / v.y);
}

using Vector2i      = Vector2<int>;
using Vector2u      = Vector2<unsigned int>;
using Vector2ull    = Vector2<unsigned long long>;
using Vector2d      = Vector2<double>;
using Vector2f      = Vector2<float>;
using Vector2ld     = Vector2<long double>;

namespace Vectors
{
    const Vector2d foreward(1,0);
    const Vector2d backward(-1,0);
    const Vector2d up(0,1);
    const Vector2d down(0,-1);
    const Vector2d units(1,1);
    const Vector2d null(0,0);
}

#endif // VECTORS_HPP_INCLUDED
