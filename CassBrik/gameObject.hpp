#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(int pSize, float pPos1, float pPos2);
	GameObject(int pSize1, int pSize2, float pPos1, float pPos2);
	inline sf::Shape* getShape() { return shape; };
	void move();

private:
	float pos[2];
	float vect[2] = { 0 };
	int size[2] = { 0 };
	sf::Shape* shape;

};