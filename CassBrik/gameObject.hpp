#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float pPos1, float pPos2, int pSize1, int pSize2);
	GameObject(float pPos1, float pPos2, int pSize1);
	inline sf::Shape* getShape() { return shape; };
	virtual int update(sf::Time deltaTime, sf::RenderWindow* window) { return 0; };
	bool isColliding(GameObject* object);

protected:
	sf::Vector2f position;
	sf::Vector2f vect;
	sf::Vector2f size;
	float velocity = 0;
	sf::Shape* initialShape = NULL;
	sf::Shape* shape = NULL;

	float getVectorLenth(sf::Vector2f vector);
	bool isCollidingOneD(sf::Vector2f object1, sf::Vector2f object2);

};