#include "includes.hpp"

#include "player.hpp"

int main()
{
    Player _player;
    _player.displayStats();
    _player.takeDamage(10);
    _player.displayStats();
    _player.giveGold(10);
    _player.displayStats();
    _player.giveGold(-10);
    _player.displayStats();
    _player.giveGold(-10);
    _player.displayStats();
    _player.addXP(70.9);
    _player.displayStats();
    _player.addXP(109.9);
    _player.displayStats();
    _player.addXP(290.9);
    _player.displayStats();

    return 0;
}