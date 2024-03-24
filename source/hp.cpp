#include "hp.h"
#include "sprite.h"

Hp::Hp(int lifeNumber) : Sprite(size * lifeNumber, size, size, size) {
  setImage(imagePath);
}