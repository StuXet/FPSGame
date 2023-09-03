#pragma once
#include "Actor.h"
#include "SphereCollisionComponent.h"

class Cube : public Actor
{
public:
	Cube();
	~Cube();

	SphereCollisionComponent& getCollision() { return *collision; }

private:
	SphereCollisionComponent* collision;
};