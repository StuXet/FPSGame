#pragma once
#include "Actor.h"
#include "BoxCollisionComponent.h"

class Plane : public Actor
{
public:
	Plane();
	~Plane();

	BoxCollisionComponent& getCollision() { return *collision; }

private:
	BoxCollisionComponent* collision;
};
