#include "Score.h"

Score::Score()
{
	_leftScore = 0;
	_rightScore = 0;
}


Score::~Score()
{
	SDL_DestroyTexture(_ptr);
}

void Score::updateScore(TTF_Font* font, SDL_Renderer* renderer) {
	string str = std::to_string(_leftScore) + "   :   " + std::to_string(_rightScore);

	SDL_Surface* surface = TTF_RenderText_Solid(font, str.c_str(), SDL_Color{ 255, 255, 255, 0 });
	
	if (_ptr != nullptr)
		SDL_DestroyTexture(_ptr);

	_ptr = SDL_CreateTextureFromSurface(renderer, surface);
	_rect = SDL_Rect{Playfield::WIDTH / 2 - surface->w / 2, 0, surface->w, surface->h};

	SDL_FreeSurface(surface);
}

SDL_Texture* Score::getPointer() {
	return _ptr;
}
SDL_Rect Score::getRect() {
	return _rect;
}