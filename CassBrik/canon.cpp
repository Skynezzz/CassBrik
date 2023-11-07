#include "canon.hpp"
#include <iostream>

void Canon::update(sf::Time deltaTime, sf::RenderWindow* window)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(*window);
	sf::Vector2f baseCanon = shape->getPosition();

	if (window->getSize().x < mouse.x and mouse.x < 0 and 0 > mouse.y and mouse.y > window->getSize().y)
		return;

	float opp = mouse.x - baseCanon.x;
	float adj = mouse.y - baseCanon.y;
	float angle = - atan(opp / adj) * 180 / 3.14;

	shape->rotate(angle - initAngle);
	initAngle = angle;
}
