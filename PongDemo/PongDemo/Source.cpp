#include "SDL.h"
#include <iostream>
#include <string>

#include "Ball.h"
#include "Paddle.h"
#include "Playfield.h"
using namespace std;

SDL_Window* _window = nullptr;
SDL_Renderer* _renderer = nullptr;

bool _isRunning = true;

Playfield playfield;
Paddle _leftPaddle = Paddle(playfield, GameObject::Side::left);
Paddle _rightPaddle = Paddle(playfield, GameObject::Side::right);
Ball _ball = Ball(playfield, GameObject::Side::left);

/*
Objects:
	scoreboard
		x/y
		value
	behaviors
		dont let the paddles leave the stage
		ball
			bounces on y axis
			bounces on paddle
			scores on x axis

*/

void onError(const string& errorMessage) {
	std::cerr << errorMessage << std::endl;
}

bool setup() {
	bool isGood = false;

	if (SDL_Init(SDL_INIT_VIDEO) == 0) { //returns negative for errors, call SDL_GetError()
		_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			playfield.WIDTH, playfield.HEIGHT, SDL_WINDOW_OPENGL);
		if (_window != nullptr) {
			_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
			isGood = (_renderer != nullptr);
		}
	}
	return isGood;
}

void teardown() {
	if (_renderer != nullptr) {
		SDL_DestroyRenderer(_renderer);
		_renderer = nullptr;
	}
	if (_window != nullptr) {
		SDL_DestroyWindow(_window);
		_window = nullptr;
	}
	SDL_Quit();
}

void onKeyUp(SDL_Keycode& key) {
	switch (key) {
	case SDLK_ESCAPE:
		_isRunning = false;
		break;
	case SDLK_w:
		_leftPaddle.pressUp(false);
		break;
	case SDLK_s:
		_leftPaddle.pressDown(false);
		break;
	case SDLK_UP:
		_rightPaddle.pressUp(false);
		break;
	case SDLK_DOWN:
		_rightPaddle.pressDown(false);
		break;
	default:
		break;
	}
}

void onKeyDown(SDL_Keycode& key) {
	switch (key) {
	case SDLK_w:
		_leftPaddle.pressUp(true);
		break;
	case SDLK_s:
		_leftPaddle.pressDown(true);
		break;
	case SDLK_UP:
		_rightPaddle.pressUp(true);
		break;
	case SDLK_DOWN:
		_rightPaddle.pressDown(true);
		break;
	default:
		break;
	}
}

void readInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			_isRunning = false;
		}
		else if (event.type == SDL_KEYDOWN) {
			onKeyDown(event.key.keysym.sym);
		}
		else if (event.type == SDL_KEYUP) {
			onKeyUp(event.key.keysym.sym);
		}
	}
}

int test = 0;
void render() {
	SDL_SetRenderDrawColor(_renderer, 64, 64, 64, 0);
	SDL_RenderClear(_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(_renderer, &_leftPaddle.GetRect());
	SDL_RenderFillRect(_renderer, &_rightPaddle.GetRect());
	SDL_RenderFillRect(_renderer, &_ball.GetRect());
	test++;

	SDL_RenderPresent(_renderer);
}

Uint32 _lastTick = 0;
void Delay(int fps) {
	int target = 1000 / fps;

	Uint32 currentTick = SDL_GetTicks();
	int wait = target - (currentTick - _lastTick);

	if (wait > 0)
		SDL_Delay(wait);

	_lastTick = currentTick;
}

void updatePaddles() {
	_leftPaddle.Update();
	_rightPaddle.Update();
}
void checkBoundaries() {
	_leftPaddle.checkBounds(playfield);
	_rightPaddle.checkBounds(playfield);
	_ball.checkBounds(playfield);
}
void checkCollision() {
	SDL_Rect ballrect = _ball.GetRect();
	SDL_Rect result;

	if (SDL_IntersectRect(&ballrect, &_leftPaddle.GetRect(), &result))
		_ball.collide(GameObject::Side::left, _leftPaddle);

	if (SDL_IntersectRect(&ballrect, &_rightPaddle.GetRect(), &result))
		_ball.collide(GameObject::Side::right, _rightPaddle);
}

int main(int argc, char* argv[]) {
	if (setup())
		while (_isRunning) {
			readInput();
			_ball.Update();
			updatePaddles();
			checkCollision();
			checkBoundaries();
			render();

			Delay(60);
		}
	else {
		onError(SDL_GetError());
	}
		

	teardown();
	return 0;
}