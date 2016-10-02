#include "ArkanoidGame.h"
#include "Config.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"

ArkanoidGame::ArkanoidGame() : _isQuitRequested{false}, _paddle{ nullptr }, _ball{ nullptr }
{
	createEntities();
}

ArkanoidGame::~ArkanoidGame()
{
	try {
		destroyEntities();
	}catch (...) {}
}

void ArkanoidGame::createEntities()
{
	destroyEntities();
	float halfPaddle = (Config::PADDLE_WIDTH / 2);
	_paddle = new Paddle(Config::CENTER_X - halfPaddle, Config::WIN_HEIGHT-30);
	_ball = new Ball((_paddle->_x + halfPaddle)-(Config::BALL_WIDTH/2), _paddle->_y- _paddle->_height);
	
	for (int i = 1; i < Config::COLUMNS; i++) {
		int x = i*(Config::BRICK_WIDTH + Config::PADDING);
		for (int j = 1; j < Config::ROWS; j++) {
			int y = j*(Config::BRICK_HEIGHT + Config::PADDING);
			Brick* b = new Brick(static_cast<float> (x),static_cast<float> (y));
			_entities.push_back(b);
		}
	}

	_entities.push_back(_paddle);
	_entities.push_back(_ball);
}

void ArkanoidGame::destroyEntities()
{
	_paddle = nullptr;
	_ball = nullptr;
	for (Entity* e : _entities) {
		delete e;
	}
	_entities.clear();
}

void ArkanoidGame::run()
{
	while (!_isQuitRequested) {
		readInput();
		update();
		render();
	}
}

void ArkanoidGame::update()
{
	for (Entity* e : _entities) {
		e->update();
	}
}

void ArkanoidGame::render()
{
	_r.setColor(Config::BG_COLOR);
	_r.clear();
	SDL_Rect rect;
	for (Entity* e : _entities) {
		_r.setColor(e->_color);
		e->populateRect(rect);
		_r.drawRect(rect);
	}
	_r.present();
}

void ArkanoidGame::readInput() {
	_input.update();
	if (_input.isKeyDown(SDL_SCANCODE_ESCAPE)) {
		_isQuitRequested = true;
	}
	if (_input.isKeyDown(SDL_SCANCODE_LEFT)) {
		_paddle->_vx = -1;
	}
	else if (_input.isKeyDown(SDL_SCANCODE_RIGHT)) {
		_paddle->_vx = +1;
	}
	else {
		_paddle->_vx = 0;
	}
}




