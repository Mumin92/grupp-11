#pragma once
#include "SDl.h"
#include "Playfield.h"
#include "GameObject.h"

class Ball : public GameObject
{
	static const int SPEED = 4;
	
	int velx;
	double vely;
	double posy;
public:
	Ball();
	Ball(GameObject::Side side);
	~Ball();

	static const int SIZE = 12;

	void update() override;
	void collide(Side side, const Paddle& paddle);
	void checkBounds();
};

