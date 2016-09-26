#pragma once
#include "SDL.h"
#include "Ball.h"
#include "Paddle.h"
#include "Playfield.h"
#include <string>
#include "FPS_Helper.h"
#include <iostream>
class GameState
{
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
	FPS_Helper fps;

	Playfield _playfield;
	Paddle _leftPaddle = Paddle(_playfield, GameObject::Side::left);
	Paddle _rightPaddle = Paddle(_playfield, GameObject::Side::right);
	Ball _ball = Ball(_playfield, GameObject::Side::left);

	bool _isRunning;

	bool setup();
	void readInput();
	void onKeyUp(SDL_Keycode& key);
	void onKeyDown(SDL_Keycode& key);
	void onError(const std::string& errorMessage);
	void render();
	void updatePaddles();
	void checkBoundaries();
	void checkCollision();
public:
	GameState();
	~GameState();

	bool Update(); //returns false if application is about to exit
};

