#pragma once
#include "Entity.h"

class Paddle : public Entity
{
public:
	Paddle(float x, float y);
	void update();
	~Paddle();
};

