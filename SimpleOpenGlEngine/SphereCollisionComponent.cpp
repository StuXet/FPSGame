#include "SphereCollisionComponent.h"
#include "Actor.h"

SphereCollisionComponent::SphereCollisionComponent(Actor* owner) : Component(owner), radius(1.0f)
{
}

float SphereCollisionComponent::getRadius() const
{
	return owner.getScale() * radius;
}

void SphereCollisionComponent::setRadius(float radiusP)
{
	radius = radiusP;
}

const Vector3 SphereCollisionComponent::getCenter() const
{
	return owner.getPosition();
}

bool Intersect(const SphereCollisionComponent& a, const SphereCollisionComponent& b)
{
	Vector3 aCenter = a.getCenter();
	Vector3 bCenter = b.getCenter();
	Vector3 ab = bCenter - aCenter;
	float distSq = ab.lengthSq();
	float sumOfRadius = a.getRadius() + b.getRadius();
	return distSq <= sumOfRadius * sumOfRadius;
}