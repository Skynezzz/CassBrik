#include "gameObject.hpp"

GameObject::GameObject(int pSize, float pPos1, float pPos2)
{
	size[0] = pSize;
	pos[0] = pPos1;
	pos[1] = pPos2;

	shape = new sf::CircleShape(100.f);
	shape->setPosition(0.f, 0.f);
	shape->setFillColor(sf::Color::Green);
}

GameObject::GameObject(int pSize1, int pSize2, float pPos1, float pPos2)
{
	size[0] = pSize1;
	size[1] = pSize2;
	pos[0] = pPos1;
	pos[1] = pPos2;

	shape = new sf::RectangleShape(sf::Vector2f(50.f, 50.f));
	shape->setPosition(100.f, 100.f);
	shape->setFillColor(sf::Color::Red);
}

void GameObject::move()
{
	shape->setPosition(pos[0], pos[1]);
}
