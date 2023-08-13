#include <SDL.h>

int main(int argc, char** argv)
{
	//Screen dimention
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;

	//Window pointer
	SDL_Window* window = nullptr;

	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	//Create Window
	window = SDL_CreateWindow("First Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOWEVENT_SHOWN);

	//Wait 2 seconds
	SDL_Delay(2000);

	//Destroy Window
	SDL_DestroyWindow(window);

	//Qiut SDL
	SDL_Quit();

	return 0;
}