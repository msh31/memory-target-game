#ifndef PLAYER_H
#define PLAYER_H

#include "includes.hpp"

class Player {
  private:
    std::vector<int> xpThresholds;
    void initializeXPThresholds(int baseXP, int growthFactor);

  public:
    int Health;
    int Gold;
    int Level;
    int MaxLevel;
    double XP;
    int XPGrowthRate;

    Player(int Health = 100, int Gold = 5, int Level = 1, int MaxLevel = 100, double XP = 0.0, int XPGrowthRate = 1);

    void displayStats();
    void takeDamage(int amount);
    void giveGold(int amount);
    void addXP(double amount);
    void OnLevelUp();
};


#endif