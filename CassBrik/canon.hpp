#pragma once

#include "gameObject.hpp"

class Canon : public GameObject
{
public:
	Canon() : GameObject(320.f, 480.f, 20, 40) { shape->setOrigin(10, 40); };
	void update(sf::Time deltaTime, sf::RenderWindow* window);

private:
	float initAngle = 0;

};