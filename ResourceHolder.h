#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

using namespace std;
namespace Textures
{
	enum ID
	{
		Ship,
		Desert
	};
}

template <typename Resource, class Identifier>
class ResourceHolder
{
	
public:
	template<typename Parameter>
	void load(Identifier id, const string& filename, const Parameter& secondParameter);
public:
	void load(Identifier id, const string& filename);
	
	Resource& get(Identifier id);
	const inline Resource& get(Identifier id) const;
	
	
private:
	map<Identifier, unique_ptr<Resource>> mResourceMap;
};

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
