#pragma once

#include "gameObject.hpp"
#include <vector>

class Ball : public GameObject
{
public:
	Ball(sf::RenderWindow* window);
	bool update(sf::Time deltaTime, sf::RenderWindow* window) override;
	void onCollision(GameObject* incomingObject) override;
	void checkBounce(GameObject* incomingObject) override;
	void borderProtection(sf::RenderWindow* window);
	//void move(sf::Time deltaTime, sf::RenderWindow* window);

private:
	bool isUnderScreen(sf::RenderWindow* window);
	void oSetPosition(float x, float y);
	void bounce(sf::Vector2f direction);
	sf::Vector2f getWindowBorderBounceDirection(sf::RenderWindow* window);
	bool isOutScreen(sf::RenderWindow* window);
	bool isColliding(GameObject* object);
	bool isCollidingOneD(sf::Vector2f object1, sf::Vector2f object2);
	sf::Vector2f getBounceDirection(GameObject* incomingObject);
	std::vector<GameObject*> colliding;

};