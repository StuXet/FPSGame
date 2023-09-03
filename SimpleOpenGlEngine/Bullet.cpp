#include "Bullet.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Cube.h"

Bullet::Bullet() : Sphere(), deathTimer(1.0f) // Initialize Sphere's constructor
{
    moveComponent = new MoveComponent(this);
    moveComponent->setForwardSpeed(800.0f); // Bullet speed
    collision = new SphereCollisionComponent(this);
    collision->setRadius(1);
}

void Bullet::updateActor(float dt)
{
    deathTimer -= dt;
    if (deathTimer <= 0.0f)
    {
        setState(Actor::ActorState::Dead);
    }
    else
    {
        auto cubes = getGame().getCubes();
        for (auto cube : cubes)
        {
	        if (Intersect(*collision, cube->getCollision()))
	        {
                setState(ActorState::Dead);
                cube->setState(ActorState::Dead);
                break;
	        }
        }
    }
}