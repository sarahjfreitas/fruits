#pragma once
#include "sprite.h"

class Player : public Sprite
{
  private:
    string const imagePath = "../assets/player.png";

  public:
    Player();
    void walkRight();
    void walkLeft();
};
