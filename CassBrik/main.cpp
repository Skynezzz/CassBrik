#include <SFML/Graphics.hpp>
#include <iostream>

#include "canon.hpp"
#include "ball.hpp"

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Le Kas Brik");

    const int fps = 60;
    const sf::Time timePerFrame = sf::seconds(1.0f / fps);
    sf::Clock clock;

    Canon canon;
    Ball ball;

    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE
        sf::Time deltaTime = clock.restart();
        ball.update(deltaTime);
        canon.update(deltaTime);

        //DRAW
        oWindow.clear();

        oWindow.draw(*canon.getShape());
        oWindow.draw(*ball.getShape());

        oWindow.display();

        //FRAME LIMITE
        sf::Time timeElapsed = clock.getElapsedTime();
        if (timeElapsed < timePerFrame) {
            sf::sleep(timePerFrame - timeElapsed);
        }
    }

    return 0;
}