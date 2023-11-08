#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "canon.hpp"
#include "ball.hpp"
#include "tiles.hpp"

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Le Kas Brik");

    const int fps = 165;
    const sf::Time timePerFrame = sf::seconds(1.0f / fps);
    sf::Clock clock;


    // Faire un vecteur de GameObject* pour update en boucle les elements des 3 vect et draw en boucle aussi
    Canon canon;
    std::vector<Ball*> listBall;
    std::vector<Tiles*> listTiles;
    listTiles.push_back(new Tiles(1, 1, 3));

    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
            switch (oEvent.type) 
            {
            case 9:
                listBall.push_back(new Ball(&oWindow));
                break;
            default:
                break;
            }
        }

        //UPDATE
        sf::Time deltaTime = clock.restart();

        canon.update(deltaTime, &oWindow);

        for (auto it = listTiles.begin(); it != listTiles.end();) {
            if ((*it)->update(deltaTime, &oWindow) == 1) {
                delete* it;
                it = listTiles.erase(it);
            }
            else {
                ++it;
            }
        }

        for (auto it = listBall.begin(); it != listBall.end();) {

            std::cout << (*it)->isColliding(listTiles[0]) << std::endl;

            if ((*it)->update(deltaTime, &oWindow) == 1) {
                delete* it;
                it = listBall.erase(it);
            }
            else {
                ++it;
            }
        }

        //DRAW
        oWindow.clear();

        for (int i = 0; i < listTiles.size(); i++) {
            oWindow.draw(*listTiles[i]->getShape());
        }

        for (int i = 0; i < listBall.size(); i++) {
            oWindow.draw(*listBall[i]->getShape());
        }
        oWindow.draw(*canon.getShape());

        oWindow.display();

        //FRAME LIMITE
        sf::Time timeElapsed = clock.getElapsedTime();
        if (timeElapsed < timePerFrame) {
            sf::sleep(timePerFrame - timeElapsed);
        }
    }

    return 0;
}