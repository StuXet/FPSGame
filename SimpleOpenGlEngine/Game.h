#pragma once
#include <vector>
#include "Actor.h"
#include "SpriteComponent.h"
#include "Window.h"
#include "Vector3.h"
#include "RendererOGL.h"
#include "AudioSystem.h"
#include "InputSystem.h"
#include "Cube.h"
#include "Plane.h"
#include "CollisionWall.h"

using std::vector;

class Game
{
public:
	static Game& instance()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

private:
	Game() : isRunning(true), isUpdatingActors(false), fps(nullptr), crosshair(nullptr), follow(nullptr) {}

public:
	bool initialize();
	void load();
	void loop();
	void unload();
	void close();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);
	RendererOGL& getRenderer() { return renderer; }
	AudioSystem& getAudioSystem() { return audioSystem; }

	vector<Cube*>& getCubes();
	void addCube(Cube* cube);
	void removeCube(Cube* cube);

	vector<Plane*>& getPlanes();
	void addPlane(Plane* plane);
	void removePlane(Plane* plane);

	vector<CollisionWall*>& getCollWall();
	void addCollWall(CollisionWall* collisionWall);
	void removeCollWall(CollisionWall* collisionWall);

private:
	void processInput();
	void update(float dt);
	void render();

	bool isRunning;
	Window window;
	RendererOGL renderer;
	AudioSystem audioSystem;
	InputSystem inputSystem;

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;

	SoundEvent musicEvent;
	class FPSActor* fps;
	class SpriteComponent* crosshair;
	class FollowActor* follow;

	vector<Cube*> cubes;
	vector<Plane*> planes;
	vector<CollisionWall*> collWalls;

};