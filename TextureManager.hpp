#ifndef TEXTUREMANAGER_HPP_INCLUDED
#define TEXTUREMANAGER_HPP_INCLUDED
#include <map>

class TextureManager
{
public:
    
    static bool ALLREPEAT;
    
    std::map<const std::string, sf::Texture*> textures;
    
    
    void load(const std::string& path)
    {
        sf::Image img;
        img.loadFromFile(path);
        img.createMaskFromColor(sf::Color::Magenta);
        sf::Texture* T = new sf::Texture;
        T->loadFromImage(img);
        if(ALLREPEAT)
        {
            T->setRepeated(true);
        }
        textures[path] = T;
    }
    
    
    sf::Texture& get(const std::string& path)
    {
        if(textures.find(path) == textures.end())
        {
            load(path);
        }
        return *textures[path];
    }
    
};

bool TextureManager::ALLREPEAT = true;

TextureManager textureManager;

#endif // TEXTUREMANAGER_HPP_INCLUDED
