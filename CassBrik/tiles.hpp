#pragma once

#include "gameObject.hpp"

class Tiles : public GameObject
{
public:
	Tiles(float posX, float posY, int pLife);
	bool update(sf::Time deltaTime, sf::RenderWindow* window) override;
	inline void getDamage() { life--; }

private:
	int life;

};