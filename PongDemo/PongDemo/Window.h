#pragma once
#include "SDL_System.h"
#include <iostream>
class Window
{
private:
	SDL_Window* _ptr = nullptr;
	Window(const Window&) = delete; //disable copy constructor
	Window& operator=(Window&) = delete; //disable copy assignment
public:
	Window(const std::string& title, int width, int height);
	~Window();
	SDL_Window* getPointer();
};

