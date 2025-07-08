#include "includes.hpp"
#include "player.hpp"

void Player::initializeXPThresholds(int baseXP, int growthFactor) {
    xpThresholds.clear();
    int cumulativeXP = 0;
    xpThresholds.push_back(0); 

    int currentGrowth = growthFactor;

    for (int level = 1; level <= MaxLevel; ++level) {
        if (level % 10 == 0) {
            currentGrowth *= 2; // double the growth factor every 10 levels
        }

        int required = baseXP + (level * level * currentGrowth);
        cumulativeXP += required;
        xpThresholds.push_back(cumulativeXP);
    }
}

Player::Player(int H, int G, int L, int ML, double X, int XG) : Health(H), Gold(G), Level(L), MaxLevel(ML), XP(X), XPGrowthRate(XG) { initializeXPThresholds(100, XPGrowthRate);  }

void Player::displayStats() 
{
    std::cout << "Health: " << Health << "\n";
    std::cout << "Gold: " << Gold << "\n";
    std::cout << "Level: " << Level << "\n";
    std::cout << "XP: " << XP << "\n";
}

void Player::takeDamage(int amount) 
{
    if(amount < 0) { std::cout << "\nnegative damage value!" << "\n\n"; return; }

    Health -= amount;

    std::cout << "\nYou took " << std::to_string(amount) << " damage!" << "\n\n";

    if (Health <= 0) 
    {
        Health = 0;
        std::cout << "\nYou died!" << "\n\n";
    }
}

void Player::giveHealth(int amount) 
{
    if(amount > 100) { std::cout << "\n value exceeds max health value!" << "\n\n"; return; }
    if(Health >= 100) { std::cout << "\n You are max health!"; Health = 100; return; }

    Health += amount;

    std::cout << "\nHealed! new health: " << std::to_string(Health) << "\n\n";
}

void Player::giveGold(int amount) 
{
    if(amount >= INT32_MAX) { std::cout << "\nthis value exists the max possible value!" << "\n\n"; return; }

    if (amount < 0 && Gold + amount < 0) { Gold = 0; return; }

    Gold += amount;

    std::cout << "\nYou received " << std::to_string(amount) << " gold!" << "\n\n";
}

void Player::addXP(double amount) 
{
    if (Level >= MaxLevel) { return; }

    XP += amount;

    std::cout << "\nYou received: " << amount << " XP!" << "\n\n";

    while (Level + 1 < xpThresholds.size() && XP >= xpThresholds[Level + 1]) 
    {
        ++Level;
        OnLevelUp();
    }
}


void Player::OnLevelUp()
{
    std::cout << "\nLevel up! You reached level: " << Level << "!" << "\n\n";
}

bool Player::isPlayerAlive()
{
    return Health > 0;
}