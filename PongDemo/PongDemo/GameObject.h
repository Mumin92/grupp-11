#pragma once
#include "SDL.h"
class GameObject
{
protected:
	SDL_Rect rect;
public:
	GameObject();
	~GameObject();

	enum Side { left, right };
	SDL_Rect GetRect() const;

	virtual void Update();
};

