#pragma once
#include "Actor.h"
#include "BoxCollisionComponent.h"

class Cube : public Actor
{
public:
	Cube();
	~Cube();

	BoxCollisionComponent& getCollision() { return *collision; }

private:
	BoxCollisionComponent* collision;
};