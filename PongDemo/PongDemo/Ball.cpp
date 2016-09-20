#include "Ball.h"
#include "Paddle.h"



Ball::Ball()
{
}
Ball::Ball(const Playfield& playfield, GameObject::Side side)
{
	if (side == Playfield::Side::left) {
		velx = SPEED;
		rect = {0 - SIZE, playfield.HEIGHT / 2 - SIZE / 2,
				SIZE, SIZE};
	}
	else {
		rect = { playfield.WIDTH, playfield.HEIGHT / 2 - SIZE / 2,
			SIZE, SIZE };
	}
	vely = 0.0;
	posy = rect.y;
}


Ball::~Ball()
{
}

void Ball::Update() {
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
void Ball::checkBounds(const Playfield& playfield) {
	if (rect.y < playfield.MARGIN) {
		posy = playfield.MARGIN;
		vely *= -1.0;
	}
	if (rect.y > playfield.HEIGHT - playfield.MARGIN - rect.h) {
		posy = playfield.HEIGHT - playfield.MARGIN - rect.h;
		vely *= -1.0;
	}

	//remove for points
	if (rect.x > playfield.WIDTH)
		rect.x -= playfield.WIDTH;
	if (rect.x < 0)
		rect.x += playfield.WIDTH;
}