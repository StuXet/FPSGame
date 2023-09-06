#include "Cube.h"
#include "MeshComponent.h"
#include "Assets.h"
#include "Game.h"

Cube::Cube() : Actor(), collision(nullptr)
{
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Cube"));

	collision = new BoxCollisionComponent(this);
	collision->setDimensions(Vector3(100,100,100));

	getGame().addCube(this);
}

Cube::~Cube()
{
	getGame().removeCube(this);
}
