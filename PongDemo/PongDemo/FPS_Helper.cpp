#include "FPS_Helper.h"



FPS_Helper::FPS_Helper()
{
	_lastTick = 0;
}


FPS_Helper::~FPS_Helper()
{
}

void FPS_Helper::Delay(int fps) {
	int target = 1000 / fps;

	Uint32 currentTick = SDL_GetTicks();
	int wait = target - (currentTick - _lastTick);

	if (wait > 0)
		SDL_Delay(wait);

	_lastTick = currentTick;
}