#pragma once
#include "SDL_System.h"
using namespace std;
#include <string>

class Font
{
private:
	TTF_Font* _ptr = nullptr;
	static const string FILE;
	static const int POINTS;
public:
	Font();
	~Font();

	TTF_Font* getPointer();
};

