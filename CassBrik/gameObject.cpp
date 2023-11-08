#include "gameObject.hpp"
#include <iostream>

GameObject::GameObject(float pPos1, float pPos2, int pSize1, int pSize2)
{

	position.x = pPos1;
	position.y = pPos2;
	size.x = pSize1;
	size.y = pSize2;

	shape = new sf::RectangleShape(sf::Vector2f(size.x, size.y));
	shape->setOrigin(pSize1/2, pSize2/2);
	shape->setPosition(position.x, position.y);
	shape->setFillColor(sf::Color::Red);
}

GameObject::GameObject(float pPos1, float pPos2, int pSize1)
{
	position.x = pPos1;
	position.y = pPos2;
	size.x = pSize1;
	size.y = pSize1;

	velocity = 500;

	shape = new sf::CircleShape(size.x / 2);
	shape->setOrigin(pSize1 / 2, pSize1 / 2);
	shape->setPosition(position.x, position.y);
	shape->setFillColor(sf::Color::Blue);

	hitbox = new sf::RectangleShape(sf::Vector2f(size.x, size.y));
	hitbox->setOrigin(pSize1 / 2, pSize1 / 2);
	hitbox->setPosition(position.x, position.y);
	hitbox->setFillColor(sf::Color::Green);
}

sf::Vector2f GameObject::getMinMaxX() {
	sf::Vector2f returnVect;
	returnVect.x = position.x - size.x / 2;
	returnVect.y = position.x + size.x / 2;
	return returnVect;
}

sf::Vector2f GameObject::getMinMaxY() {
	sf::Vector2f returnVect;
	returnVect.x = position.y - size.y / 2;
	returnVect.y = position.y + size.y / 2;
	return returnVect;
}

float GameObject::getVectorLenth(sf::Vector2f vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

bool GameObject::isCollidingOneD(sf::Vector2f objectOne, sf::Vector2f objectTwo)
{
	if (objectOne.y - objectOne.x > objectTwo.y - objectTwo.x)
		return isCollidingOneD(objectTwo, objectOne);
	
	return ((objectOne.x >= objectTwo.x and objectOne.x <= objectTwo.y) or (objectOne.y >= objectTwo.x and objectOne.y <= objectTwo.y));
}

bool GameObject::isColliding(GameObject* incomingObject)
{
	bool collideX = isCollidingOneD(incomingObject->getMinMaxX(), getMinMaxX());

	hitbox->setPosition(position.x, position.y);

	bool collideY = isCollidingOneD(incomingObject->getMinMaxY(), getMinMaxY());

	return (collideX and collideY);
}

sf::Vector2f GameObject::getBounceDirection(GameObject* incomingObject)
{
	sf::Vector2f returnVect;

	return returnVect;
}

void GameObject::bounce(sf::Vector2f direction)
{
}

void GameObject::checkBounce(GameObject* incomingObject)
{
	if (!isColliding(incomingObject))
		return;

	bounce(getBounceDirection(incomingObject));
}
