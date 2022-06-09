#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;
class SceneNode : public Transformable, public Drawable,
	private NonCopyable
{
public:
	typedef unique_ptr<SceneNode> Ptr;
public:
	SceneNode();
	void attachChild(Ptr Child);
	Ptr detatchChild(const SceneNode& node);
private:
	vector<Ptr> mChildren;
	SceneNode* mParent;
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;
};

