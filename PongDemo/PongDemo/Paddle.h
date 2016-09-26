#pragma once
#include "Playfield.h"
#include "SDL.h"
#include "GameObject.h"

class Playfield;

class Paddle : public GameObject
{
	const int SPEED = 3;

	bool pressingUp;
	bool pressingDown;

	Side side;
public:
	const int WIDTH = 12;
	const int HEIGHT = 64;

	Paddle();
	Paddle(const Playfield& playfield, Side side_);
	~Paddle();
	
	Side GetSide();

	void Update() override;
	void checkBounds(const Playfield& playfield);
	void pressUp(bool b);
	void pressDown(bool b);
};

