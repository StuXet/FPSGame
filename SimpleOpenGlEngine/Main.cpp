#include <SDL.h>

int main(int argc, char** argv)
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;

	SDL_Window* window = nullptr;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("First Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOWEVENT_SHOWN);

	SDL_Delay(2000);

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}