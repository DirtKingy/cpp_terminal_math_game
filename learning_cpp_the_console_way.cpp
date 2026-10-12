// learning_cpp_the_console_way.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

int main() {
	Game myGame;

	while(myGame.keepPlaying()) {
		myGame.playTurn();
	}

	return 0;
}
