#ifndef VECTORS_HPP_INCLUDED
#define VECTORS_HPP_INCLUDED

#include <iostream>
#include <cmath>

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
    
    template<typename T_>
    Vector2<T> operator+(Vector2<T_> v)
    {
        return Vector2<T>(x + v.x, y + v.y);
    }
    template<typename T_>
    Vector2<T> operator-(Vector2<T_> v)
    {
        return Vector2<T>(x - v.x, y - v.y);
    }
    template<typename T_>
    Vector2<T> operator*(T_ s)
    {
        return Vector2<T>(x * s, y * s);
    }
    template<typename T_>
    Vector2<T> operator/(T_ s)
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
    
    long double magnatudeSquared();
    long double magnatude();
    Vector2<long double> normalize();
    Vector2<T>& normalizeSelf();
    Vector2<T> rotate(double angle);
    Vector2<T>& rotateSelf(double angle);
    
    
    
    void SHOW()
    {
        std::cout<<"("<<x<<" , "<<y<<")"<<std::endl;
    }
    
};

template<typename T>
long double Vector2<T>::magnatudeSquared()
{
    return x*x+y*y;
}

template<typename T>
long double Vector2<T>::magnatude()
{
    return std::sqrt(x*x+y*y);
}

template<typename T>
Vector2<long double> Vector2<T>::normalize()
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
Vector2<T> Vector2<T>::rotate(double angle)
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
Vector2<_T> operator*(T s, Vector2<_T> v)
{
    return Vector2<_T>(v.x * s, v.y * s);
}
template<typename T, typename _T>
Vector2<_T> operator/(T s, Vector2<_T> v)
{
    return Vector2<_T>(s / v.x, s / v.y);
}

using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned int>;
using Vector2ull = Vector2<unsigned long long>;
using Vector2d = Vector2<double>;
using Vector2f = Vector2<float>;
using Vector2ld = Vector2<long double>;

#endif // VECTORS_HPP_INCLUDED
