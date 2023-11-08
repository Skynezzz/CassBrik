#include "tiles.hpp"

Tiles::Tiles(float posX, float posY, int pLife) : GameObject(60*posX, 20*posY, 60, 20)
{
	life = pLife;
}

int Tiles::update(sf::Time deltaTime, sf::RenderWindow* window)
{
	if (life <= 0)
		return 1;

	return 0;
}
