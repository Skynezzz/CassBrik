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
	velocity = 100;

	size[0] = pSize1;

	shape = new sf::CircleShape(pSize1);
	shape->setPosition(pPos1, pPos2);
	shape->setFillColor(sf::Color::Blue);
}

void GameObject::move(sf::Time deltaTime)
{
	shape->setPosition(shape->getPosition().x + vect.x * velocity * deltaTime.asSeconds(), shape->getPosition().y + vect.y * velocity * deltaTime.asSeconds());
}