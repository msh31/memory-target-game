#include "includes.hpp"
#include "game.hpp"
#include "player.hpp"

Player _player;

Game::Game()
{
}

void Game::Play()
{
    bool finished = false;

    std::cout << "Your stats:" << "\n";
    _player.displayStats();

    while (!finished)
    {
        std::cout << "\n> "; // prompt
        std::string input;
        std::getline(std::cin, input);

        if (input == "quit")
        {
            finished = true;
        }
        else if (input == "stats")
        {
            _player.displayStats();
        }
        else if (input == "damage")
        {
            _player.takeDamage(97);
        }
        else if (input == "heal")
        {
            _player.giveHealth(20); // hardcodeed atm
        }
        else if (input == "gold")
        {
            _player.giveGold(12);
        }
        else if (input == "xp")
        {
            _player.addXP(983.98);
        }

        if (!_player.isPlayerAlive())
        {
            std::cout << "\nYou are dead!" << "\n\n";
            finished = true;
        }
    }
}

bool Game::ProcessCommand()
{
    bool wantToQuit = false;

    return wantToQuit;
}