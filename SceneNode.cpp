#include "SceneNode.h"
#include <assert.h>

using namespace sf;
SceneNode::SceneNode()
{

}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detatchChild(const SceneNode& node)
{
	auto found = find_if(mChildren.begin(), mChildren.end(), 
		[&](Ptr& p) -> bool 
		{ 
			return p.get() == &node; 
		});
	assert(found != mChildren.end());
	
	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();
	drawCurrent(target, states);

	for (const Ptr& child : mChildren)
	{
		child->draw(target, states);
	}
}

void SceneNode::drawCurrent(RenderTarget& target, RenderStates states) const
{

}