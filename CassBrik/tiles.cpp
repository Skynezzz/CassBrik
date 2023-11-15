#include "tiles.hpp"
#include <iostream>

Tiles::Tiles(float posX, float posY, int pLife) : GameObject(64*posX + 32, 25*posY + 12, 60, 20)
{
	maxLife = pLife;
	life = pLife;
}

bool Tiles::update(sf::Time deltaTime, sf::RenderWindow* window)
{
	if (life <= 0)
		return true;

	float colorLife = life * 100 / maxLife;  

	if (life == maxLife)
		return false;

	if (colorLife > 75)
	{
		shape->setFillColor(sf::Color::Blue);
		return false;
	}
	if (colorLife > 50)
	{
		shape->setFillColor(sf::Color::Green);
		return false;
	}
	if (colorLife > 25)
	{
		shape->setFillColor(sf::Color::Yellow);
		return false;
	}
	if (colorLife > 0)
	{
		shape->setFillColor(sf::Color::Red);
		return false;
	}

	return false;
}
