#pragma once
#include "SDl.h"
#include "Playfield.h"
#include "GameObject.h"

class Ball : public GameObject
{
	const int SPEED = 4;
	const int SIZE = 12;
	int velx;
	double vely;
	double posy;
public:
	Ball();
	Ball(const Playfield& playfield, GameObject::Side side);
	~Ball();

	void Update() override;
	void collide(Side side_, const Paddle& paddle);
	void checkBounds(const Playfield& playfield);
};

