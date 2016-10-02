#pragma once
#include "Window.h"
struct SDL_Renderer;
struct SDL_Color;
struct SDL_Rect;

class Renderer
{
	Window _window;
	SDL_Renderer* _ptr;
	Renderer(Renderer&) = delete;                //disable copy constructor
	Renderer& operator=(Renderer&) = delete;     //disable copy assignment

public:
	Renderer();
	~Renderer();
	void clear();
	void setColor(const SDL_Color& c);
	void drawRect(const SDL_Rect& r);
	void present();
};

