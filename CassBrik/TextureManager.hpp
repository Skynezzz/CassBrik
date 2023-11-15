#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class TextureManager
{
public:
	static sf::Sprite* getSprite(std::string path);

private:
	static bool checkSprite(std::string path);
	static int loadNewSprite(std::string path);
	static sf::Sprite* findSprite(std::string path);
	static std::vector<sf::Sprite*> sprites;

};