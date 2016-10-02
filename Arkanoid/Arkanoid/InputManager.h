#pragma once
#include "SDLSystem.h"

class InputManager
{
	InputManager(const InputManager&) = delete;
	InputManager& operator=(InputManager&) = delete;

	void onKeyDown(const SDL_KeyboardEvent& e);
	void onKeyUp(const SDL_KeyboardEvent& e);
	void onMouseMove(SDL_MouseMotionEvent& e);
	void onMouseButtonUp(SDL_MouseButtonEvent& e);
	void onMouseButtonDown(SDL_MouseButtonEvent& e);

	const Uint8* _keyStates;

public:
	InputManager();
	~InputManager();

	void update();
	bool isKeyDown(const SDL_Scancode key);
};

