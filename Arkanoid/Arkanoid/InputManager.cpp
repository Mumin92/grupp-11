#include "InputManager.h"
#include <stdexcept>
#include "SDLSystem.h"


InputManager::InputManager() : _keyStates(SDL_GetKeyboardState(nullptr)), _clickedCloseButton(false)
{
	if (!_keyStates) {
		throw std::runtime_error(SDL_GetError());
	}
}


InputManager::~InputManager()
{
}

void InputManager::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			_clickedCloseButton = true;
		}
	}
}

bool InputManager::isKeyDown(const SDL_Scancode key)
{
	return (_keyStates[key] == 1);
}

bool InputManager::isQuitRequested()
{
	return _clickedCloseButton || isKeyDown(SDL_SCANCODE_ESCAPE);
}

void InputManager::onKeyDown(const SDL_KeyboardEvent & e)
{
}

void InputManager::onKeyUp(const SDL_KeyboardEvent & e)
{
}

void InputManager::onMouseMove(SDL_MouseMotionEvent & e)
{
}

void InputManager::onMouseButtonUp(SDL_MouseButtonEvent & e)
{
}

void InputManager::onMouseButtonDown(SDL_MouseButtonEvent & e)
{
}
