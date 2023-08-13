#include "Game.h"

int main(int argc, char** argv)
{
	bool isGameInit = Game::instace().initialize();
	if (isGameInit)
	{
		Game::instace().load();
		Game::instace().loop();
		Game::instace().unload();
	}
	Game::instace().close();
	return 0;
}