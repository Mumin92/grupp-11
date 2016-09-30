#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <stdexcept>
class SDL_System
{
public:
	SDL_System(Uint32 flags);
	~SDL_System();
};

