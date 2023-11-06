#include "canon.hpp"
#include <iostream>
#include <cmath>

void Canon::update(sf::Time deltaTime)
{
	float opp = sf::Mouse::getPosition().x - shape->getPosition().x;
	float adj = sf::Mouse::getPosition().y - shape->getPosition().y;
	float angle = std::atan(opp / adj);

	std::cout << "Rotating by" << angle << std::endl << "With arctan(" << opp / adj << ")" << std::endl;
	shape->rotate(angle);
}