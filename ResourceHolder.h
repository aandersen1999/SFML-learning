#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

using namespace std;
namespace Textures
{
	enum ID
	{
		Background,
		Player,
		Enemies,
		Bullets
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void load(Identifier id, const string& filename);
	template<typename Parameter>
	void load(Identifier id, const string& filename, const Parameter& secondParameter);
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;
private:
	map<Identifier, unique_ptr<Resource>> mResourceMap;
};

