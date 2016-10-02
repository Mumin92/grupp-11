#include "Entity.h"
#include "Config.h"


Entity::Entity(float x, float y, int width, int height) : _x{ x }, _y{ y }, _vx{ 0.0f }, _vy{ 0.0f },
                                                          _width{ width }, _height{ height }, _color(Config::FG_COLOR)
{
}

void Entity::update()
{
	_x += _vx;
	_y += _vy;
}

void Entity::populateRect(SDL_Rect & r)
{
	r.x = static_cast<int>(_x);
	r.y = static_cast<int>(_y);
	r.w = static_cast<int>(_width);
	r.h = static_cast<int>(_height);
}

Entity::~Entity()
{
}
