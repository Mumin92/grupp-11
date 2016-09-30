#include "Font.h"

const string Font::FILE = "OpenSans-Bold.ttf";
const int Font::POINTS = 26;

Font::Font()
{
	_ptr = TTF_OpenFont(FILE.c_str(), POINTS);
	if (_ptr == nullptr)
		throw std::runtime_error(TTF_GetError());
}


Font::~Font()
{
	TTF_CloseFont(_ptr);
}

TTF_Font* Font::getPointer() {
	return _ptr;
}