#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:

	GameObject(float pPos1, float pPos2, int pSize1, int pSize2);
	GameObject(float pPos1, float pPos2, int pSize1);

	virtual bool update(sf::Time deltaTime, sf::RenderWindow* window) { return 0; };
	inline sf::Shape* getShape() { return shape; };
	inline sf::Shape* getHitbox() { return hitbox; };

	void move(sf::Time deltaTime);
	sf::Vector2f getMinMaxX();
	sf::Vector2f getMinMaxY();

	void checkBounce(GameObject* incomingObject, sf::RenderWindow* window);


protected:

	sf::Vector2f position;
	sf::Vector2f vect;
	sf::Vector2f size;

	float velocity = 0;

	sf::Shape* shape;
	sf::Shape* hitbox;

	float getVectorLenth(sf::Vector2f vector);
	sf::Vector2f getWindowBorderBounceDirection(sf::RenderWindow* window);
	bool isOutScreen(sf::RenderWindow* window);
	bool isColliding(GameObject* object);
	bool isCollidingOneD(sf::Vector2f object1, sf::Vector2f object2);
	sf::Vector2f getBounceDirection(GameObject* incomingObject);
	void bounce(sf::Vector2f direction);

};