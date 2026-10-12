#include "Game.h"
#include <iostream>
#include <string>
#include <limits>
#include <random>

class Game {
private:
    int nm1;
    int nm2;
    int tries;
    bool isRunning;

public:
    Game() {
        tries = 0;
        isRunning = true;

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(1, 100);

        nm1 = distribution(generator);
        nm2 = distribution(generator);
        
        bool keepPlaying() {
            return isRunning;
        }

        void playTurn() {
            if (tries > 2) {
                std::cout << "Game over\n";
                isRunning = false;
                return;
            }

            std::cout << "Whats " + std::to_string(nm1) + " + " + std::to_string(nm2) + "?\n";
            int guess;
            std::cin >> guess;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
                std::cout << "That is not a number, try again\n\n"
                return;
            }

            if (guess == nm1 + nm2) {
                std::cout << "Your guess of " + std::to_string(guess) + " is correct\n";
                isRunning = false;
            }
            else {
                std::cout << "Your guess is incorrect\n\n";
                tries += 1;
            }
        }
    }
};