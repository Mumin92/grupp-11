#include <iostream>
#include "GameState.h"

int main(int argc, char* argv[]) {
	GameState game;
	while (game.Update());

	return 0;
}