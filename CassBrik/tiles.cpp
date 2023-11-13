#include "tiles.hpp"

Tiles::Tiles(float posX, float posY, int pLife) : GameObject(40*posX, 20*posY, 40, 20)
{
	life = pLife;
}

bool Tiles::update(sf::Time deltaTime, sf::RenderWindow* window)
{
	if (life <= 0)
		return true;

	switch (life)
	{
	case 4:
		shape->setFillColor(sf::Color::Blue);
		break;
	case 3:
		shape->setFillColor(sf::Color::Green);
		break;
	case 2:
		shape->setFillColor(sf::Color::Yellow);
		break;
	case 1:
		shape->setFillColor(sf::Color::Red);
		break;
	default:
		break;
	}

	return false;
}
