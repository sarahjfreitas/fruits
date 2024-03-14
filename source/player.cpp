#include "player.h"

Player::Player() : Sprite(100, 360) {
  setImage(imagePath);
}

void Player::walkRight()
{
  move(10, 0);
}

void Player::walkLeft()
{
  move(-10,0);
}
