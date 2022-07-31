#include <SFML/Graphics.hpp>
#include "Game.h"
#include "ResourceHolder.h"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nException: " << e.what() << std::endl;
	}
	
	return 0;
}