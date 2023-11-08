#include "ball.hpp"
#include <iostream>

Ball::Ball(sf::RenderWindow* window) : GameObject(320.f, 480.f, 20)
{
	sf::Vector2f direction;
	direction.x = sf::Mouse::getPosition(*window).x - shape->getPosition().x;
	direction.y = (sf::Mouse::getPosition(*window).y - shape->getPosition().y);
	float norme = getVectorLenth(direction);
	vect.x = direction.x / norme;
	vect.y = direction.y / norme;
	std::cout << vect.x << " / " << vect.y << std::endl;
}

int Ball::update(sf::Time deltaTime, sf::RenderWindow* window)
{
	move(deltaTime, window);
	//std::cout << shape->getPosition().x << " / " << shape->getPosition().y << std::endl;

	if (position.y > window->getSize().y)
		return 1;

	return 0;
}

void Ball::move(sf::Time deltaTime, sf::RenderWindow* window)
{
	sf::Vector2f nextPosition;
	nextPosition.x = position.x + vect.x * velocity * deltaTime.asSeconds();
	nextPosition.y = position.y + vect.y * velocity * deltaTime.asSeconds();

	sf::Vector2f add;
	add.x = vect.x * velocity * deltaTime.asSeconds();
	add.y = vect.y * velocity * deltaTime.asSeconds();

	if (nextPosition.x - size.x < 0) {
		add.x = -add.x;
		float xOut = position.x - size.x;
		position.x = size.x + add.x - 2 * xOut;
		vect.x = -vect.x;
		std::cout << vect.x << std::endl;
	}
	else if (nextPosition.x + size.x > window->getSize().x) {
		add.x = -add.x;
		float xOut = window->getSize().x - (position.x + size.x);
		position.x = window->getSize().x - size.x + (add.x + 2 * xOut);
		vect.x = -vect.x;
	}
	else {
		position.x = nextPosition.x;
	}

	if (nextPosition.y - size.y < 0) {
		add.y = -add.y;
		float yOut = position.y - size.y;
		position.y = size.y + add.y - 2 * yOut;
		vect.y = -vect.y;
	}
	else {
		position.y = nextPosition.y;
	}

	shape->setPosition(position.x, position.y);
}