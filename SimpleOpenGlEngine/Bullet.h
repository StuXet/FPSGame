#pragma once
#include "Actor.h"
#include "Sphere.h"
#include "SphereCollisionComponent.h"

class Bullet : public Sphere // Bullet now inherits from Sphere
{
public:
    Bullet();
    void updateActor(float dt) override;

private:
    SphereCollisionComponent* collision;
    class MoveComponent* moveComponent;
    float deathTimer;
};