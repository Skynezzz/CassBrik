#pragma once

#include "gameObject.hpp"

class Ball : public GameObject
{
public:
	Ball(sf::RenderWindow* window);
	bool update(sf::Time deltaTime, sf::RenderWindow* window) override;
	bool isUnderScreen(sf::RenderWindow* window);
	//void move(sf::Time deltaTime, sf::RenderWindow* window);
	void oSetPosition(float x, float y);

private:

};