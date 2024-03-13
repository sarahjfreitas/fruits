#pragma once
#include <SDL.h>
#include <vector>
#include "sprite.h"

using std::vector;

class Fruit : public Sprite
{
  private:
    vector<string> const imagePaths = {
      "../assets/banana.jpeg",
      "../assets/orange.jpg"
    };

  public:
    Fruit(int x = 0, int y = 0);
    void fall();
};
