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

	generateRandomTarget();
}

void Cube::updateActor(float dt)
{
    Actor::updateActor(dt);

    Vector3 direction = targetPosition - getPosition();
    if (direction.lengthSq() > 5.0f) // 5.0f is a small threshold to determine if we're "close enough"
    {
        direction.normalize();
        setPosition(getPosition() + direction * moveSpeed * dt);
    }
    else
    {
        generateRandomTarget();
    }
}

void Cube::generateRandomTarget()
{
    const float maxX = 1000.0f;
    const float minX = -1000.0f;
    const float maxY = 1000.0f;
    const float minY = -1000.0f;

    float randomX = minX + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxX - minX)));
    float randomY = minY + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));

    targetPosition = Vector3(randomX, randomY, getPosition().z);
}

Cube::~Cube()
{
	getGame().removeCube(this);
}
