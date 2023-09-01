#pragma once
#include "Actor.h"
#include "Sphere.h"

class Bullet : public Sphere // Bullet now inherits from Sphere
{
public:
    Bullet();
    void updateActor(float dt) override;

private:
    class MoveComponent* moveComponent;
    float deathTimer;
};