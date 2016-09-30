#pragma once
#include "SDL_System.h"
#include "Renderer.h"
#include <iostream>
#include <string>
#include "Ball.h"
#include "Paddle.h"
#include "Playfield.h"
#include "FPS_Helper.h"

#include "Font.h"
#include "Text.h"

class PongGame
{
	SDL_System _sdl{SDL_INIT_VIDEO};
	Renderer _renderer{};
	Font _font = Font();
	FPS_Helper fps;

	Playfield _playfield;
	Paddle _leftPaddle = Paddle(GameObject::Side::left);
	Paddle _rightPaddle = Paddle(GameObject::Side::right);
	Ball _ball;
	Text _score = Text();
	int leftScore = 0;
	int rightScore = 0;

	bool _isRunning;

	void readInput();
	void onKeyUp(SDL_Keycode& key);
	void onKeyDown(SDL_Keycode& key);
	void render();
	void updatePaddles();
	void checkBoundaries();
	void checkCollision();
	bool update();
	void serveBall(GameObject::Side side);
	void checkForGoal();
public:
	PongGame();
	~PongGame();

	void run();
};

