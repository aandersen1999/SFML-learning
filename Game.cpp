#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game() : mWindow(sf::VideoMode(640, 480), "Test") , mPlayer()
{
	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.0f, 100.0f);
	mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update()
{

}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	
}