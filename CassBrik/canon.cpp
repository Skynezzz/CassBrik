#include "canon.hpp"
#include <iostream>

int Canon::update(sf::Time deltaTime, sf::RenderWindow* window)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(*window);
	sf::Vector2f baseCanon = shape->getPosition();

	if (window->getSize().x < mouse.x or mouse.x < 0 or 0 > mouse.y or mouse.y > window->getSize().y)
		return 0;

	float opp = mouse.x - baseCanon.x;
	float adj = mouse.y - baseCanon.y;

	//std::cout << atan2(opp, adj) * 180 / 3.14 << std::endl;

	float angle = -atan(opp / adj) * 180 / 3.14;

	shape->setRotation(angle);
	initAngle = angle;

	return 0;
}
