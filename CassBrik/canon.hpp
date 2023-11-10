#pragma once

#include "gameObject.hpp"

class Canon : public GameObject
{
public:
	Canon() : GameObject(320.f, 480.f, 20, 40) { shape->setOrigin(10, 40); };
	bool update(sf::Time deltaTime, sf::RenderWindow* window) override;

private:
	float initAngle = 0;

};