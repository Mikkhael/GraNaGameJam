#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "Vectors.hpp"
#include "TextureManager.hpp"
#include "Animations.hpp"


class Object
{
public:
    sf::Sprite sprite;
    std::string name;
    
    Animation* animation = nullptr;
    void setAnimation(AnimationPreset ap)
    {
        if(animation == nullptr)
        {
            animation = new Animation(ap);
        }
        else
        {
            animation->setPreset(ap);
        }
    }
    
    virtual void update(double deltaTime)
    {
        return;
    }
    virtual void draw(sf::RenderTarget& rt)
    {
            rt.draw(sprite);
    }
    
    void setSize(const sf::IntRect& rect)
    {
        sprite.setTextureRect(rect);
    }
    
    Object(const char* texture, const std::string& n = "")
        : name(n)
    {
        sprite.setTexture(textureManager.get(texture));
    }
    
    Object(const char* texture, const AnimationPreset& ap, const std::string& n = "")
        : name(n)
    {
        sprite.setTexture(textureManager.get(texture));
        animation = new Animation(ap);
    }
    
    Object(const char* texture, const sf::IntRect& rect, const std::string& n = "")
        : name(n)
    {
        sprite.setTexture(textureManager.get(texture));
        sprite.setTextureRect(rect);
    }
    
    ~Object()
    {
        if(animation != nullptr)
            delete animation;
    }
    
};

#endif // OBJECT_HPP_INCLUDED
