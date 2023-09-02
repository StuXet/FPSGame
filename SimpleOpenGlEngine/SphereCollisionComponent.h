#pragma once
#include "Component.h"
#include "Vector3.h"

class SphereCollisionComponent : public Component
{
public:
	SphereCollisionComponent(Actor* owner);
	SphereCollisionComponent() = delete;
	SphereCollisionComponent(const SphereCollisionComponent&) = delete;
	SphereCollisionComponent& operator=(const SphereCollisionComponent&) = delete;

	float getRadius() const;
	void setRadius(float radiusP);

	const Vector3 getCenter() const;

private:
	float radius;
};

bool Intersect(const SphereCollisionComponent& a, const SphereCollisionComponent& b);