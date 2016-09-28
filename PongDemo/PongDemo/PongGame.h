#pragma once
#include "SDL.h"
#include "Ball.h"
#include "Paddle.h"
#include "Playfield.h"
#include <string>
#include "FPS_Helper.h"
#include "SDL_System.h"
#include "Renderer.h"
#include <iostream>
class PongGame
{
	SDL_System _sdl{SDL_INIT_VIDEO};
	Renderer _renderer{};
	FPS_Helper fps;

	Playfield _playfield;
	Paddle _leftPaddle = Paddle(GameObject::Side::left);
	Paddle _rightPaddle = Paddle(GameObject::Side::right);
	Ball _ball = Ball(GameObject::Side::left);

	bool _isRunning;

	void readInput();
	void onKeyUp(SDL_Keycode& key);
	void onKeyDown(SDL_Keycode& key);
	void onError(const std::string& errorMessage);
	void render();
	void updatePaddles();
	void checkBoundaries();
	void checkCollision();
	bool update();
public:
	PongGame();
	~PongGame();

	void run();
};

