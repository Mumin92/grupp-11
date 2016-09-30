#pragma once
#include "SDL_System.h"
#include "Font.h"
#include "Playfield.h"

class Text
{
private:
	SDL_Texture* _ptr = nullptr;
	SDL_Rect _rect;
public:
	Text();
	Text(TTF_Font* font, SDL_Renderer* renderer, int left, int right);
	~Text();

	void updateScore(TTF_Font* font, SDL_Renderer* renderer, int left, int right);
	SDL_Texture* getPointer();
	SDL_Rect getRect();
};

