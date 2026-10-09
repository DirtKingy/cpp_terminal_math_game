// learning_cpp_the_console_way.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <limits>
#include <random>


int ask(int nm1, int nm2, int tries);

bool whileTrue = true;

int main()
{
    int x;
    int tries = 0;

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(1, 100);

    int nm1 = distribution(generator);
    int nm2 = distribution(generator);


    while (whileTrue) {
        x = ask(nm1, nm2, tries);

        if (!whileTrue) {
            break;
        }

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "That is not a number, try again\n\n";
        }
        else {
            if (x == nm1 + nm2 && tries == 3) {
                std:: cout << "Your guess of " + std::to_string(x) + " is correct!\n";
                whileTrue = false;
            }
            else {
                std::cout << "Your guess is incorrect!\n\n";
                tries += 1;
            }
        }
    }
    return 0;
}

int ask(int nm1, int nm2, int tries) {
    if (tries <= 2)
    {
        int input;
        std::cout << "Whats " + std::to_string(nm1) + " + " + std::to_string(nm2) + "?\n";
        std::cin >> input;
        return input;
    }
    else {
        std::cout << "Game over\n";
        whileTrue = false;
        return -1;
    }
}

