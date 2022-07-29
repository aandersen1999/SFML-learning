#pragma once
#include "Entity.h"
#include "ResourceHolder.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle
	};
public:
	Aircraft(Aircraft::Type type, const TextureHolder& textures);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	
	Aircraft::Type mType;
	sf::Sprite mSprite;
};
