#include "includes.hpp"
#include "player.hpp"

Player::Player(int H, int G, int L, float X) : Health(H), Gold(G), Level(L), XP(X) {  }

void Player::displayStats() 
{
    std::cout << "Health: " << Health << "\n";
    std::cout << "Gold: " << Gold << "\n";
    std::cout << "Level: " << Level << "\n";
    std::cout << "XP: " << XP << "\n";
}