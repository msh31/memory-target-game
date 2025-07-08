#ifndef GAME_H
#define GAME_H

#include "includes.hpp"

class Game {
  private:
    bool ProcessCommand();

  public:
    Game();

    void Play();
};


#endif