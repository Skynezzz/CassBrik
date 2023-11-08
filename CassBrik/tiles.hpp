#pragma once

#include "gameObject.hpp"

class Tiles : public GameObject
{
public:
	Tiles(float posX, float posY, int pLife);
	int update(sf::Time deltaTime, sf::RenderWindow* window) override;
	inline void getDamage() { life--; }

private:
	int life;

};