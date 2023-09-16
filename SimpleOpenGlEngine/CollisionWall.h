#pragma once
#include "Actor.h"
#include "BoxCollisionComponent.h"

class CollisionWall : public Actor
{
public:
	CollisionWall();
	~CollisionWall();

	BoxCollisionComponent& getCollision() { return *collision; }

private:
	BoxCollisionComponent* collision;
};