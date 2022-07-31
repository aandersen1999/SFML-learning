#pragma once

#include <SFML/Graphics.hpp>
#include "World.h"

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	sf::RenderWindow mWindow;
	World mWorld;
};

