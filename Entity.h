#pragma once
#include <SFML/Graphics.hpp>
#include "SceneNode.h"

class Entity : public SceneNode
{
public:
	Entity();
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float x, float y);
	sf::Vector2f getVelocity() const;

	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;

private:
	sf::Vector2f mVelocity;
};

