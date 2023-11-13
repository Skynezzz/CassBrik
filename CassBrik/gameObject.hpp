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
	inline int getDamage() { return damage; };

	void move(sf::Time deltaTime);
	sf::Vector2f getMinMaxX();
	sf::Vector2f getMinMaxY();

	virtual void checkBounce(GameObject* incomingObject) { return; };
	virtual void onCollision(GameObject* incomingObject) { return; }


protected:

	sf::Vector2f position;
	sf::Vector2f vect;
	sf::Vector2f size;

	float velocity = 0;

	float damage = 1;

	sf::Shape* shape;
	sf::Shape* hitbox;

	float getVectorLenth(sf::Vector2f vector);

};