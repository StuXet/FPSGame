#pragma once
#include "Actor.h"
#include "Sphere.h"
#include "BoxCollisionComponent.h"

class Bullet : public Sphere // Bullet now inherits from Sphere
{
public:
    Bullet();
    void updateActor(float dt) override;

private:
    BoxCollisionComponent* collision;
    class MoveComponent* moveComponent;
    float deathTimer;
};