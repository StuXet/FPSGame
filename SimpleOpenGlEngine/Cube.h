#pragma once
#include "Actor.h"
#include "BoxCollisionComponent.h"

class Cube : public Actor
{
public:
	Cube();
	~Cube();

	void updateActor(float dt) override;

	BoxCollisionComponent& getCollision() { return *collision; }

private:
	BoxCollisionComponent* collision;
	Vector3 targetPosition;
	float moveSpeed = 100.0f;
	void generateRandomTarget();
};