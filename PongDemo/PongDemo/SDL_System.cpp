#include "SDL_System.h"


SDL_System::SDL_System(Uint32 flags = SDL_INIT_VIDEO)
{
	if (SDL_Init(flags) != 0)
		throw std::runtime_error(SDL_GetError());
}


SDL_System::~SDL_System()
{
	SDL_Quit();
}
