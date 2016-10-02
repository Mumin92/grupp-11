#include "Ball.h"
#include "Config.h"


Ball::Ball(float x, float y) : Entity(x, y, Config::BALL_WIDTH, Config::BALL_WIDTH)
{
}


Ball::~Ball()
{
}
