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
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	
public:
	void load(Identifier id, const string& filename);
	
	Resource& get(Identifier id);
	Resource& get(Identifier id) const;
	template<typename Parameter>
	void load(Identifier id, const string& filename, const Parameter& secondParameter);
private:
	map<Identifier, unique_ptr<Resource>> mResourceMap;
};

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
