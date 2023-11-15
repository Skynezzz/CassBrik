#include "gameObject.hpp"
#include <iostream>

GameObject::GameObject(float pPos1, float pPos2, int pSize1, int pSize2, const char* path)
{

	position.x = pPos1;
	position.y = pPos2;
	size.x = pSize1;
	size.y = pSize2;

	shape = new sf::RectangleShape(sf::Vector2f(size.x, size.y));
	shape->setOrigin(pSize1/2, pSize2/2);
	shape->setPosition(position.x, position.y);
	shape->setFillColor(sf::Color::White);

	sf::Vector2f sizeSprite;
	sprite = new sf::Sprite(*TextureManager::getTexture(path));
	sizeSprite.x = (size.x / 225);
	sizeSprite.y = (size.y / 225);
	sprite->setScale(sizeSprite);
	sprite->setOrigin(pSize1 / 2, pSize2 / 2);
	sprite->setPosition(position.x, position.y);
}

GameObject::GameObject(float pPos1, float pPos2, int pSize1, int pSize2)
{

	position.x = pPos1;
	position.y = pPos2;
	size.x = pSize1;
	size.y = pSize2;

	shape = new sf::RectangleShape(sf::Vector2f(size.x, size.y));
	shape->setOrigin(pSize1/2, pSize2/2);
	shape->setPosition(position.x, position.y);
	shape->setFillColor(sf::Color::White);
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
	shape->setFillColor(sf::Color::Cyan);

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