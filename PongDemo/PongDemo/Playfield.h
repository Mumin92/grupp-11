#pragma once
#include "Paddle.h"

class Playfield
{
public:
	Playfield();
	~Playfield();

	enum Side { left, right };

	const int WIDTH = 640;
	const int HEIGHT = 360;
	const int MARGIN = 8;
};

