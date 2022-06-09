#include "Entity.h"

Entity::Entity()
{

}

void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float x, float y)
{
	mVelocity.x = x;
	mVelocity.y = y;
}

sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}

void Entity::drawCurrent(RenderTarget& target, RenderStates states) const
{

}