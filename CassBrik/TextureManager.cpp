#include "TextureManager.hpp"

sf::Sprite* TextureManager::getSprite(std::string path)
{
    if (checkSprite(path))
        loadNewSprite(path);

    //return findSprite(path);
    return sf::Sprite*;
}

bool TextureManager::checkSprite(std::string path)
{
    return sprites[path];
}

int loadNewSprite(std::string path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(path))
    {
        return 1;
    }

    sf::Sprite sprite(texture);

    sprites[path] = sprite;

    return 0;
}

static sf::Sprite* TextureManager::findSprite(std::string path)
{
    if (sprites[path])
        return sprites[path];

    return nullptr;
}