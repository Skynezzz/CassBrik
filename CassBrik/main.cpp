#include <SFML/Graphics.hpp>
#include <iostream>

#include "canon.hpp"
#include "ball.hpp"

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Le Kas Brik");

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

        //DRAW
        oWindow.clear();

        oWindow.draw(*canon.getShape());
        oWindow.draw(*ball.getShape());

        oWindow.display();
    }

    return 0;
}