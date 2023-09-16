#include "CollisionWall.h"

#include "Game.h"
#include "MeshComponent.h"

CollisionWall::CollisionWall() : Actor()
{
	MeshComponent* mc = new MeshComponent(this);
	collision = new BoxCollisionComponent(this);

	getGame().addCollWall(this);
}

CollisionWall::~CollisionWall()
{
	getGame().removeCollWall(this);
}