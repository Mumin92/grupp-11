#pragma once
#include "SDLSystem.h"
#include <string>

namespace Config {
	const SDL_Color BG_COLOR{ 0x00, 0x00, 0x00, 0xFF };
	const SDL_Color FG_COLOR{ 0xFF, 0xFF, 0xFF, 0xFF };
	const SDL_Color PADDLE_COLOR{ 0xFF, 0x00, 0xFF, 0xFF };
	const SDL_Color BALL_COLOR{ 0xFF, 0x00, 0xFF, 0xFF };
	const std::string TITLE = "Arkanoid";
	const int WIN_WIDTH = 480;
	const int CENTER_X = WIN_WIDTH / 2;
	const int WIN_HEIGHT = 680;
	const int BRICK_WIDTH = 30;
	const int BRICK_HEIGHT = 15;
	const int BALL_WIDTH = 15;
	const int PADDLE_WIDTH = 100;
	const int COLUMNS = 11;
	const int ROWS = 5;
	const int PADDING = 10;
};