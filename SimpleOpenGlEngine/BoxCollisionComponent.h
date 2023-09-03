#pragma once
#include "Component.h"
#include "Vector3.h"
class SphereCollisionComponent;

class BoxCollisionComponent : public Component
{
public:
	BoxCollisionComponent(Actor* owner);
	BoxCollisionComponent() = delete;
	BoxCollisionComponent(const BoxCollisionComponent&) = delete;
	BoxCollisionComponent& operator=(const BoxCollisionComponent&) = delete;

	const Vector3& getDimensions() const;
	void setDimensions(const Vector3& dimensions);

	const Vector3 getCenter() const;

private:
	Vector3 dimensions; // Represents the width, height, and depth of the box
};

bool Intersect(const BoxCollisionComponent& a, const BoxCollisionComponent& b);