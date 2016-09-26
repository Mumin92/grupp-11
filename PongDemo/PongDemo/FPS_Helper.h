#pragma once
#include "SDL.h"
class FPS_Helper
{
	Uint32 _lastTick;
public:
	FPS_Helper();
	~FPS_Helper();

	void Delay(const int delay);
};

