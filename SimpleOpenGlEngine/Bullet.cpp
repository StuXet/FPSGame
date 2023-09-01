#include "Bullet.h"
#include "MoveComponent.h"
#include "Game.h"

Bullet::Bullet() : Sphere(), deathTimer(1.0f) // Initialize Sphere's constructor
{
    moveComponent = new MoveComponent(this);
    moveComponent->setForwardSpeed(800.0f); // Bullet speed
}

void Bullet::updateActor(float dt)
{
    deathTimer -= dt;
    if (deathTimer <= 0.0f)
    {
        setState(Actor::ActorState::Dead);
    }
}