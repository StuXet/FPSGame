#pragma once
#include <vector>
#include "Window.h"
#include "Renderer.h"
#include "Vector2.h"
#include "Actor.h"
#include "SpriteComponent.h"

using std::vector;

class Game
{
public:
	static Game& instace()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator = (const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator = (Game&&) = delete;

	bool initialize();
	void load();
	void loop();
	void unload();
	void close();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);

	Renderer& getRenderer() { return renderer; }

private:
	Game() : isRunning(true), isUpdatingActors(false) {}

	void processInput();
	void update(float dt);
	void render();

	bool isRunning;
	Window window;
	Renderer renderer;

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;
};