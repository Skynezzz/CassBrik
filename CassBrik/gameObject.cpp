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


// Position //

void GameObject::move(sf::Time deltaTime)
{
	position.x += vect.x * velocity * deltaTime.asSeconds();
	position.y += vect.y * velocity * deltaTime.asSeconds();

	shape->setPosition(position.x, position.y);
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


// Vector //

float GameObject::getVectorLenth(sf::Vector2f vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}


// Collides //

bool GameObject::isOutScreen(sf::RenderWindow* window)
{
	if (getMinMaxX().x < 0 or getMinMaxX().y > window->getSize().x or getMinMaxY().x < 0)
		return true;

	return false;
}

bool GameObject::isColliding(GameObject* incomingObject)
{
	bool collideX = isCollidingOneD(incomingObject->getMinMaxX(), getMinMaxX());

	bool collideY = isCollidingOneD(incomingObject->getMinMaxY(), getMinMaxY());

	return (collideX and collideY);
}

bool GameObject::isCollidingOneD(sf::Vector2f objectOne, sf::Vector2f objectTwo)
{
	if (objectOne.y - objectOne.x > objectTwo.y - objectTwo.x)
		return isCollidingOneD(objectTwo, objectOne);
	
	return ((objectOne.x >= objectTwo.x and objectOne.x <= objectTwo.y) or (objectOne.y >= objectTwo.x and objectOne.y <= objectTwo.y));
}


// Bounce //

void GameObject::checkBounce(GameObject* incomingObject, sf::RenderWindow* window)
{
	if (isOutScreen(window))
		bounce(getWindowBorderBounceDirection(window));

	if (isColliding(incomingObject))
	{
		bounce(getBounceDirection(incomingObject));
		incomingObject.getDamage();
	}
}

void GameObject::bounce(sf::Vector2f direction)
{
	std::cout << "X : " << direction.x << std::endl << "Y : " << direction.y << std::endl;

	if (direction.x != 0)
		vect.x = -vect.x;
	else if (direction.y != 0)
		vect.y = -vect.y;
	return;
}

sf::Vector2f GameObject::getBounceDirection(GameObject* incomingObject)
{
	sf::Vector2f returnVect;
	returnVect.x = -1;
	returnVect.y = -1;

	float left = abs(getMinMaxX().y - incomingObject->getMinMaxX().x);
	float right = abs(getMinMaxX().x - incomingObject->getMinMaxX().y);
	float up = abs(getMinMaxY().y - incomingObject->getMinMaxY().x);
	float down = abs(getMinMaxY().x - incomingObject->getMinMaxY().y);
	float xMin = left;
	float yMin = up;

	if (left > right) {
		xMin = right;
		returnVect.x = 1;
	}
	if (up > down) {
		yMin = down;
		returnVect.y = 1;
	}
	if (xMin > yMin) {
		returnVect.x = 0;
	}
	else {
		returnVect.y = 0;
	}

	return returnVect;
}

sf::Vector2f GameObject::getWindowBorderBounceDirection(sf::RenderWindow* window)
{
	sf::Vector2f bounceDirection;

	if (getMinMaxX().x < 0)
		bounceDirection.x = 1;

	else if (getMinMaxX().y > window->getSize().x)
		bounceDirection.x = -1;

	if (getMinMaxY().x < 0)
		bounceDirection.y = 1;

	return bounceDirection;
}
