#include <iostream>
#include <stdexcept>
#include "ArkanoidGame.h"

int main(int argc, char* argv[]) {
	try {
		ArkanoidGame game;
		game.run();
	}
	catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "bad" << std::endl;
	}
	return 0;
}