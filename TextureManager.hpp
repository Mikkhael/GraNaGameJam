#ifndef TEXTUREMANAGER_HPP_INCLUDED
#define TEXTUREMANAGER_HPP_INCLUDED
#include <map>

class TextureManager
{
public:
    
    static bool ALLREPEAT;
    
    std::map<const char*, sf::Texture*> textures;
    
    
    void load(const char* path)
    {
        sf::Texture* T = new sf::Texture;
        T->loadFromFile(path);
        if(ALLREPEAT)
        {
            T->setRepeated(true);
        }
        textures[path] = T;
    }
    
    
    sf::Texture& get(const char* path)
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
