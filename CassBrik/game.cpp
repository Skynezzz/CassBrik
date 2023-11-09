#include "game.hpp"

Game::Game()
{
    oWindow = new sf::RenderWindow(sf::VideoMode(640, 480), "Le Kas Brik");

    listTiles.push_back(new Tiles(7, 5, 3));
}

Game::~Game()
{
}

void Game::start()
{
    while (oWindow->isOpen())
    {
        event();

        update();

        display();

        frameLimiter();
    }
}

void Game::event()
{
    while (oWindow->pollEvent(oEvent))
    {
        switch (oEvent.type)
        {
        //--- CLOSE ---//
        case sf::Event::Closed:
            oWindow->close();
            break;

        //--- MOUSE CLICK ---//
        case 9:
            listBall.push_back(new Ball(oWindow));
            break;

        default:
            break;
        }
    }
}

void Game::update()
{
    deltaTime = clock.restart();

    //--- CANON ---//
    canon.update(deltaTime, oWindow);

    //--- TILES ---//
    for (auto it = listTiles.begin(); it != listTiles.end();)
    {
        if ((*it)->update(deltaTime, oWindow) == 1)
        {
            delete* it;
            it = listTiles.erase(it);
        }
        else
        {
            ++it;
        }
    }

    //--- BALLS ---//
    for (auto it = listBall.begin(); it != listBall.end();)
    {
        (*it)->checkBounce(listTiles[0]);

        if ((*it)->update(deltaTime, oWindow) == 1)
        {
            delete* it;
            it = listBall.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::display()
{
    //--- CLEAR ---//
    oWindow->clear();

    //--- DRAW ---//
    // Balls
    for (int i = 0; i < listBall.size(); i++)
    {
        oWindow->draw(*listBall[i]->getShape());
        oWindow->draw(*listBall[i]->getHitbox());
    }
    // Tiles
    for (int i = 0; i < listTiles.size(); i++)
    {
        oWindow->draw(*listTiles[i]->getShape());
    }
    // Canon
    oWindow->draw(*canon.getShape());

    //--- DISPLAY ---//
    oWindow->display();
}

void Game::frameLimiter()
{
    timeElapsed = clock.getElapsedTime();
    if (timeElapsed < timePerFrame)
    {
        sf::sleep(timePerFrame - timeElapsed);
    }
}