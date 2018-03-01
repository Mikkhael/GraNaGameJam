#ifndef LIGHTS_HPP_INCLUDED
#define LIGHTS_HPP_INCLUDED

#include "Vectors.hpp"
#include "Rooms.hpp"
class LightEmmition
{
public:
    
    sf::RenderTexture texture;
    sf::Sprite sprite;
    
};
    
void emitLight(sf::RenderTarget& rt, LightEmmition& le, const Vector2d& pos, double range)
{
    
    
    sf::CircleShape c;
    c.setFillColor(sf::Color::White);
    c.setRadius(range);
    c.setOrigin(range, range);
    c.setPosition(pos.x, pos.y);
    
    
    le.texture.clear(sf::Color::Black);
    le.texture.draw(c);
    
    //std::cout<<c.getPosition().x<<" "<<c.getPosition().y<<std::endl;
    
    sf::VertexArray shadow(sf::TriangleStrip, 4);
    shadow[0].color = sf::Color::Black;
    shadow[1].color = sf::Color::Black;
    shadow[2].color = sf::Color::Black;
    shadow[3].color = sf::Color::Black;
    
    Vector2d a, b;
    for(auto& rect : Platform::list)
    {
        if(rect.collid.width < 0.1 && rect.collid.height < 0.1)
            continue;
        a = Vector2d(rect.collid.left, rect.collid.top);
        if(rect.collid.width > rect.collid.height)
        {
            b = Vector2d(rect.collid.left+rect.collid.width, rect.collid.top);
        }
        else
        {
            b = Vector2d(rect.collid.left, (rect.collid.top + rect.collid.height));
        }
        
        shadow[0].position = sf::Vector2f(a);
        shadow[1].position = sf::Vector2f(b);
        shadow[2].position = sf::Vector2f(pos + (a-pos).normalize()*range*4);
        shadow[3].position = sf::Vector2f(pos + (b-pos).normalize()*range*4);
        le.texture.draw(shadow);
    }
    le.texture.display();
    le.sprite.setTexture(le.texture.getTexture());
    le.sprite.setTextureRect(sf::IntRect(0, le.texture.getSize().y,le.texture.getSize().x, -le.texture.getSize().y));
    rt.draw(le.sprite);
    
}
#endif // LIGHTS_HPP_INCLUDED
