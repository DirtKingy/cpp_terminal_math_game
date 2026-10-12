// learning_cpp_the_console_way.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "learning_cpp_the_console_way.h"
#include "Game.h"

int main() {
	Game Game;

	while(Game.keepPlaying()) {
		Game.playTurn();
	}

	return 0;
}
