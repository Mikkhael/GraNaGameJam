#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

double gravity = 1000;
double drag    = 0.0001;

#include "Vectors.hpp"
#include "TextureManager.hpp"
#include "Animations.hpp"
#include "Colisions.hpp"
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> cda4541f802314c0a6a217b49e8c933fbeb5f1be

void flip(sf::Sprite& s)
{
    auto r = s.getTextureRect();
    s.setTextureRect(sf::IntRect(r.left + r.width, r.top, -r.width, r.height));
}


=======

void flip(sf::Sprite& s)
{
    auto r = s.getTextureRect();
    s.setTextureRect(sf::IntRect(r.left + r.width, r.top, -r.width, r.height));
}


>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
Vector2d getMouse(const sf::RenderWindow& rt)
{
    auto m = sf::Mouse::getPosition(rt);
    return Vector2d(m.x, m.y);
}

Vector2d getRealMouse(const sf::RenderWindow& rt)
{
    auto m = sf::Mouse::getPosition(rt);
    return Vector2d(m.x * rt.getView().getSize().x / rt.getSize().x, m.y * rt.getView().getSize().y / rt.getSize().y);
}
<<<<<<< HEAD
<<<<<<< HEAD

Vector2d mouseRealPosition(0,0);
=======
=======

Vector2d mouseRealPosition(0,0);
=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
=======

void flip(sf::Sprite& s)
{
    auto r = s.getTextureRect();
    s.setTextureRect(sf::IntRect(r.left + r.width, r.top, -r.width, r.height));
}


Vector2d getMouse(const sf::RenderWindow& rt)
{
    auto m = sf::Mouse::getPosition(rt);
    return Vector2d(m.x, m.y);
}

Vector2d getRealMouse(const sf::RenderWindow& rt)
{
    auto m = sf::Mouse::getPosition(rt);
    return Vector2d(m.x * rt.getView().getSize().x / rt.getSize().x, m.y * rt.getView().getSize().y / rt.getSize().y);
}
>>>>>>> cda4541f802314c0a6a217b49e8c933fbeb5f1be
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957

class Object
{
public:
    sf::Sprite sprite;
    std::string name;

    Animation* animation = nullptr;
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> cda4541f802314c0a6a217b49e8c933fbeb5f1be
    void setAnimation(const AnimationPreset& ap, const AnimationState state = Once)
=======
    void setAnimation(AnimationPreset ap, AnimationState state = Once)
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
<<<<<<< HEAD
=======
=======
    void setAnimation(AnimationPreset ap, AnimationState state = Once)
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
>>>>>>> cda4541f802314c0a6a217b49e8c933fbeb5f1be
    {
        if(animation == nullptr)
        {
            animation = new Animation(ap);
        }
        else
        {
            animation->setPreset(ap);
        }
        animation->state = state;
<<<<<<< HEAD
<<<<<<< HEAD
=======
    }
    
    Collider* collider = nullptr;
    template<class T>
    void setCollider(T c)
    {
        if(collider == nullptr)
        {
            collider = new ShapeCollider<T>(c);
        }
        else
        {
            delete collider;
            collider = new ShapeCollider<T>(c);
        }
    }
    void updateCollider()
    {
        collider->updateCollider(sprite);
    }
    bool testCollision(Object& o, bool inclusive = true)
    {
        updateCollider();
        o.updateCollider();
        return collider->test(o.collider, inclusive);
    }
    template<class T>
    bool testCollision(const T& o, bool inclusive = true)
    {
        updateCollider();
        return collider->test(o, inclusive);
    }
    
=======
<<<<<<< HEAD
=======
=======
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    }
    
    Collider* collider = nullptr;
    template<class T>
    void setCollider(T c)
    {
        if(collider == nullptr)
        {
            collider = new ShapeCollider<T>(c);
        }
        else
        {
            delete collider;
            collider = new ShapeCollider<T>(c);
        }
    }
    void updateCollider()
    {
        collider->updateCollider(sprite);
    }
    bool testCollision(Object& o, bool inclusive = true)
    {
        updateCollider();
        o.updateCollider();
        return collider->test(o.collider, inclusive);
    }
    template<class T>
    bool testCollision(const T& o, bool inclusive = true)
    {
        updateCollider();
        return collider->test(o, inclusive);
<<<<<<< HEAD
=======
    }
    
    
    void base_update(double deltaTime)
    {
        if(animation != nullptr)
        {
            animation->update(deltaTime);
        }
        
        update(deltaTime);
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    }
    
>>>>>>> cda4541f802314c0a6a217b49e8c933fbeb5f1be
    
    void base_update(double deltaTime)
    {
        if(animation != nullptr)
        {
            animation->update(deltaTime);
        }
        
        update(deltaTime);
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    }

    Collider* collider = nullptr;
    template<class T>
    void setCollider(T c)
    {
        if(collider == nullptr)
        {
            collider = new ShapeCollider<T>(c);
        }
        else
        {
            delete collider;
            collider = new ShapeCollider<T>(c);
        }
    }
    void updateCollider()
    {
        collider->updateCollider(sprite);
    }
    bool testCollision(Object& o, bool inclusive = true)
    {
        if(collider == nullptr || o.collider == nullptr)
        {
            return false;
        }
        updateCollider();
        o.updateCollider();
        return collider->test(o.collider, inclusive);
    }
    template<class T>
    bool testCollision(const T& o, bool inclusive = true)
    {
        updateCollider();
        return collider->test(o, inclusive);
    }


    void base_update(double deltaTime)
    {
        if(animation != nullptr)
        {
            animation->update(deltaTime);
        }

        update(deltaTime);
    }

    virtual void update(double deltaTime)
    {

        return;
    }
    virtual void draw(sf::RenderTarget& rt)
    {
        if(animation != nullptr)
        {
            sprite.setTextureRect(animation->get());
        }
        rt.draw(sprite);
    }

    void setSize(const sf::IntRect& rect)
    {
        sprite.setTextureRect(rect);
    }
<<<<<<< HEAD

    Object()
        : name("")
    {}

=======
<<<<<<< HEAD
    
    Object()
        : name("")
    {}
    
=======
    
    Object()
        : name("")
    {}
    
<<<<<<< HEAD
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
=======
>>>>>>> cda4541f802314c0a6a217b49e8c933fbeb5f1be
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    Object(const std::string& texture, const std::string& n = "")
        : name(n)
    {
        sprite.setTexture(textureManager.get(texture));
    }
<<<<<<< HEAD

=======
    
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
=======
>>>>>>> cda4541f802314c0a6a217b49e8c933fbeb5f1be
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    Object(const std::string& texture, const AnimationPreset& ap, const std::string& n = "", AnimationState state=Loop)
        : name(n)
    {
        sprite.setTexture(textureManager.get(texture));
        animation = new Animation(ap);
        animation->state = state;
    }
<<<<<<< HEAD

=======
    
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
=======
>>>>>>> cda4541f802314c0a6a217b49e8c933fbeb5f1be
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    Object(const std::string& texture, const sf::IntRect& rect, const std::string& n = "")
        : name(n)
    {
        sprite.setTexture(textureManager.get(texture));
        sprite.setTextureRect(rect);
    }
<<<<<<< HEAD

=======
    
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
=======
>>>>>>> cda4541f802314c0a6a217b49e8c933fbeb5f1be
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
    virtual ~Object()
    {
        if(animation != nullptr)
            delete animation;
    }
    
};

#endif // OBJECT_HPP_INCLUDED
