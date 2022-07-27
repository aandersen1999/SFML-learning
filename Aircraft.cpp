#include "Aircraft.h"
#include "ResourceHolder.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
	case Aircraft::Eagle:
		return Textures::Ship;
	default:
		return Textures::Ship;
	}
}

Aircraft::Aircraft(Type type, TextureHolder& textures) : mType(type)
{
	//mSprite.setTexture(textures.get(toTextureID(type)));
}


void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}