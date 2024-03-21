#include "player.h"

Player::Player() : Sprite(300, 800, 300, 600) {
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
