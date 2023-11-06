#pragma once

#include "gameObject.hpp"

class Canon : public GameObject
{
public:
	Canon() : GameObject(310.f, 440.f, 20, 40) {};
	void update(sf::Time deltaTime);

private:

};