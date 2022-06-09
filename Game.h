#pragma once

#include <SFML/Graphics.hpp>

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
	sf::CircleShape mPlayer;
	
};

