#include "hp.h"
#include "sprite.h"

Hp::Hp(int lifeNumber) : Sprite(64 * lifeNumber, 64, 64, 64) {
  setImage(imagePath);
}