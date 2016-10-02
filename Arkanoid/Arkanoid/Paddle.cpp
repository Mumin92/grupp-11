#include "Paddle.h"
#include "Config.h"


Paddle::Paddle(float x, float y) : Entity(x, y, Config::PADDLE_WIDTH, Config::BRICK_HEIGHT)
{
	_color = Config::PADDLE_COLOR;
}

void Paddle::update() 
{
	Entity::update();
	_vx *= 0.98;
}

Paddle::~Paddle()
{
}
