#include "PongGame.h"



PongGame::PongGame(){
	
}


PongGame::~PongGame()
{

}

void PongGame::run(){
	while (_isRunning)
		update();
}

void PongGame::render() {
	_renderer.setColor(SDL_Color{64,64,64,0});
	_renderer.clear();

	_renderer.setColor(SDL_Color{ 255,255,255,0 });
	_renderer.fillRect(_leftPaddle.GetRect());
	_renderer.fillRect(_rightPaddle.GetRect());
	_renderer.fillRect(_ball.GetRect());

	_renderer.present();
}
bool PongGame::update() {
	readInput();
	_ball.update();
	updatePaddles();
	checkCollision();
	checkBoundaries();
	render();

	fps.Delay(60);

	return _isRunning;
}

void PongGame::readInput() {
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
void PongGame::onKeyUp(SDL_Keycode& key) {
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
void PongGame::onKeyDown(SDL_Keycode& key) {
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

void PongGame::updatePaddles() {
	_leftPaddle.update();
	_rightPaddle.update();
}
void PongGame::checkBoundaries() {
	_leftPaddle.checkBounds();
	_rightPaddle.checkBounds();
	_ball.checkBounds();
}
void PongGame::checkCollision() {
	SDL_Rect ballrect = _ball.GetRect();
	SDL_Rect result;

	if (SDL_IntersectRect(&ballrect, &_leftPaddle.GetRect(), &result))
		_ball.collide(GameObject::Side::left, _leftPaddle);

	if (SDL_IntersectRect(&ballrect, &_rightPaddle.GetRect(), &result))
		_ball.collide(GameObject::Side::right, _rightPaddle);
}