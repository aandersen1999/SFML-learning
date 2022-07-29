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
	Ptr detachChild(const SceneNode& node);
	void update(sf::Time dt);
	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;
private:
	vector<Ptr> mChildren;
	SceneNode* mParent;
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;
};
