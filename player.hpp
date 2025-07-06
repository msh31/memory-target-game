#ifndef PLAYER_H
#define PLAYER_H

#include "includes.hpp"

class Player {
  public:
    int Health;
    int Gold;
    int Level;
    float XP;

    Player(int Health = 100, int Gold = 5, int Level = 1, float XP = 10.0f);

    void displayStats();
    void takeDamage(int amount);
    void giveGold(int amount);
    void addXP(float amount);
};


#endif