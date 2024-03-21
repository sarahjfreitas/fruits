#pragma once
#include "sprite.h"

class Background : public Sprite
{
private:
  string const imagePath = "assets/background.png";

public:
  Background();
  void draw(SDL_Renderer* renderer) const;
};
