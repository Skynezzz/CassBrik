#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float pPos1, float pPos2, int pSize1, int pSize2);
	GameObject(float pPos1, float pPos2, int pSize1);
	inline sf::Shape* getShape() { return shape; };
	void move();

protected:
	float pos[2];
	float vect[2] = { 0 };
	int size[2] = { 0 };
	sf::Shape* shape;

};