#include "FPSActor.h"
#include "MoveComponent.h"
#include "AudioComponent.h"
#include "Game.h"
#include "FPSCameraComponent.h"
#include "MeshComponent.h"
#include "Assets.h"
#include "Bullet.h"
#include "FPSCameraComponent.h"
#include "MeshComponent.h"

FPSActor::FPSActor() :
	Actor(),
	moveComponent(nullptr),
	audioComponent(nullptr),
	meshComponent(nullptr),
	cameraComponent(nullptr),
	lastFootstep(0.0f)
{
	moveComponent = new MoveComponent(this);
	audioComponent = new AudioComponent(this);
	cameraComponent = new FPSCameraComponent(this);

	footstep = audioComponent->playEvent("event:/Footstep");
	footstep.setPaused(true);

	FPSModel = new Actor();
	FPSModel->setScale(0.75f);
	meshComponent = new MeshComponent(FPSModel);
	meshComponent->setMesh(Assets::getMesh("Mesh_Rifle"));

	playerCollision = new BoxCollisionComponent(this);
	playerCollision->setDimensions(Vector3(10.0f, 10.0f, 10.0f));
}

void FPSActor::updateActor(float dt)
{
	Actor::updateActor(dt);

	// Play the footstep if we're moving and haven't recently
	lastFootstep -= dt;
	if ((!Maths::nearZero(moveComponent->getForwardSpeed()) || !Maths::nearZero(moveComponent->getStrafeSpeed())) && lastFootstep <= 0.0f)
	{
		footstep.setPaused(false);
		footstep.restart();
		lastFootstep = 0.5f;
	}

	// Update position and rotation of model relatively to position
	Vector3 modelPosition = getPosition();
	modelPosition += getForward() * MODEL_OFFSET.x;
	modelPosition += getRight() * MODEL_OFFSET.y;
	modelPosition.z += MODEL_OFFSET.z;
	FPSModel->setPosition(modelPosition);
	Quaternion q = getRotation();
	q = Quaternion::concatenate(q, Quaternion(getRight(), cameraComponent->getPitch()));
	FPSModel->setRotation(q);

	bulletCooldown -= dt;

	for (Cube* cube : getGame().getCubes())
	{
		if (Intersect(*playerCollision, (cube->getCollision())))
		{
			// Calculate the direction from the cube to the player
			Vector3 direction = getPosition() - cube->getPosition();
			direction.normalize();

			// Push the player out based on the cube's scale
			setPosition(getPosition() + direction * (cube->getScale() * 0.5f));
			
		}
	}

	for (Plane* plane : getGame().getPlanes())
	{
		if (Intersect(*playerCollision, plane->getCollision()))
		{
			Vector3 direction = getPosition() - plane->getPosition();

			setPosition(getPosition() + direction * (plane->getScale() * .5f));
		}
	}
}

void FPSActor::actorInput(const InputState& inputState)
{
	float forwardSpeed = 0.0f;
	float strafeSpeed = 0.0f;
	// wasd movement
	if (inputState.keyboard.getKeyValue(SDL_SCANCODE_W))
	{
		forwardSpeed += 400.0f;
	}
	if (inputState.keyboard.getKeyValue(SDL_SCANCODE_S))
	{
		forwardSpeed -= 400.0f;
	}
	if (inputState.keyboard.getKeyValue(SDL_SCANCODE_A))
	{
		strafeSpeed -= 400.0f;
	}
	if (inputState.keyboard.getKeyValue(SDL_SCANCODE_D))
	{
		strafeSpeed += 400.0f;
	}
	moveComponent->setForwardSpeed(forwardSpeed);
	moveComponent->setStrafeSpeed(strafeSpeed);
	// Mouse mouvement
	Vector2 mousePosition = inputState.mouse.getPosition();
	float x = mousePosition.x;
	float y = mousePosition.y;
	const int maxMouseSpeed = 500;
	const float maxAngularSpeed = Maths::pi * 8;
	float angularSpeed = 0.0f;
	if (x != 0)
	{
		angularSpeed = x / maxMouseSpeed;
		angularSpeed *= maxAngularSpeed;
	}
	moveComponent->setAngularSpeed(angularSpeed);
	const float maxPitchSpeed = Maths::pi * 8;
	float pitchSpeed = 0.0f;
	if (y != 0)
	{
		pitchSpeed = y / maxMouseSpeed;
		pitchSpeed *= maxPitchSpeed;
	}
	cameraComponent->setPitchSpeed(pitchSpeed);

	//Bullet
	if (inputState.mouse.getButtonState(SDL_BUTTON_LEFT) == ButtonState::Pressed)
	{
		Bullet* bullet = new Bullet();

		// Set bullet position slightly ahead of the player to avoid collisions
		bullet->setPosition(getPosition() + getForward() * 50.0f);

		// Combine player's yaw and camera's pitch for bullet's rotation
		Quaternion playerRot = getRotation();
		Quaternion cameraRot(getRight(), cameraComponent->getPitch());
		Quaternion combinedRot = Quaternion::concatenate(playerRot, cameraRot);

		bullet->setRotation(combinedRot);

		bulletCooldown = 0.2f;
	}
}

void FPSActor::setFootstepSurface(float value)
{
	// Pause here because the way I setup the parameter in FMOD
	// changing it will play a footstep
	footstep.setPaused(true);
	footstep.setParameter("Surface", value);
}

void FPSActor::setVisible(bool isVisible)
{
	meshComponent->setVisible(isVisible);
}