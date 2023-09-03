#include "BoxCollisionComponent.h"
#include "SphereCollisionComponent.h"
#include "Actor.h"

BoxCollisionComponent::BoxCollisionComponent(Actor* owner) : Component(owner), dimensions(1.0f, 1.0f, 1.0f)
{
}

const Vector3& BoxCollisionComponent::getDimensions() const
{
	return dimensions;
}

void BoxCollisionComponent::setDimensions(const Vector3& dimensionsP)
{
	dimensions = dimensionsP;
}

const Vector3 BoxCollisionComponent::getCenter() const
{
	return owner.getPosition();
}

bool Intersect(const BoxCollisionComponent& a, const BoxCollisionComponent& b)
{
	Vector3 aDimHalf = Vector3(a.getDimensions().x / 2.0f, a.getDimensions().y / 2.0f, a.getDimensions().z / 2.0f);
	Vector3 bDimHalf = Vector3(b.getDimensions().x / 2.0f, b.getDimensions().y / 2.0f, b.getDimensions().z / 2.0f);

	Vector3 aMin = a.getCenter() - aDimHalf;
	Vector3 aMax = a.getCenter() + aDimHalf;
	Vector3 bMin = b.getCenter() - bDimHalf;
	Vector3 bMax = b.getCenter() + bDimHalf;

	return (aMin.x <= bMax.x && aMax.x >= bMin.x) &&
		(aMin.y <= bMax.y && aMax.y >= bMin.y) &&
		(aMin.z <= bMax.z && aMax.z >= bMin.z);
}