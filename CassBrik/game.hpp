#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

#include "canon.hpp"
#include "ball.hpp"
#include "tiles.hpp"

class Game
{
public:
	Game(int level);
	~Game();

    void start();

private:

    sf::RenderWindow* oWindow;

    const int FPS = 165;
    const sf::Time timePerFrame = sf::seconds(1.0f / FPS);
    sf::Clock clock;
    sf::Event oEvent;
    sf::Time deltaTime;
    sf::Time timeElapsed;

    Canon canon;
    std::vector<Ball*> listBall;
    std::vector<Tiles*> listTiles;

    void event();
    void update();
    void display();
    void frameLimiter();

    void setLevel(int level);

};