#include "Game.h"

int main(int argc, char** argv)
{
	bool isGameInit = Game::instace().initialize();
	if (isGameInit)
	{
		Game::instace().loop();
	}
	Game::instace().close();
	return 0;
}