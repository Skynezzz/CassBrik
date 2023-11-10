#include "tiles.hpp"

Tiles::Tiles(float posX, float posY, int pLife) : GameObject(40*posX, 20*posY, 40, 20)
{
	life = pLife;
}

bool Tiles::update(sf::Time deltaTime, sf::RenderWindow* window)
{
	if (life <= 0)
		return true;

	return false;
}
