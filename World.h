#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "ResourceHolder.cpp"
#include "SceneNode.h"
#include "Aircraft.h"
#include <array>


class World : private sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();

private:
	void loadTextures();
	void buildScene();

private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;
};

