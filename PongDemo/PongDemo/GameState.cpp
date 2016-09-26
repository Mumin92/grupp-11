#include "GameState.h"



GameState::GameState()
{
	if (setup())
		_isRunning = true;
	else {
		_isRunning = false;
		onError(SDL_GetError());
	}
}


GameState::~GameState()
{
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

bool GameState::setup() {
	bool isGood = false;

	if (SDL_Init(SDL_INIT_VIDEO) == 0) { //returns negative for errors, call SDL_GetError()
		_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			_playfield.WIDTH, _playfield.HEIGHT, SDL_WINDOW_OPENGL);
		if (_window != nullptr) {
			_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
			isGood = (_renderer != nullptr);
		}
	}
	return isGood;
}
void GameState::render() {
	SDL_SetRenderDrawColor(_renderer, 64, 64, 64, 0);
	SDL_RenderClear(_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(_renderer, &_leftPaddle.GetRect());
	SDL_RenderFillRect(_renderer, &_rightPaddle.GetRect());
	SDL_RenderFillRect(_renderer, &_ball.GetRect());

	SDL_RenderPresent(_renderer);
}
void GameState::onError(const std::string& errorMessage) {
	std::cerr << errorMessage << std::endl;
}

bool GameState::Update() {
	readInput();
	_ball.Update();
	updatePaddles();
	checkCollision();
	checkBoundaries();
	render();

	fps.Delay(60);

	return _isRunning;
}

void GameState::readInput() {
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
void GameState::onKeyUp(SDL_Keycode& key) {
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
void GameState::onKeyDown(SDL_Keycode& key) {
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

void GameState::updatePaddles() {
	_leftPaddle.Update();
	_rightPaddle.Update();
}
void GameState::checkBoundaries() {
	_leftPaddle.checkBounds(_playfield);
	_rightPaddle.checkBounds(_playfield);
	_ball.checkBounds(_playfield);
}
void GameState::checkCollision() {
	SDL_Rect ballrect = _ball.GetRect();
	SDL_Rect result;

	if (SDL_IntersectRect(&ballrect, &_leftPaddle.GetRect(), &result))
		_ball.collide(GameObject::Side::left, _leftPaddle);

	if (SDL_IntersectRect(&ballrect, &_rightPaddle.GetRect(), &result))
		_ball.collide(GameObject::Side::right, _rightPaddle);
}