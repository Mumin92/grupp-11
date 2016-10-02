#pragma once
#include <vector>
#include "SDLSystem.h"
#include "Renderer.h"
#include "InputManager.h"
class Entity;
class Paddle;
class Ball;
class Brick;

class ArkanoidGame
{
	//collisiondetection
	//checkboundaries	
	//_inputManager
	//launch();
	//getRandomNumber

	void readInput();
	void update();
	void render();
	void createEntities();
	void destroyEntities();

	SDLSystem _sdl;
	Renderer _r;
	InputManager _input;
	Paddle* _paddle;
	Ball* _ball;
	std::vector<Entity*> _entities;

	bool _isQuitRequested;

public:
	ArkanoidGame();
	~ArkanoidGame();
	void run();
};

