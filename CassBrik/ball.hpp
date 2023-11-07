#pragma once

#include "gameObject.hpp"

class Ball : public GameObject
{
public:
	Ball(sf::RenderWindow* window);
	void update(sf::Time deltaTime);

private:

};