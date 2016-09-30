#pragma once
#include "SDL_System.h"
#include "Renderer.h"
#include "Ball.h"
#include "Paddle.h"
#include "Playfield.h"
#include "FPS_Helper.h"
#include "Font.h"
#include "Score.h"

class PongGame
{
	SDL_System _sdl{SDL_INIT_VIDEO};
	Renderer _renderer;
	Font _font;
	FPS_Helper fps;

	Playfield _playfield;
	Paddle _leftPaddle = Paddle(GameObject::Side::left);
	Paddle _rightPaddle = Paddle(GameObject::Side::right);
	Ball _ball;
	Score _score;

	bool _isRunning;

	void readInput();
	void onKeyUp(SDL_Keycode& key);
	void onKeyDown(SDL_Keycode& key);
	void render();
	void updatePaddles();
	void checkBoundaries();
	void checkCollision();
	void update();
	void serveBall(GameObject::Side side);
	void checkForGoal();
public:
	PongGame();
	~PongGame();

	void run();
};

