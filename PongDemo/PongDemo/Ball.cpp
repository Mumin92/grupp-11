#include "Ball.h"
#include "Paddle.h"



Ball::Ball()
{
}
Ball::Ball(GameObject::Side side)
{
	if (side == GameObject::Side::left) {
		velx = SPEED;
		rect = {0 - SIZE, Playfield::HEIGHT / 2 - SIZE / 2,
				SIZE, SIZE};
	}
	else {
		rect = { Playfield::WIDTH, Playfield::HEIGHT / 2 - SIZE / 2,
			SIZE, SIZE };
	}
	vely = 0.0;
	posy = rect.y;
}


Ball::~Ball()
{
}

void Ball::update() {
	rect.x += velx;

	posy += vely;
	rect.y = (int)posy;
}
void Ball::collide(Side side_, const Paddle& paddle) {
	if (side_ == Side::left)
		velx = SPEED;
	else
		velx = -SPEED;

	int bally = rect.y + rect.h / 2;
	SDL_Rect padrect = paddle.GetRect();
	int pady = padrect.y + padrect.h / 2;

	vely = (double)(bally - pady) / (padrect.h / 4.0);
}
void Ball::checkBounds() {
	if (rect.y < Playfield::MARGIN) {
		posy = Playfield::MARGIN;
		vely *= -1.0;
	}
	if (rect.y > Playfield::HEIGHT - Playfield::MARGIN - rect.h) {
		posy = Playfield::HEIGHT - Playfield::MARGIN - rect.h;
		vely *= -1.0;
	}

	//remove for points
	if (rect.x > Playfield::WIDTH)
		rect.x -= Playfield::WIDTH;
	if (rect.x < 0)
		rect.x += Playfield::WIDTH;
}