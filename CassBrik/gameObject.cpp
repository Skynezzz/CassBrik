#include "gameObject.hpp"
#include <iostream>

GameObject::GameObject(float pPos1, float pPos2, int pSize1, int pSize2)
{
	size[0] = pSize1;
	size[1] = pSize2;
	pos[0] = pPos1;
	pos[1] = pPos2;

	shape = new sf::RectangleShape(sf::Vector2f(pSize1, pSize2));
	shape->setPosition(pPos1, pPos2);
	shape->setFillColor(sf::Color::Red);
}

GameObject::GameObject(float pPos1, float pPos2, int pSize1)
{
	vect[0] = 0;
	vect[1] = -1;
	velocity = 100;

	//pos[0] = pPos1;
	//pos[1] = pPos2;
	//size[0] = pSize1;

	shape = new sf::CircleShape(pSize1);
	shape->setPosition(pPos1, pPos2);
	shape->setFillColor(sf::Color::Blue);
}

void GameObject::move(sf::Time deltaTime)
{
	//pos[0] = pos[0] + vect[0] * velocity * deltaTime.asSeconds();
	//pos[1] = pos[1] + vect[1] * velocity * deltaTime.asSeconds();
	//shape->setPosition(pos[0], pos[1]);

	shape->setPosition(shape->getPosition().x + vect[0] * velocity * deltaTime.asSeconds(), shape->getPosition().y + vect[1] * velocity * deltaTime.asSeconds());
}