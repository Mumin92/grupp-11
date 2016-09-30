#include "Text.h"

Text::Text()
{
	
}
Text::Text(TTF_Font* font, SDL_Renderer* renderer, int left, int right)
{
	updateScore(font, renderer, left, right);
}


Text::~Text()
{
	SDL_DestroyTexture(_ptr);
}

void Text::updateScore(TTF_Font* font, SDL_Renderer* renderer, int left, int right) {
	string str = std::to_string(left) + "   :   " + std::to_string(right);

	SDL_Surface* surface = TTF_RenderText_Solid(font, str.c_str(), SDL_Color{ 255, 255, 255, 0 });
	
	if (_ptr != nullptr)
		SDL_DestroyTexture(_ptr);

	_ptr = SDL_CreateTextureFromSurface(renderer, surface);
	_rect = SDL_Rect{Playfield::WIDTH / 2 - surface->w / 2, 0, surface->w, surface->h};

	SDL_FreeSurface(surface);
}

SDL_Texture* Text::getPointer() {
	return _ptr;
}
SDL_Rect Text::getRect() {
	return _rect;
}