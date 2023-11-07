#include "ball.hpp"
#include <iostream>

Ball::Ball(sf::RenderWindow* window) : GameObject(310.f, 470.f, 10)
{
	sf::Vector2i direction;
	direction.x = sf::Mouse::getPosition(*window).x - shape->getPosition().x;
	direction.y = (sf::Mouse::getPosition(*window).y - shape->getPosition().y);
	float norme = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	vect.x = direction.x / norme;
	vect.y = direction.y / norme;
	std::cout << vect.x << " / " << vect.y << std::endl;
}

void Ball::update(sf::Time deltaTime)
{
	move(deltaTime);
}