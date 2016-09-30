#include "Renderer.h"



Renderer::Renderer()
{
	_ptr = SDL_CreateRenderer(_window.getPointer(), -1, SDL_RENDERER_ACCELERATED);
	if (_ptr == nullptr)
		throw std::runtime_error(SDL_GetError());
}


Renderer::~Renderer()
{
	SDL_DestroyRenderer(_ptr);
}

void Renderer::setColor(const SDL_Color& c) {
	SDL_SetRenderDrawColor(_ptr, c.r, c.g, c.b, c.a);
}
void Renderer::clear() {
	SDL_RenderClear(_ptr);
}
void Renderer::present() {
	SDL_RenderPresent(_ptr);
}
void Renderer::fillRect(const SDL_Rect& rect) {
	SDL_RenderFillRect(_ptr, &rect);
}
void Renderer::drawTexture(SDL_Texture* texture, const SDL_Rect& rect) {
	SDL_RenderCopy(_ptr, texture, NULL, &rect);
}

SDL_Renderer* Renderer::getPointer() {
	return _ptr;
}