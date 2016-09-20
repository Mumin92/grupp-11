#include "Paddle.h"
#include "Playfield.h"


Paddle::Paddle()
{
	side = Side::left;
	rect = { 0, 0,
		WIDTH, HEIGHT };
}
Paddle::Paddle(const Playfield& playfield, Side side_) {
	rect = { 0, (playfield.HEIGHT / 2) - (HEIGHT / 2),
		WIDTH, HEIGHT};
	
	side = side_;

	if (side == Side::left)
		rect.x = playfield.MARGIN;
	else
		rect.x = playfield.WIDTH - WIDTH - playfield.MARGIN;

	pressingUp = false;
	pressingDown = false;
}

Paddle::~Paddle()
{
}


GameObject::Side Paddle::GetSide() {
	return side;
}

void Paddle::Update() {
	if (pressingUp)
		rect.y -= SPEED;
	if (pressingDown)
		rect.y += SPEED;
}
void Paddle::checkBounds(const Playfield& playfield) {
	if (rect.y < playfield.MARGIN)
		rect.y = playfield.MARGIN;

	if (rect.y + rect.h > playfield.HEIGHT - playfield.MARGIN)
		rect.y = playfield.HEIGHT - playfield.MARGIN - rect.h;
}
void Paddle::pressUp(bool b) {
	pressingUp = b;
}
void Paddle::pressDown(bool b) {
	pressingDown = b;
}