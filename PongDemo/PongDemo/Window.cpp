#include "Window.h"

Window::Window(const std::string& title, int width = 640, int height = 360)
{
	_ptr = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
	if (_ptr == nullptr)
		throw std::runtime_error(SDL_GetError());
}


Window::~Window()
{
	SDL_DestroyWindow(_ptr);
}

SDL_Window* Window::getPointer() {
	return _ptr;
}