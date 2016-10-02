#include "Renderer.h"
#include "SDLSystem.h"
#include <stdexcept>
#include "Config.h"

Renderer::Renderer() : _window{Config::TITLE, Config::WIN_WIDTH, Config::WIN_HEIGHT}
{
	_ptr = SDL_CreateRenderer(_window.getPointer(), -1, SDL_RENDERER_ACCELERATED);
	if (!_ptr) {
		throw std::runtime_error(SDL_GetError());
	}
}


Renderer::~Renderer()
{
	if (_ptr) {
		SDL_DestroyRenderer(_ptr);
	}
}

void Renderer::clear()
{
	SDL_RenderClear(_ptr);
}

void Renderer::setColor(const SDL_Color& c)
{
	SDL_SetRenderDrawColor(_ptr, c.r, c.g, c.b, c.a);
}

void Renderer::drawRect(const SDL_Rect& c)
{
	SDL_RenderFillRect(_ptr, &c);
}

void Renderer::present()
{
	SDL_RenderPresent(_ptr);
}
