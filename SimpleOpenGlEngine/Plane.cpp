#include "Plane.h"
#include "MeshComponent.h"
#include "Assets.h"
#include "Game.h"

Plane::Plane() : Actor()
{
	setScale(10.0f);
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Plane"));
	Game::instance().addPlane(this);
}