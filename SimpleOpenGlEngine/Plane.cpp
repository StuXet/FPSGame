#include "Plane.h"
#include "MeshComponent.h"
#include "Assets.h"
#include "Game.h"

Plane::Plane() : Actor()
{
	setScale(10.0f);
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Plane"));

	collision = new BoxCollisionComponent(this);
	collision->setDimensions(Vector3(20, 20, 20));

	getGame().addPlane(this);
}

Plane::~Plane()
{
	getGame().removePlane(this);
}