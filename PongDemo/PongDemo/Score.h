#pragma once
#include "SDL_System.h"
#include "Font.h"
#include "Playfield.h"

class Score
{
private:
	SDL_Texture* _ptr = nullptr;
	SDL_Rect _rect;

	int _leftScore;
	int _rightScore;
public:
	Score();
	~Score();

	void updateScore(TTF_Font* font, SDL_Renderer* renderer);
	SDL_Texture* getPointer();
	SDL_Rect getRect();

	void leftGoal() {
		_leftScore++;
	}
	void rightGoal() {
		_rightScore++;
	}
};

