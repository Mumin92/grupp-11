#include <string>
#pragma once
struct SDL_Window;


class Window
{
	SDL_Window* _ptr;
	Window(const Window&) = delete; //disable copy constructor
	Window& operator=(Window&) = delete; //disable copy assignment
public:
	Window(const std::string& title, int width = 1280, int height = 720);
	~Window();
	SDL_Window* getPointer();
};

