#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float pPos1, float pPos2, int pSize1, int pSize2);
	GameObject(float pPos1, float pPos2, int pSize1);
	inline sf::Shape* getShape() { return shape; };
	inline sf::Shape* getHitbox() { return hitbox; };
	virtual int update(sf::Time deltaTime, sf::RenderWindow* window) { return 0; };
	
	sf::Vector2f getMinMaxX();
	sf::Vector2f getMinMaxY();
	void checkBounce(GameObject* incomingObject);
	bool isColliding(GameObject* object);

protected:
	sf::Vector2f position;
	sf::Vector2f vect;
	sf::Vector2f size;
	float velocity = 0;
	sf::Shape* initialShape = NULL;
	sf::Shape* shape = NULL;
	sf::Shape* hitbox = NULL;

	float getVectorLenth(sf::Vector2f vector);
	bool isCollidingOneD(sf::Vector2f object1, sf::Vector2f object2);
	sf::Vector2f getBounceDirection(GameObject* incomingObject);
	void bounce(sf::Vector2f direction);

};