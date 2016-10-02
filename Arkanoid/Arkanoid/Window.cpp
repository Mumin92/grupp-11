#include "Window.h"
#include "SDLSystem.h"
#include <cassert>

Window::Window(const std::string& title, int width, int height)
{
	_ptr = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
	if (!_ptr) {
		throw std::runtime_error(SDL_GetError());
	}
}

Window::~Window()
{
	SDL_DestroyWindow(_ptr);
}

SDL_Window* Window::getPointer()
{
	assert(_ptr != nullptr);
	return _ptr;
}
