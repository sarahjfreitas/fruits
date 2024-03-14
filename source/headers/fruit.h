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
    string selectedImagePath;

  public:
    Fruit(int x = 0, int y = 0);
    Fruit& operator=(const Fruit& other);
    void fall();

    static Fruit generateRandom(int windowWidth);
};
