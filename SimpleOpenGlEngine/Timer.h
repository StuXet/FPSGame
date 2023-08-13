#pragma once

class Timer
{
public:
	Timer();
	Timer(const Timer&) = delete;
	Timer& operator=(const Timer&) = delete;

	//compute delta time as the number of milliseconds since last time
	//clamp it so debug won't think delta time is really high during breakpoints
	unsigned int computeDeltaTime();

	//WAit if the game run faster than the decided FPS
	void delayTime();

private:
	const static unsigned int FPS = 60;
	const static unsigned int FRAME_DELAY = 1000 / FPS;
	const unsigned int MAX_DT = 50;

	//Time in milliseconds when frame starts
	unsigned int frameStart;

	//Last frame start time in milliseconds
	unsigned int lastFrame;

	//Time it tooks to run the loop. Used to cap framerat.
	unsigned int frameTime;
};