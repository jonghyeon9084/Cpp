#ifndef GAMBLINGGAME_H
#define GAMBLINGGAME_H

#include "Player.h"

class GamblingGame {
private:
    Player players[2];

public:
    GamblingGame(string name1, string name2);
    void startGame();
};

#endif
