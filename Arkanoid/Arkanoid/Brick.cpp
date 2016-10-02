#include "Brick.h"
#include "Config.h"

Brick::Brick(float x, float y) : Entity(x, y, Config::BRICK_WIDTH, Config::BRICK_HEIGHT)
{
}


Brick::~Brick()
{
}
