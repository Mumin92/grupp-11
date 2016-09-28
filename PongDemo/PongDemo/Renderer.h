#pragma once
#include "SDL_System.h"
#include "Window.h"
#include "Playfield.h"

class Renderer
{
private:
	Renderer(const Renderer&) = delete; //disable copy constructor
	Renderer& operator=(Renderer&) = delete; //disable copy assignment

	SDL_Renderer* _ptr = nullptr;
	Window _window{ "Pong", Playfield::WIDTH, Playfield::HEIGHT };
public:
	Renderer();
	~Renderer();

	void setColor(const SDL_Color& c);
	void clear();
	void present();
	void fillRect(const SDL_Rect& rect);
};

