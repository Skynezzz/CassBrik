#pragma once

#include "gameObject.hpp"

class Ball : public GameObject
{
public:
	Ball() : GameObject(310.f, 470.f, 10) {};
	void update(sf::Time deltaTime);

private:

};