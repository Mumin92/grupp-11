#pragma once
#include "SDLSystem.h"

class Entity
{
public:
	float _x;
	float _y;
	float _vx;
	float _vy;
	int _width;
	int _height;
	SDL_Color _color;

	virtual void update();
	void populateRect(SDL_Rect& r);

	Entity(float x, float y, int width, int height);
	~Entity();
};

