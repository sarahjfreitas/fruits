#pragma once
#include "sprite.h"

class Hp : public Sprite
{
private:
  string const imagePath = "assets/hp.png";
  const int size = 64;

public:
  Hp(int lifeNumber);
};
