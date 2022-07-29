#include "ResourceHolder.h"
#include <assert.h>

template <typename Resource, class Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const string& filename)
{
	unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
	{
		throw runtime_error("ResourceHolder::load - Failed to load " + filename);
	}
	auto inserted = mResourceMap.insert(make_pair(id, move(resource)));
	assert(inserted.second);
}

template <typename Resource, class Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const string& filename, const Parameter& secondParameter)
{
	unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename, secondParameter))
	{
		throw runtime_error("ResourceHolder::load - Failed to load " + filename);
	}
	auto inserted = mResourceMap.insert(make_pair(id, move(resource)));
	assert(inserted.second);
}

template <typename Resource, class Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

template <typename Resource, class Identifier>
const inline Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}