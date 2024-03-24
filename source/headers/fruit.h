#pragma once
#include <SDL.h>
#include <vector>
#include <memory>
#include "sprite.h"

using std::vector;

class Fruit : public Sprite
{
  private:
    vector<string> const imagePaths = {
      "assets/apple.png",
      "assets/banana.png",
      "assets/orange.png",
      "assets/strawberry.png",
    };
    string selectedImagePath;
    int const static startingHeight = 200;

  public:
    Fruit(int x = 0, int y = 0);
    void fall(int speed = 1);

    std::unique_ptr<Fruit> static generateRandom(const int& windowWidth);
};
