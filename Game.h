#pragma once

class Game {
private:
    int nm1;
    int nm2;
    int tries;
    bool isRunning;

public:
    Game(); // Constructor blauwdruk
    bool keepPlaying();
    void playTurn();
};
