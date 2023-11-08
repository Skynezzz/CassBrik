#pragma once

#include "gameObject.hpp"

class Ball : public GameObject
{
public:
	Ball(sf::RenderWindow* window);
	int update(sf::Time deltaTime, sf::RenderWindow* window) override;
	void move(sf::Time deltaTime, sf::RenderWindow* window);

private:

};