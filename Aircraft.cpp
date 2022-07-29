#include "Aircraft.h"
#include "ResourceHolder.h"
#include <SFML/Graphics.hpp>
#include "ResourceHolder.cpp"

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

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

Aircraft::Aircraft(Type type, const TextureHolder& textures) : mType(type), mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bound = mSprite.getLocalBounds();
	mSprite.setOrigin(bound.width / 2.0f, bound.height / 2.0f);
}


void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}