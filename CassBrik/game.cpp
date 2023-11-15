#include "game.hpp"

Game::Game()
{
    oWindow = new sf::RenderWindow(sf::VideoMode(640, 480), "Le Kas Brik");

    listTiles.push_back(new Tiles(1, 3, 5));
    listTiles.push_back(new Tiles(2, 3, 5));
    listTiles.push_back(new Tiles(3, 3, 5));
    listTiles.push_back(new Tiles(4, 3, 5));
    listTiles.push_back(new Tiles(5, 3, 5));
    listTiles.push_back(new Tiles(6, 3, 5));
    listTiles.push_back(new Tiles(7, 3, 5));
    listTiles.push_back(new Tiles(8, 3, 100));
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

    
    for (auto itBall = listBall.begin(); itBall != listBall.end();)
    {
    //--- BALLS Collision ---//
        for (auto itBallColision = listBall.begin(); itBallColision != listBall.end(); ++itBallColision)
        {
            if (itBall == itBallColision)
                continue;

            (*itBall)->checkBounce(*itBallColision);
        }

        for (auto itTile = listTiles.begin(); itTile != listTiles.end();)
        {
            (*itBall)->checkBounce(*itTile);

    //--- TILES ---//
            if ((*itTile)->update(deltaTime, oWindow) == 1)
            {
                delete* itTile;
                itTile = listTiles.erase(itTile);
            }
            else
            {
                ++itTile;
            }
        }


    //--- BALLS ---//
        if ((*itBall)->update(deltaTime, oWindow) == 1)
        {
            delete* itBall;
            itBall = listBall.erase(itBall);
        }
        else
        {
            ++itBall;
        }
    }

    //if (listTiles.empty())
    //    oWindow->close();
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