#include "gameObject.hpp"
#include <iostream>

GameObject::GameObject(float pPos1, float pPos2, int pSize1, int pSize2)
{
	position.x = pPos1;
	position.y = pPos2;
	size.x = pSize1;
	size.y = pSize2;

	shape = new sf::RectangleShape(sf::Vector2f(size.x, size.y));
	shape->setPosition(position.x, position.y);
	shape->setFillColor(sf::Color::Red);
}

GameObject::GameObject(float pPos1, float pPos2, int pSize1)
{
	position.x = pPos1;
	position.y = pPos2;
	size.x = pSize1;
	size.y = pSize1;

	velocity = 30;

	shape = new sf::CircleShape(size.x);
	shape->setPosition(position.x, position.y);
	shape->setFillColor(sf::Color::Blue);
}

float GameObject::getVectorLenth(sf::Vector2f vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

bool GameObject::isCollidingOneD(sf::Vector2f objectOne, sf::Vector2f objectTwo)
{
	if (getVectorLenth(objectOne) > getVectorLenth(objectTwo))
		return isCollidingOneD(objectTwo, objectOne);
	
	return ((objectOne.x >= objectTwo.x and objectOne.x <= objectTwo.y) or (objectOne.y >= objectTwo.x and objectOne.y <= objectTwo.y));
}

bool GameObject::isColliding(GameObject* incomingObject)
{
	sf::Vector2f vectThisObject;
	sf::Vector2f vectIncomingObject;

	vectThisObject.x = position.x - size.x;
	vectThisObject.y = position.x + size.x;

	vectIncomingObject.x = incomingObject->position.x;
	vectIncomingObject.y = incomingObject->position.x + incomingObject->size.x;

	bool collideX = isCollidingOneD(vectIncomingObject, vectThisObject);

	vectThisObject.x = position.y - size.y;
	vectThisObject.y = position.y + size.y;

	vectIncomingObject.x = incomingObject->position.y;
	vectIncomingObject.y = incomingObject->position.y + incomingObject->size.y;

	bool collideY = isCollidingOneD(vectIncomingObject, vectThisObject);

	if (collideX and collideY)
		int a = 0;

	return (collideX and collideY);
}
