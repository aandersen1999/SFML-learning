#include "ResourceHolder.h"
#include <assert.h>

template <typename Resource, typename Identifier>
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

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const string& filename, const Parameter& secondParam)
{
	unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename, secondParam))
	{
		throw runtime_error("ResourceHolder::load - Failed to load " + filename);
	}
	auto inserted = mResourceMap.insert(make_pair(id, move(resource)));
	assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}